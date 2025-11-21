/*
 * Project lasPotential
 * Author: Jamie Dowden-Duarte
 * Date: 11-12-2025
 * laser and photodiode functionality with neopixels
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"
#include "neopixel.h"
#include "Colors.h"

///////////////
/// Global//////
///////////////
const int LAS = D3;
const int PHOTO = A0;
const int PIXELCOUNT = 12;

int reading, prevRead;

SYSTEM_MODE(SEMI_AUTOMATIC);

///////////////
/// OBJECTS//////
///////////////
Adafruit_NeoPixel pixel(PIXELCOUNT, SPI1, WS2812B);

void setup()
{
  Serial.begin();
  waitFor(Serial.isConnected, 10000);

  /////////
  // pinMode
  /////////
  pinMode(LAS, OUTPUT);
  pinMode(PHOTO, INPUT);

  /////////
  // neopixel
  /////////
  pixel.begin();
  pixel.setBrightness(10);
  for (int i = 0; i < PIXELCOUNT; i++)
  {
    pixel.setPixelColor(i, blue);
    pixel.show();
  }
}

void loop()
{
  digitalWrite(LAS, HIGH);

  reading = analogRead(PHOTO);
  prevRead = 0;
  if (reading != prevRead)
  {
    Serial.printf("reading %i\n", reading);
    prevRead = reading;
    delay(1000);
    if (reading > 7)
    {
      Serial.printf("yellow");
      for (int i = 0; i < PIXELCOUNT; i++)
      {
        pixel.setPixelColor(i, yellow);
        pixel.show();
      }
    }
  }
  if (reading < 7)
  {
    for (int i = 0; i < PIXELCOUNT; i++)
    {
      pixel.setPixelColor(i, blue);
      pixel.show();
    }
  }
}
