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

#include "rtcm3/sta_decode.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "rtcm3/bits.h"
#include "rtcm3/decode_macros.h"

rtcm3_rc sta_decode_fwver(const uint8_t buff[], char *fw_ver, uint8_t len) {
  assert(fw_ver);
  uint8_t fw_ver_strlen = 0;
  uint16_t bit = 0;
  uint16_t msg_num = rtcm_getbitu(buff, bit, 12);
  bit += 12;
  uint16_t subtype_id = rtcm_getbitu(buff, bit, 8);
  bit += 8;
  /* this should never be called on anything other than msg 999:25 */
  (void) msg_num;
  (void) subtype_id;
  assert(msg_num == 999 && subtype_id == 25);
  GET_STR_LEN(buff, bit, fw_ver_strlen);
  GET_STR(buff, bit, len, fw_ver);
  fw_ver[fw_ver_strlen] = '\0';
  return RC_OK;
}

rtcm3_rc sta_decode_rfstatus(const uint8_t buff[],
                             sta_rf_status *rf_status,
                             uint16_t len) {
  assert(rf_status);
  uint16_t bit = 0;
  rf_status->status_mask = 0;
  rf_status->msg_num = rtcm_getbitu(buff, bit, 12);
  bit += 12;
  if (bit + 8 >= len) return RC_INVALID_MESSAGE;
  rf_status->subtype_id = rtcm_getbitu(buff, bit, 8);
  assert(rf_status->msg_num == 999 && rf_status->subtype_id == 24);
  bit += 8;
  if (bit + 30 >= len) return RC_INVALID_MESSAGE;
  rf_status->gnss_epoch_time = rtcm_getbitu(buff, bit, 30);
  bit += 30;
  if (bit + 8 >= len) return RC_INVALID_MESSAGE;
  rf_status->status_mask = rtcm_getbitu(buff, bit, 8);
  if (rf_status->status_mask & RF_STATUS_CW_MASK) {
    bit += 8;
    if (bit + 4 >= len) return RC_INVALID_MESSAGE;
    rf_status->cw_detect_mask = rtcm_getbitu(buff, bit, 4);
    bit += 4;
    if (bit + 8 >= len) return RC_INVALID_MESSAGE;
    rf_status->cw_notch_mask = rtcm_getbitu(buff, bit, 8);
    bit += 8;
    if (bit + 32 >= len) return RC_INVALID_MESSAGE;
    rf_status->cw_constellation_mask = rtcm_getbitu(buff, bit, 32);
    bit += 32;
    if (bit + 8 >= len) return RC_INVALID_MESSAGE;
    rf_status->cw_candidate_mask = rtcm_getbitu(buff, bit, 8);
    bit += 8;
    if (bit + (8 * 32) >= len) return RC_INVALID_MESSAGE;
    for (int i = 0; i < 8; i++) {
      rf_status->cw_power_array[i] = rtcm_getbitu(buff, bit, 32);
      bit += 32;
    }
  }
  if (rf_status->status_mask & RF_STATUS_AGC_MASK) {
    if (bit + 4 >= len) return RC_INVALID_MESSAGE;
    rf_status->agc_mask = rtcm_getbitu(buff, bit, 4);
    bit += 4;
    if (bit >= len) return RC_INVALID_MESSAGE;
    bit += 8;
    if (bit + (4 * 12) >= len) return RC_INVALID_MESSAGE;
    for (int i = 0; i < 4; i++) {
      rf_status->agc_array[i] = rtcm_getbitu(buff, bit, 12);
      bit += 12;
    }
  }
  if (rf_status->status_mask & RF_STATUS_IFM_MASK) {
    if (bit + 6 >= len) return RC_INVALID_MESSAGE;
    rf_status->ifm_mask = rtcm_getbitu(buff, bit, 6);
    bit += 6;
    if (bit + 32 >= len) return RC_INVALID_MESSAGE;
    rf_status->ifm_constellation_mask = rtcm_getbitu(buff, bit, 32);
    bit += 32;
  }
  if (rf_status->status_mask & RF_STATUS_NOISE_FLOOR_MASK) {
    if (bit + (6 * 32) >= len) return RC_INVALID_MESSAGE;
    for (int i = 0; i < 6; i++) {
      rf_status->noise_floor_ddc_array[i] = rtcm_getbitu(buff, bit, 32);
      bit += 32;
    }
  }
  if (rf_status->status_mask & RF_STATUS_ANTENNA_SENSE_MASK) {
    if (bit + 8 >= len) return RC_INVALID_MESSAGE;
    rf_status->antenna_sense_power_switch = rtcm_getbitu(buff, bit, 1);
    bit += 1;
    rf_status->antenna_sense_op_mode = rtcm_getbitu(buff, bit, 1);
    bit += 1;
    rf_status->antenna_sense_rf_path = rtcm_getbitu(buff, bit, 3);
    bit += 3;
    rf_status->antenna_sense_status = rtcm_getbitu(buff, bit, 3);
    bit += 3;
  }
  if (bit != len) {
    return RC_INVALID_MESSAGE;
  }
  return RC_OK;
}
