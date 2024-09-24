#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       100  // Speed of theater chase effect

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int step = 0; step < 3; step++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = ((i + step) % 3 == 0) ? CRGB::Red : CRGB::Black;  // Light every 3rd LED
    }
    FastLED.show();
    delay(SPEED);
  }
}
