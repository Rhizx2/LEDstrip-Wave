#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       30  // Speed of the comet

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t hue = 0;

  for (int i = 0; i < NUM_LEDS; i++) {
    // Fade all LEDs a bit
    fadeToBlackBy(leds, NUM_LEDS, 20);
    
    // Set the current LED to a bright color
    leds[i] = CHSV(hue++, 255, 255);

    FastLED.show();
    delay(SPEED);
  }
}
