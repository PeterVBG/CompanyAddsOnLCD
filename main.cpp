
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// wokwi project link: https://wokwi.com/projects/445516715245466625

// GLOBALS
#define LED_PIN     PB5
#define BUTTON_PIN    PB4

int main(void) {

    DDRB |= (1 << LED_PIN); //It configures the pin LED_PIN on Port B as an output.
    PORTB &= ~(1 << LED_PIN); //t turns OFF the LED connected to LED_PIN

    // SUPER LOOP
    while(1) {
        PORTB |= (1 << LED_PIN);  // LED ON
        _delay_ms(1000);      // Wait 1 second
        PORTB &= ~(1 << LED_PIN); // LED OFF
        _delay_ms(5000);      // Wait 5 second
    }

    return 0;
}