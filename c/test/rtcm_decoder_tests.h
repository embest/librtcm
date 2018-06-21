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

#ifndef PIKSI_BUILDROOT_RTCM_DECODER_TESTS_H
#define PIKSI_BUILDROOT_RTCM_DECODER_TESTS_H

#include <rtcm3_messages.h>

static void test_rtcm_1001(void);
static void test_rtcm_1002(void);
static void test_rtcm_1003(void);
static void test_rtcm_1004(void);
static void test_rtcm_1005(void);
static void test_rtcm_1006(void);
static void test_rtcm_1007(void);
static void test_rtcm_1008(void);
static void test_rtcm_1010(void);
static void test_rtcm_1012(void);
static void test_rtcm_1029(void);
static void test_rtcm_1033(void);
static void test_rtcm_1230(void);
static void test_rtcm_msm4(void);
static void test_rtcm_msm5(void);
static void test_rtcm_msm7(void);
static void test_rtcm_random_bits(void);
static void test_msm_bit_utils(void);
static void test_msm_sid_conversion(void);
static void test_msm_glo_fcn(void);
static void test_logging(void);

bool msgobs_equals(const rtcm_obs_message *msg_in,
                   const rtcm_obs_message *msg_out);
bool msgobs_glo_equals(const rtcm_obs_message *msg_in,
                       const rtcm_obs_message *msg_out);
bool msg1005_equals(const rtcm_msg_1005 *lhs, const rtcm_msg_1005 *rhs);
bool msg1006_equals(const rtcm_msg_1006 *lhs, const rtcm_msg_1006 *rhs);
bool msg1007_equals(const rtcm_msg_1007 *lhs, const rtcm_msg_1007 *rhs);
bool msg1008_equals(const rtcm_msg_1008 *lhs, const rtcm_msg_1008 *rhs);
bool msg1029_equals(const rtcm_msg_1029 *lhs, const rtcm_msg_1029 *rhs);
bool msg1033_equals(const rtcm_msg_1033 *lhs, const rtcm_msg_1033 *rhs);
bool msg1230_equals(const rtcm_msg_1230 *lhs, const rtcm_msg_1230 *rhs);

