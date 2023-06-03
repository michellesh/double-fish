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

int leftY[] = {50,  52,  56,  63,  72,  83,  94,  108, 121, 136, 151,
               169, 185, 202, 214, 224, 238, 251, 263, 273, 280, 287,
               298, 305, 309, 312, 311, 309, 300, 286, 271, 255, 239,
               225, 214, 199, 183, 161, 152, 142, 144, 128, 117, 117,
               128, 135, 130, 118, 109, 88,  74,  60,  53,  53};
int rightY[] = {171, 171, 173, 176, 181, 188, 199, 210, 223, 236, 251,
                266, 282, 299, 315, 332, 334, 353, 357, 379, 389, 398,
                405, 414, 423, 429, 433, 434, 432, 425, 421, 396, 380,
                364, 350, 337, 325, 308, 292, 276, 266, 265, 255, 242,
                233, 245, 255, 259, 250, 236, 221, 205, 193, 181};
int Y_MIN = 50;
int Y_MAX = 434;

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

  static int y = Y_MIN;
  static int yInc = 1;
  int zThreshold = 5;
  for (int i = 0; i < NUM_LEDS; i++) {
    if (isBetween(leftY[i], y - zThreshold, y + zThreshold)) {
      leftLEDs[i] = CRGB::White;
    }
    if (isBetween(rightY[i], y - zThreshold, y + zThreshold)) {
      rightLEDs[i] = CRGB::White;
    }
  }

  y += yInc;
  if (y > Y_MAX || y < Y_MIN) {
    yInc *= -1;
  }

  // twinkle();

  // for (int i = 0; i < NUM_LEDS; i++) {
  //   leftLEDs[i] = CRGB::White;
  //   rightLEDs[i] = CRGB::White;
  // }

  FastLED.show();
}

bool isBetween(int value, int range1, int range2) {
  return value >= min(range1, range2) && value <= max(range1, range2);
}
