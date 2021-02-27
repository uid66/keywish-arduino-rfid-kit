/***********************************************************************
 *       __                                                          _
 *      / /        _____  __    __  _          _   (_)   ________   | |
 *     / /____   / _____) \ \  / / | |   __   | |  | |  (  ______)  | |_____
 *    / / ___/  | |_____   \ \/ /  | |  /  \  | |  | |  | |______   |  ___  |
 *   / /\ \     | |_____|   \  /   | | / /\ \ | |  | |  (_______ )  | |   | |
 *  / /  \ \__  | |_____    / /    | |/ /  \ \| |  | |   ______| |  | |   | |
 * /_/    \___\  \______)  /_/      \__/    \__/   |_|  (________)  |_|   |_|
 *
 *
 * KeyWay Tech firmware
 *
 * Copyright (C) 2015-2020
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, in version 3.
 * learn more you can see <http://www.gnu.org/licenses/>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * [Title]      Infrared transmitter module
 * [Diagram]
 *         Arduino PIN 11   ===================  Infrared transmitter module pin Y
 *         Arduino PIN GND  ===================  Infrared transmitter module pin G
 *         Arduino PIN +5V  ===================  Infrared transmitter module pin R
 */
#include <Wire.h> 
#include "LiquidCrystal_I2C.h"
#include "IRremote.h"

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
IRrecv irrecv(11);
decode_results results;

void setup()
{  
    lcd.init();                      // initialize the lcd
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(2,0); // go to start of 2nd line
    lcd.print("Hello, world!");
    irrecv.enableIRIn();
}

int counter = 0;
void loop()
{
    if (irrecv.decode(&results)) {
        lcd.setCursor(0,1);
        lcd.print("222");//results.value);
        lcd.print("        ");
        irrecv.resume();
    }
    else {
        counter++;
        if (counter % 10 == 0) {
          lcd.setCursor(0,0);
          lcd.print(counter);
          lcd.print("        ");
        }
    }
    delay(120);
}
