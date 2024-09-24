#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define BLINK_SPEED 100  // Speed of blinking effect

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  // Randomly blink LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    if (random(10) > 7) {  // 30% chance to blink
      leds[i] = CHSV(random(255), 255, 255);  // Random color
    } else {
      leds[i] = CRGB::Black;
    }
  }
  
  FastLED.show();
  delay(BLINK_SPEED);
}
