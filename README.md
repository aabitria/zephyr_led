# STM32F407-DISCO Blinky 4 LEDS Project

This is a 4-LED version of Blinky project developed in Zephyr.  It is just
basic GPIO peripheral control with no threads yet.  It runs on STM32F407-DISC
discovery board.  This project is for use in Visual Studio Code.

Other settings:
IDE: vscode
Zephyr Version: 4.0.99
OS: Ubuntu 22.04

To build and to flash to a USB-connected discovery board, use the following
terminal commands:

   $ west build -b stm32f4_disco .

   $ west update

This can also be debugged with openocd in the host as the gdbserver, with the
gdb being inside the zephyr-sdk folder.