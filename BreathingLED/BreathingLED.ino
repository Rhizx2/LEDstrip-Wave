#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define BREATH_SPEED 20  // Speed of the breathing effect

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 255));  // Blue color
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(BREATH_SPEED);
  }
  
  for (int brightness = 255; brightness >= 0; brightness--) {
    fill_solid(leds, NUM_LEDS, CRGB(0, 0, 255));  // Blue color
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(BREATH_SPEED);
  }
}
