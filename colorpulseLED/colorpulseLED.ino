#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define PULSE_SPEED 10   // Speed of color pulsing

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t hue = 0;

  // Pulse with a single color (Rainbow)
  for (int brightness = 0; brightness <= 255; brightness++) {
    fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255)); // Apply hue
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(PULSE_SPEED);
  }
  
  for (int brightness = 255; brightness >= 0; brightness--) {
    fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255)); // Apply hue
    FastLED.setBrightness(brightness);
    FastLED.show();
    delay(PULSE_SPEED);
  }

  hue += 5;  // Change hue for the next pulse
}
