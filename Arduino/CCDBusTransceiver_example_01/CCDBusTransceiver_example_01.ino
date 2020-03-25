/*
 * CCDBusTransceiver_example_01 (https://github.com/laszlodaniel/CCDBusTransceiver)
 * Copyright (C) 2020, László Dániel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// Board: Arduino Uno

uint8_t engine_speed[] = { 0xE4, 0x00, 0x00, 0xE4 };
uint8_t vehicle_speed[] = { 0x24, 0x00, 0x00, 0x24 };

void setup()
{
    // Turn off Arduino UNO's built in LED.
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);

    // Set serial speed to 7812.5 baud (assuming 16 MHz clock speed).
    // Baudrate prescaler calculation: UBRR = (F_CPU / (16 * BAUDRATE)) - 1
    UBRR0H = (127 >> 8) & 0x0F;
    UBRR0L = 127 & 0xFF;

    // Enable serial receiver and transmitter.
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0);

    // Set frame format: asynchronous, 8 data bit, no parity, 1 stop bit.
    UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);
}

void loop()
{
    Serial.write(engine_speed, 4);
    delay(200);
    Serial.write(vehicle_speed, 4);
    delay(200);
}
