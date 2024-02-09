# RGBW LED Strip Controller
![image](https://github.com/Aahan-Kar/RGBW-Controller/assets/123918359/915888b9-8e10-4b80-91a8-b97205f2fed0)

Welcome to the repository for the RGBW LED Strip Controller! This project is designed for enthusiasts and professionals looking to control non-addressable RGBW LED strips with precision and flexibility. Using a Teensy 3.2 microcontroller, this controller offers high-frequency PWM for smooth LED dimming, compatibility with both RGB and single-color strips, and both manual and software control options.

## Features

- **High-Frequency PWM**: The controller operates at a 23.4 kHz PWM frequency to minimize visible flicker, ensuring smooth light output.
- **Compatibility**: Designed for use with non-addressable RGBW LED strips, but also supports RGB and single-color (white) strips.
- **12V Input**: Supports a 12V input for LED driving and internal electronics, ensuring wide compatibility with common LED strip specifications.
- **Power Control**: Includes a power on/off switch for easy power management.
- **Manual Control**: Features four knobs for adjusting the brightness levels of the Red, Green, Blue, and White channels independently.
- **USB Connectivity**: Offers USB connectivity for software control, making it suitable for integration with computer-managed setups like 3D printers with Raspberry Pi controllers.
- **Mode Selection**: A rocker switch allows for easy toggling between manual (hardware) control and software control modes.

## Repository Contents

- `Eagle/` - Contains Eagle CAD files including both the electronic schematics and PCB layout designs in a single directory, as preferred by Eagle CAD.
- `Gerber/` - Gerber files ready for PCB fabrication.
- `Code/` - Source code for the Teensy 3.2 microcontroller, including the PWM control and USB communication logic.
- `3DCAD/` - 3D CAD files for the controller's enclosure, suitable for 3D printing.

## Getting Started

### Hardware Setup

1. **Power Supply Connection**: Connect a 12V power supply to the barrel connector. Ensure your power supply can handle the current draw of your LED setup.
2. **Power On**: Use the power switch to turn on the controller.
3. **LED Strip Connection**: Connect your RGBW, RGB, or White LED strip to the appropriate terminals on the controller.

### Manual Control

- With the mode selector switched to hardware control, use the knobs on the controller to adjust the brightness levels of each channel to your liking.

### Software Control

- Ensure the mode selector is set to software control.
- Connect the controller to your computer via USB. It should be recognized as a serial (RS232) device.
- You can now send commands from your computer to adjust the LED strip's settings. This is particularly useful for automated setups like lighting effects for 3D printers.

## Contributing

Contributions to this project are welcome! Whether it's bug fixes, feature enhancements, or documentation improvements, please feel free to fork the repository and submit a pull request.

## License

This project is released under the [MIT License](LICENSE.md). Feel free to use, modify, and distribute the code and designs as per the license terms.

## Contact

For questions, suggestions, or to report issues, please open an issue in this repository, and we'll get back to you as soon as possible.

Happy Lighting!
