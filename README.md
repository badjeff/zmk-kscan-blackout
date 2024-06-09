# ZMK kscan blackout

## What it does

Do nothing productive. Just let free up the mandatary gpio and make `zmk,matrix-transform` happy to be compiled. Designed for split pointing peripherals with [zmk-split-peripheral-input-relay](https://github.com/badjeff/zmk-split-peripheral-input-relay)

## Installation

Include this project on your ZMK's west manifest in `config/west.yml`:

```yaml
manifest:
  remotes:
    # START #####
    - name: badjeff
      url-base: https://github.com/badjeff
    # END #######
  projects:
    # START #####
    - name: zmk-kscan-blackout
      remote: badjeff
      revision: main
    # END #######
```

Update `board.dtsi`, adding minimal necessary bits:
```
/ {
	chosen {
		zmk,kscan = &kscan0;
		zmk,matrix-transform = &default_transform;
	};
	kscan0: kscan {
		compatible = "zmk,kscan-blackout";
		label = "KSCAN";
	};
	default_transform: keymap_transform_0 {
		compatible = "zmk,matrix-transform";
		columns = <0>;
		rows = <0>;
		map = <>;
	};
};
```