/* raw received 1077 message */
static const uint8_t msm7_raw[] = {
    0x43, 0x50, 0x00, 0x6F, 0x3B, 0x96, 0x02, 0x00, 0x00, 0x42, 0x2B, 0x52,
    0xC0, 0x80, 0x00, 0x00, 0x00, 0x28, 0x20, 0x40, 0x80, 0x7F, 0xF3, 0xF7,
    0x3D, 0xEE, 0x73, 0xFF, 0xFA, 0x92, 0x7A, 0xA2, 0x2A, 0x9A, 0x9A, 0x4A,
    0x2A, 0xA2, 0x22, 0x8A, 0x68, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8E,
    0xFD, 0xA4, 0xD5, 0xB6, 0xF7, 0xE0, 0xB9, 0x33, 0x79, 0x89, 0x09, 0x3A,
    0x0E, 0x18, 0x2F, 0x7E, 0x9F, 0x83, 0x75, 0xEF, 0x27, 0xA7, 0xC1, 0x30,
    0x01, 0xA7, 0xFD, 0xEF, 0xD2, 0x00, 0x22, 0x79, 0x93, 0xF1, 0x98, 0x58,
    0x2D, 0x85, 0x66, 0x50, 0x5D, 0xCA, 0x85, 0xE1, 0x48, 0x57, 0x83, 0x0D,
    0x59, 0xE8, 0xD7, 0xC0, 0x8D, 0xC0, 0x40, 0xDC, 0xBE, 0x0D, 0xD0, 0x2E,
    0xB5, 0xB9, 0x40, 0x00, 0x04, 0x00, 0x00, 0x0D, 0xF6, 0x48, 0xE0, 0x2D,
    0x0D, 0x54, 0xC8, 0xD5, 0x9F, 0x01, 0x4F, 0x98, 0x11, 0x1B, 0x00, 0xC4,
    0xD9, 0x24, 0x91, 0x12, 0x78, 0xF1, 0x22, 0x3B, 0x12, 0x32, 0x79, 0x2D,
    0x26, 0x12, 0xEA, 0xE9, 0x24, 0x4B, 0x12, 0x53, 0xE6, 0xA9, 0x8C, 0xEA,
    0x7C, 0xA6, 0x99, 0xD9, 0x79, 0x28, 0x47, 0x96, 0x4A, 0x78, 0x6D, 0xC9,
    0x4A, 0xFE, 0x14, 0xBC, 0xB9, 0x4B, 0x7D, 0x14, 0xAC, 0x29, 0x4A, 0xDA,
    0x9B, 0x61, 0xD9, 0xB4, 0x1F, 0x1B, 0xA0, 0x11, 0xBA, 0x4B, 0x1B, 0xA6,
    0xD8, 0xA2, 0xD3, 0x8A, 0x5A, 0x60, 0xA2, 0x53, 0x0A, 0x36, 0x18, 0x9B,
    0xD8, 0x01, 0x55, 0x15, 0x81, 0x53, 0x03, 0x81, 0x53, 0x14, 0x01, 0x53,
    0x15, 0x01, 0x5C, 0xD4, 0x03, 0x62, 0xD7, 0x03, 0x63, 0x7A, 0x03, 0x65,
    0xDC, 0x03, 0x65, 0xDB, 0x03, 0x6E, 0x7E, 0x7A, 0xCC, 0x20, 0xC0, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x03, 0x80, 0xD9, 0x03, 0x81, 0x80, 0x83, 0x81,
    0x97, 0x03, 0x81, 0x93, 0x00, 0x33, 0xE2, 0x80, 0x4C, 0x86, 0x80, 0x4C,
    0x7D, 0x84, 0x88, 0xC9, 0x84, 0x89, 0x73, 0x04, 0x86, 0x86, 0x84, 0x86,
    0x90, 0x04, 0xB6, 0x99, 0x04, 0xB7, 0x41, 0x04, 0xB6, 0x6F, 0x84, 0xB6,
    0x6A, 0xFA, 0xA5, 0x5B, 0xFA, 0xA6, 0x02, 0xFA, 0xA6, 0xE6, 0x7E, 0x4B,
    0x12, 0xFE, 0x4B, 0xC0, 0x7E, 0x4C, 0xDD, 0x05, 0x2F, 0x6E, 0x85, 0x30,
    0x17, 0x85, 0x2F, 0xF3, 0x85, 0x2F, 0xF6, 0x85, 0x2E, 0x06, 0x06, 0xC7,
    0x73, 0x86, 0xC8, 0x12, 0x06, 0xCA, 0x7D, 0x86, 0xCA, 0x95, 0x86, 0xDA,
    0xD4, 0x02, 0x83, 0x71, 0x02, 0x84, 0x18, 0x82, 0x83, 0x7F, 0x82, 0x83,
    0x81, 0x02, 0x88, 0x9B, 0x3D, 0x2F, 0x4B, 0xD2, 0xF4, 0xBD, 0x2F, 0x4B,
    0xD2, 0xF4, 0xBD, 0x2F, 0x4A, 0xEE, 0x00, 0x00, 0x0F, 0x4B, 0xD2, 0xF4,
    0xBD, 0x2F, 0x43, 0x84, 0xE1, 0x3D, 0x2F, 0x4B, 0xD2, 0xF4, 0xBD, 0x2F,
    0x4B, 0xD2, 0xF4, 0xBD, 0x2F, 0x4B, 0xD2, 0xDE, 0x35, 0x2D, 0x4B, 0xD2,
    0xF4, 0xBD, 0x2F, 0x4B, 0xD2, 0xF4, 0xBD, 0x2F, 0x4B, 0xD2, 0xF4, 0xBD,
    0x2F, 0x4B, 0xD2, 0xF4, 0xBD, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09,
    0xC1, 0x7C, 0x5F, 0x28, 0x8C, 0x12, 0x98, 0x78, 0x1E, 0x0A, 0xD3, 0x1C,
    0x85, 0x00, 0x00, 0x03, 0x58, 0xB5, 0x2D, 0x4C, 0xB2, 0x38, 0x52, 0x14,
    0x89, 0xE1, 0x68, 0x5A, 0x26, 0x8D, 0x12, 0xB4, 0xAD, 0x30, 0xCD, 0x32,
    0xE0, 0xB8, 0x22, 0xC4, 0x41, 0x10, 0xE2, 0x32, 0x0C, 0x83, 0x7C, 0xF5,
    0x27, 0xC6, 0x41, 0x90, 0xA4, 0x2F, 0x8B, 0xD2, 0x40, 0x90, 0x2E, 0xCD,
    0x00, 0x69, 0xC0, 0xD3, 0x81, 0xA7, 0xE3, 0x5F, 0x86, 0xA8, 0xD8, 0x47,
    0xB0, 0x8F, 0x5F, 0xF2, 0xC0, 0x7D, 0x80, 0x62, 0x49, 0xB0, 0x00, 0x20,
    0x00, 0x6A, 0x63, 0xD4, 0xC7, 0xAA, 0x3B, 0x54, 0x0D, 0x41, 0xDA, 0x83,
    0xB5, 0x02, 0x09, 0x10, 0x92, 0x21, 0x22, 0xC4, 0x44, 0x50, 0x1B, 0x30,
    0x36, 0x60, 0x6B, 0xE0, 0xD4, 0x6E, 0x30, 0xDC, 0x61, 0xB8, 0xDF, 0x7D,
    0x36, 0xFA, 0x6E, 0x03, 0xF2, 0x29, 0xE4, 0x53, 0xC8, 0xA1, 0x91, 0x43,
    0x22, 0xA5, 0x57, 0x92, 0xAF, 0x25, 0x5C, 0x9A, 0xC4, 0x35, 0x8B, 0xED,
    0x5A, 0xDA, 0xB5, 0xB5, 0xF3, 0x6B, 0x86, 0xD7};

