#include <FastLED.h>

#include "colors.h"
#include "utils.h"

#define NUM_LEDS_LEFT 53
#define NUM_LEDS_RIGHT 54
#define NUM_LEDS NUM_LEDS_LEFT + NUM_LEDS_RIGHT
#define BRIGHTNESS 255

#define LEFT_LED_PIN 13  // D7
#define RIGHT_LED_PIN 14 // D5
#define BUTTON_PIN 4     // D2
#define WHEEL_PIN 0      // A0

#include "Palette.h"
Palette palette;

float ledY[] = {50,  52,  56,  63,  72,  83,  94,  108, 121, 136, 151, 169,
                185, 202, 214, 224, 238, 251, 263, 273, 280, 287, 298, 305,
                309, 312, 311, 309, 300, 286, 271, 255, 239, 225, 214, 199,
                183, 161, 152, 142, 144, 128, 117, 117, 128, 135, 130, 118,
                109, 88,  74,  60,  53,  171, 171, 173, 176, 181, 188, 199,
                210, 223, 236, 251, 266, 282, 299, 315, 332, 334, 353, 357,
                379, 389, 398, 405, 414, 423, 429, 433, 434, 432, 425, 421,
                396, 380, 364, 350, 337, 325, 308, 292, 276, 266, 265, 255,
                242, 233, 245, 255, 259, 250, 236, 221, 205, 193, 181};
float Y_MIN = 50;
float Y_MAX = 434;

float ledX[] = {265, 282, 298, 313, 327, 339, 350, 360, 369, 376, 380, 383,
                384, 382, 391, 402, 403, 394, 383, 371, 356, 341, 328, 314,
                298, 282, 266, 250, 238, 231, 232, 237, 242, 249, 261, 270,
                273, 274, 279, 291, 306, 304, 291, 275, 263, 249, 235, 231,
                238, 245, 235, 233, 244, 170, 154, 137, 122, 106, 92,  78,
                67,  57,  48,  41,  36,  33,  31,  32,  31,  17,  11,  16,
                27,  40,  53,  68,  82,  95,  111, 127, 143, 159, 173, 182,
                183, 181, 175, 168, 158, 147, 142, 141, 138, 128, 113, 106,
                118, 133, 146, 158, 173, 184, 184, 176, 171, 182, 180};
float X_MIN = 11;
float X_MAX = 403;

CRGB *leds;
CRGB *ledsLeft;
CRGB *ledsRight;

void setup() {
  Serial.begin(115200);
  delay(500);

  leds = new CRGB[NUM_LEDS];

  FastLED.addLeds<NEOPIXEL, LEFT_LED_PIN>(leds, NUM_LEDS_LEFT);
  FastLED.addLeds<NEOPIXEL, RIGHT_LED_PIN>(leds, NUM_LEDS_LEFT, NUM_LEDS_RIGHT);

  ledsLeft = &leds[0];
  ledsRight = &leds[NUM_LEDS_LEFT];

  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  FastLED.clear();
  palette.cycle();

  twinkle();

  FastLED.show();
}

void testAxisX() {
  static float x = X_MIN;
  static float inc = 0.5;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = fade(CRGB::White, ledX[i], x);
  }

  x += inc;
  if (x > X_MAX || x < X_MIN) {
    inc *= -1;
  }
}

void testAxisY() {
  static float y = Y_MIN;
  static float inc = 0.5;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = fade(CRGB::White, ledY[i], y);
  }

  y += inc;
  if (y > Y_MAX || y < Y_MIN) {
    inc *= -1;
  }
}
