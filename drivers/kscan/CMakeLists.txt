# Copyright (c) 2020-2023 The ZMK Contributors
# SPDX-License-Identifier: MIT

zephyr_library_amend()

zephyr_library_sources_ifdef(CONFIG_ZMK_KSCAN_BLACKOUT_DRIVER kscan_blackout.c)
