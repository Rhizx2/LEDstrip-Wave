#include <FastLED.h>

#define LED_PIN     7
#define NUM_LEDS    50
#define WAVE_LENGTH 2   //num of led moving
#define BRIGHTNESS  255
#define SPEED       20    // Lower value for faster speed

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  static int position = 0; // Starting position of the wave

  // Reset all LEDs to black (off) at the start of each cycle
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  // Create a wave of 6 LEDs with varying brightness
  for (int i = 0; i < WAVE_LENGTH; i++) {
    int ledIndex = (position + i) % NUM_LEDS;  // Ensure the index wraps around the strip
    int brightness = sin8( (i * 255) / WAVE_LENGTH); // Sine wave pattern for smooth brightness
    
    leds[ledIndex] = CRGB(100, 50, 0);  // Set color (red for example)
    leds[ledIndex].fadeLightBy(255 - brightness);  // Apply the sine-based brightness
  }

  FastLED.show();
  delay(SPEED);

  position++;  // Move the wave forward
  if (position >= NUM_LEDS) {
    position = 0;  // Loop back to the start
  }
}
