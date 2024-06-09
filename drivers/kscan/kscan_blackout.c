/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT zmk_kscan_blackout

#include <zephyr/device.h>
#include <zephyr/drivers/kscan.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#define MATRIX_NODE_ID DT_DRV_INST(0)

struct kscan_blackout_config {};

struct kscan_blackout_data {
    kscan_callback_t callback;

    const struct device *dev;
};

static int kscan_blackout_enable_callback(const struct device *dev) {
    return 0;
}

static int kscan_blackout_disable_callback(const struct device *dev) {
    return 0;
}

static int kscan_blackout_configure(const struct device *dev, kscan_callback_t callback) {
    struct kscan_blackout_data *data = dev->data;

    if (!callback) {
        return -EINVAL;
    }

    data->callback = callback;

    return 0;
}

static int kscan_blackout_init(const struct device *dev) {
    struct kscan_blackout_data *data = dev->data;

    data->dev = dev;

    return 0;
}

static const struct kscan_driver_api mock_driver_api = {
    .config = kscan_blackout_configure,
    .enable_callback = kscan_blackout_enable_callback,
    .disable_callback = kscan_blackout_disable_callback,
};

static const struct kscan_blackout_config kscan_blackout_config = {};

static struct kscan_blackout_data kscan_blackout_data;

DEVICE_DT_INST_DEFINE(0, kscan_blackout_init, NULL, &kscan_blackout_data, &kscan_blackout_config,
                      POST_KERNEL, CONFIG_ZMK_KSCAN_BLACKOUT_INIT_PRIORITY, &mock_driver_api);
