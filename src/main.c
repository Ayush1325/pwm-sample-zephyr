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

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));
int step = 5;

int main(void) {
  int i;

  while (1) {
    for (i = 0; i < pwm_led0.period; i += step) {
      pwm_set_pulse_dt(&pwm_led0, i);
      k_sleep(K_MSEC(30));
    }

    for (i = pwm_led0.period; i > 0; i -= step) {
      pwm_set_pulse_dt(&pwm_led0, i);
      k_sleep(K_MSEC(30));
    }
  }

  return 0;
}
