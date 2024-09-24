#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define SPEED       20   // Speed of color wave
#define WAVE_SIZE   10   // Size of the color wave

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  static uint8_t startHue = 0;
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(startHue + (i * (255 / WAVE_SIZE)), 255, 255); // Smooth color transition
  }
  
  FastLED.show();
  startHue += 1;  // Shift the starting hue to create movement
  delay(SPEED);
}
