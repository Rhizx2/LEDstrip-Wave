#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define TWINKLE_SPEED 100  // Speed of twinkling

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    if (random(10) > 8) {  // 20% chance to twinkle
      leds[i] = CRGB::White;
    } else {
      leds[i] = CRGB::Black;
    }
  }
  FastLED.show();
  delay(TWINKLE_SPEED);
}
