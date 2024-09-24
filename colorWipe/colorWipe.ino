#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       50  // Speed of color wipe

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Wipe with Red
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(SPEED);
  }
  
  // Wipe with Green
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(SPEED);
  }
  
  // Wipe with Blue
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(SPEED);
  }
}
