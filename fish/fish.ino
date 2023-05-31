#include <FastLED.h>

#define DATA_PIN 4
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS 68
#define BRIGHTNESS 255

#include "colors.h"
#include "Palette.h"
Palette palette;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  delay(500);

  //FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
}

void loop() {
  FastLED.clear();
  palette.cycle();

  twinkle();

  FastLED.show();
}
