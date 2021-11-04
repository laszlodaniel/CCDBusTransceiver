# CCDBusTransceiver
Development board for interfacing Chrysler's legacy CCD-bus (no CDP68HC68S1 chip needed).

To be used with [CCDLibrary](https://github.com/laszlodaniel/CCDLibrary).

The Chrysler CCD/SCI Scanner [Firmware](https://github.com/laszlodaniel/ChryslerCCDSCIScanner/tree/master/Arduino/ChryslerCCDSCIScanner) and [GUI](https://github.com/laszlodaniel/ChryslerCCDSCIScanner/raw/master/GUI/ChryslerCCDSCIScanner/bin/Debug/ChryslerCCDSCIScanner_GUI.zip) works with this hardware. There are obvious limitations of course and there may be connections issues but worth a try.

[Get one or two on Tindie!](https://www.tindie.com/products/25291/)

Wiring (V1.XX):

| PCB      | Arduino Mega | OBD2 connector  |
|----------|--------------|-----------------|
| J1 GND   | GND          |                 |
| J1 TX    | RXD1 + D3    |                 |
| J1 RX    | TXD1         |                 |
| J1 +5V   | +5V          |                 |
| J2 CCD-  |              | J1962-11        |
| J2 CCD+  |              | J1962-3         |
| J2 GND   |              | J1962-4         |

Connect TBEN jumpers if standalone operation is needed without a compatible vehicle.  
Disconnect TBEN jumpers when connected to a live CCD-bus network in a compatible vehicle.

Wiring (V3.XX):

| PCB      | Arduino Mega | OBD2 connector  |
|----------|--------------|-----------------|
|  5 CCD+  |              | J1962-3         |
|  6 CCD-  |              | J1962-11        |
|  7 GND   | GND          | J1962-4         |
|  8 RX    | TXD1         |                 |
|  9 TX    | RXD1         |                 |
| 13 CTRL  | D3           |                 |
| 14 +5V   | +5V          |                 |

[https://chryslerccdsci.wordpress.com/2020/03/22/re-designing-the-ccd-bus-transceiver-chip/](https://chryslerccdsci.wordpress.com/2020/03/22/re-designing-the-ccd-bus-transceiver-chip/)