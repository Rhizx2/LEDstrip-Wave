#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       100  // Delay for movement speed

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = (i % 2 == 0) ? CRGB::Red : CRGB::Green;  // Alternate between red and green
    FastLED.show();
    delay(SPEED);
    leds[i] = CRGB::Black;  // Turn off the LED after it moves
  }
}