static const rtcm_msm_header msm7_expected_header = {
    1077,
    0,
    466544000,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    {
        1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1,
        0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {
        0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
        1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    },
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0,
     1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0,
     1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

static const rtcm_msm_sat_data msm7_expected_sat_data[] = {
    {0, 24641242.0, 379.0},
    {0, 23832036.6, -705.0},
    {0, 25268639.7, 442.0},
    {0, 20888859.3, -540.0},
    {0, 25143628.6, -706.0},
    {0, 25164122.2, 608.0},
    {0, 22018643.5, 211.0},
    {0, 20868072.9, -67.0},
    {0, 25239948.6, -368.0},
    {0, 20541053.2, 68.0},
    {0, 24419032.6, -823.0},
    {0, 23216056.8, -461.0}};

static const rtcm_msm_signal_data msm7_expected_sig_data[] = {
    {24641267.21, 129490728.84, 671.744, 0, 39.0, {31}, 1993.4},  /* 1C */
    {24641266.70, 129490728.06, 671.744, 0, 23.8, {31}, 1993.4},  /* 1W */
    {24641268.82, 100901866.04, 671.744, 0, 23.8, {31}, 1553.3},  /* 2W */
    {24641268.90, 100901866.04, 671.744, 0, 40.5, {31}, 1553.4},  /* 2S */
    {24641267.02, 96697624.36, 671.744, 0, 48.2, {31}, 1488.6},   /* 5X */
    {23832097.66, 125238523.11, 671.744, 0, 41.5, {31}, -3710.1}, /* etc */
    {23832098.27, 125238523.35, 671.744, 0, 30.0, {31}, -3710.1},
    {23832099.48, 97588460.45, 671.744, 0, 30.0, {31}, -2891.05},
    {23832099.69, 97588460.45, 671.744, 0, 43.2, {31}, -2891.0},
    {23832099.77, 93522277.02, 671.744, 0, 49.8, {31}, -2770.6},
    {25268545.27, 132787097.59, 56.320, 0, 33.2, {31}, 2325.2},
    {25268346.93, 0.00, 0.000, 0, 0.0, {9}, 0.0},
    {25268346.93, 0.00, 0.000, 0, 0.0, {9}, 0.0},
    {20888923.13, 109772033.15, 671.744, 0, 53.5, {31}, -2840.6},
    {20888923.35, 109772033.40, 671.744, 0, 45.2, {31}, -2840.6},
    {20888920.24, 85536649.43, 671.744, 0, 45.2, {31}, -2213.5},
    {20888920.33, 85536649.42, 671.744, 0, 50.8, {31}, -2213.5},
    {25143634.58, 132130679.51, 655.360, 0, 35.5, {31}, -3716.0},
    {25143633.47, 132130688.76, 278.528, 0, 20.5, {31}, -3716.0},
    {25143632.10, 102958978.25, 278.528, 0, 20.5, {31}, -2895.6},
    {25164205.86, 132238790.75, 671.744, 0, 39.5, {31}, 3197.5},
    {25164206.71, 132238791.00, 671.744, 0, 22.5, {31}, 3197.5},
    {25164205.19, 103043212.91, 671.744, 0, 22.5, {31}, 2491.5},
    {25164205.45, 103043212.92, 671.744, 0, 38.5, {31}, 2491.4},
    {22018729.63, 115709205.92, 671.744, 0, 52.2, {31}, 1109.3},
    {22018730.07, 115709206.17, 671.744, 0, 43.2, {31}, 1109.3},
    {22018727.10, 90163017.56, 671.744, 0, 43.2, {31}, 864.4},
    {22018727.37, 90163017.55, 671.744, 0, 48.8, {31}, 864.4},
    {20867974.96, 109661948.24, 671.744, 0, 52.8, {31}, -356.9},
    {20867974.45, 109661948.49, 671.744, 0, 46.0, {31}, -356.9},
    {20867970.47, 85450869.21, 671.744, 0, 46.0, {31}, -278.1},
    {25239917.32, 132636661.12, 245.760, 0, 34.8, {31}, -1938.3},
    {25239918.40, 132636661.37, 167.936, 0, 17.0, {31}, -1938.3},
    {25239913.99, 103353242.96, 167.936, 0, 17.0, {31}, -1510.2},
    {20541147.79, 107944461.53, 671.744, 0, 56.5, {31}, 359.7},
    {20541148.02, 107944461.77, 671.744, 0, 50.0, {31}, 359.7},
    {20541147.94, 84112567.57, 671.744, 0, 50.0, {31}, 280.3},
    {20541147.73, 84112567.58, 671.744, 0, 55.8, {31}, 280.3},
    {20541147.75, 80607876.72, 671.744, 0, 61.2, {31}, 268.6},
    {24419157.81, 128323534.04, 671.744, 0, 39.8, {31}, -4330.6},
    {24419157.24, 128323534.27, 671.744, 0, 25.0, {31}, -4330.6},
    {24419158.93, 99992365.08, 671.744, 0, 25.0, {31}, -3374.5},
    {24419159.01, 99992365.10, 671.744, 0, 41.0, {31}, -3374.4},
    {24419159.05, 95826021.11, 671.744, 0, 47.5, {31}, -3233.8},
    {23216103.32, 122001443.42, 671.744, 0, 47.2, {31}, -2427.6},
    {23216104.12, 122001443.67, 671.744, 0, 36.0, {31}, -2427.6},
    {23216103.17, 95066059.83, 671.744, 0, 36.0, {31}, -1891.6},
    {23216103.48, 95066059.83, 671.744, 0, 46.8, {31}, -1891.6},
    {23216101.32, 91104975.43, 671.744, 0, 52.0, {31}, -1812.8},
};

#endif /* PIKSI_BUILDROOT_RTCM_DECODER_TESTS_H */
