/*
 * Copyright (c) 2016 Intel Corporation
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file Sample app to demonstrate PWM.
 */

#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define DELAY 30

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));
int step = 5;

static const uint32_t start = 0;
static const uint32_t period = pwm_led0.period;

int main(void) {
  int i;

  while (1) {
    // pwm_set_pulse_dt(&pwm_led0, 0);
    // k_sleep(K_MSEC(DELAY));
    for (i = start; i < period; i += step) {
      pwm_set_pulse_dt(&pwm_led0, i);
      // k_busy_wait(30000);
      k_sleep(K_MSEC(DELAY));
    }

    for (i = period; i > start; i -= step) {
      pwm_set_pulse_dt(&pwm_led0, i);
      // k_busy_wait(30000);
      k_sleep(K_MSEC(DELAY));
    }
  }

  return 0;
}
