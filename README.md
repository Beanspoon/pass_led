# pass_led

This project demonstrates simple radio comms between any number of participants.
It is a bare-metal implementation, using no external libraries.
The Nordic nrf52832 SoC code is imported from my previous "hello_C" project, which was written from scratch, beginning with just the arm gnu toolchain, the chipset's technical manual and a text editor.

## Project description
This project is initally written for the MBN52832DK development board, which has two buttons and two LEDs. Each button is mapped to an LED.
When the user presses a button, the participant board attempts to request the associated LED from another participant. If another board is currently "holding" this LED it will respond and the LED will be "passed" from the holder to the requester.
In the event that there is no response from a holder, the requesting participant will re-transmit its request a number of times.
Once a threshold number of re-tries is reached the board will assume that there is no holder, and will become the holder for that LED.
In the event that a requester detects another board attempting to request the same LED, it will drop its request.

## Sequence diagram
![sequence diagram](./out/sequence-diagrams/sequence-diagram.svg)