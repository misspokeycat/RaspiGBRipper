# RaspiGBRipper
A GB cartridge ripper for the Raspberry Pi

## Setup
Connect the pins of a GB cart header to the pi as follows:

| Cart Pin | GPIO Pin (Broadcom numbering) |
|--------------|-----------------------------|
| POWER (1)    | 5v Power |
| CLOCK (2)    | Not connected |
| WRITE (3)    | GPIO0 |
| READ (4)     | GPIO1 |
| SRAM (5)     | GPIO2 |
| Adress lanes (6-21) | GPIO3-18 |
| Data lanes (22-29) | GPIO19-26 |
| Reset (30) | 5v Power |
| AUDIOIN (31) | Not connected |
| GND (32) | Ground |

Build the ripper with `make`.  You can also build the pintest tool with `make pintest`, if you want to check your wiring.

## Usage
`ripper > romname.gb`

If you install `visualboyadvance`, you can also use `dumpandrun` to do more or less what the name of the script implies.
