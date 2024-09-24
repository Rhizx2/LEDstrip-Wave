#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       30  // Speed of confetti effect

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Slightly fade all LEDs to create a trailing effect
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(40);
  }

  // Randomly light up one LED
  int pos = random(NUM_LEDS);
  leds[pos] = CHSV(random(255), 255, 255);  // Random color
  
  FastLED.show();
  delay(SPEED);
}
