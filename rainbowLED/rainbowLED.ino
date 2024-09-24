#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       30  // Speed of color transition

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t startIndex = 0;

  // Fill the LEDs with a rainbow
  fill_rainbow(leds, NUM_LEDS, startIndex, 7);  // Increment hue by 7 per LED
  FastLED.show();

  startIndex++;  // Shift the rainbow pattern
  delay(SPEED);
}
