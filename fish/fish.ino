#include <FastLED.h>

#include "colors.h"

#define NUM_LEDS 54
#define BRIGHTNESS 255

#define LEFT_LED_PIN 13  // D7
#define RIGHT_LED_PIN 14 // D5
#define BUTTON_PIN 4     // D2
#define WHEEL_PIN 0      // A0

#include "Palette.h"
Palette palette;

CRGB leftLEDs[NUM_LEDS];
CRGB rightLEDs[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  delay(500);

  FastLED.addLeds<NEOPIXEL, LEFT_LED_PIN>(leftLEDs, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, RIGHT_LED_PIN>(rightLEDs, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  FastLED.clear();
  palette.cycle();

  twinkle();
  // for (int i = 0; i < NUM_LEDS; i++) {
  //   leftLEDs[i] = CRGB::White;
  //   rightLEDs[i] = CRGB::White;
  // }

  FastLED.show();
}
