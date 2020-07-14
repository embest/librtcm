/*
 * Copyright (C) 2017 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rtcm3/bits.h"
#include "rtcm3/decode.h"
#include "rtcm3/encode.h"
#include "rtcm3/eph_decode.h"
#include "rtcm3/messages.h"
#include "rtcm3/msm_utils.h"
#include "rtcm3/sta_decode.h"

#define DEBUG 0
#define LIBRTCM_LOG_INTERNAL
#include "rtcm3/logging.h"

static uint8_t fw_ver_array[] = {
    0xD3, 0x00, 0x1A, 0x3E, 0x71, 0x91, 0x64, 0x74, 0xE5, 0x35, 0x34,
    0xC4, 0x94, 0x25, 0xF3, 0x92, 0xE3, 0x32, 0xE3, 0x02, 0xE3, 0x05,
    0xF5, 0x24, 0x35, 0xF4, 0x15, 0x24, 0xD0, 0x43, 0xB8, 0xC9};

/* RF status plus partial other messages; should avoid going off end of buffer
 * in logic */
static uint8_t rf_status_array[] = {
    0xD3, 0x00, 0x32, 0x3E, 0x71, 0x86, 0x91, 0x4A, 0x47, 0xC7, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4,
    0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4,
    0x00, 0x00, 0x30, 0xD4, 0x00, 0x09, 0xFB, 0xB1, 0xD3, 0x00, 0x10, 0x3E,
    0x71, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xF0, 0xFE, 0x9C, 0x87, 0xD2, 0xD3, 0x00, 0x10, 0x3E, 0x71, 0xA0,
    0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF0,
    0xFE, 0x50, 0x2A, 0x81, 0xD3, 0x00, 0x10, 0x3E, 0x71, 0xA0, 0x00, 0x00,
    0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xF0, 0xFE, 0xF5,
    0x5A, 0x55};

/* RF status plus partial other messages; should avoid going off end of buffer
 * in logic */
static uint8_t rf_status_array_only[] = {
    0xD3, 0x00, 0x32, 0x3E, 0x71, 0x86, 0x91, 0x4A, 0x47, 0xC7, 0xFC, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4,
    0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4, 0x00, 0x00, 0x30, 0xD4,
    0x00, 0x00, 0x30, 0xD4, 0x00, 0x09, 0xFB, 0xB1};

static void test_rf_status() {
  uint8_t* msg_buffer = rf_status_array;
  sta_rf_status rf_status;

  /* files include RTCMv3 Framing for now */
  uint16_t payload_len = (msg_buffer[1] & 0x3) << 8;
  payload_len |= msg_buffer[2];
  assert(payload_len > 0);
  if (DEBUG) printf("rf_status payload_len is %u\n", payload_len);
  /* this message received from device is lacking payload, ret should be
   * invalid*/
  int ret = sta_decode_rfstatus(&(msg_buffer[3]), &rf_status, payload_len);
  assert(ret == RC_INVALID_MESSAGE);
  /* TODO: add a test with a valid rfstatus message once I can make TeseoV
   * produce one */
}

static void test_rf_status_only() {
  uint8_t* msg_buffer = rf_status_array_only;
  sta_rf_status rf_status;

  /* files include RTCMv3 Framing for now */
  uint16_t payload_len = (msg_buffer[1] & 0x3) << 8;
  payload_len |= msg_buffer[2];
  assert(payload_len > 0);
  if (DEBUG) printf("rf_status payload_len is %u\n", payload_len);
  /* this message received from device is lacking payload, ret should be
   * invalid*/
  int ret = sta_decode_rfstatus(&(msg_buffer[3]), &rf_status, payload_len);
  assert(ret == RC_INVALID_MESSAGE);
  /* TODO: add a test with a valid rfstatus message once I can make TeseoV
   * produce one */
}

static void test_fw_version() {
  uint8_t* msg_buffer = fw_ver_array;
  /* files include RTCMv3 Framing for now */
  uint16_t payload_len = (msg_buffer[1] & 0x3) << 8;
  payload_len |= msg_buffer[2];
  if (DEBUG) printf("fw version payload len is %d\n", payload_len);
  char fw_ver[128];
  sta_decode_fwver(&(msg_buffer[3]), fw_ver, 128);
  if (DEBUG)
    printf("fw version strnlen is %u and string is %s\n",
           (uint32_t)strnlen(fw_ver, 128),
           fw_ver);
  assert(strnlen(fw_ver, 128) == 22);
}

int main(void) {
  test_fw_version();
  test_rf_status();
  test_rf_status_only();
}