#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define METEOR_SIZE 10
#define SPEED       30  // Speed of meteor

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t hue = 0;

  // Fade all LEDs slightly to simulate a trail
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].fadeToBlackBy(40);
  }

  // Draw the meteor (a bright segment moving across the strip)
  for (int i = 0; i < METEOR_SIZE; i++) {
    int ledIndex = (i + hue) % NUM_LEDS;  // Wrap the meteor around the strip
    leds[ledIndex] = CHSV(hue, 255, 255);
  }

  FastLED.show();
  hue++;  // Move the meteor forward
  delay(SPEED);
}
