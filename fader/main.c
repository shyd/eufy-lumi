/*
 * fader.c
 *
 * Created: 03.01.2018 20:55:13
 * Author : Dennis Schuett <https://schuett.io>
 */

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* OC0A as output */
    DDRB |= (1 << PINB0);

    /* Set OC0A/OC0B on Compare Match when up-counting.
    Clear OC0A/OC0B on Compare Match when down-counting.
    Mode 5: Fast PWM, 8-bit (with WGM02) */
    TCCR0A |= (1 << COM0A1) | (1 << COM0A0) | (1 << WGM00);

    /* Prescaler clk/8 */
    TCCR0B |= (1 << CS01) | (1 << WGM02);

    OCR0A = 0;
    for (uint8_t i=0; i<0xFF; i++)
    {
        _delay_us(2250);
        OCR0A = i;
    }
    OCR0A = 0xFF;

    while (1)
    {
    }
}
