/*
 * fader.c
 *
 * Created: 03.01.2018 20:55:13
 * Author : Dennis
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	// Set CPU speed by setting clock prescaler:
	// CCP register must first be written with the correct signature - 0xD8
	//CCP = 0xD8;
	//  CLKPS[3:0] sets the clock division factor
	//CLKPSR = 0; // 0000 (1)
	
	// Internal 128 kHz Oscillator (WDT Oscillator)
	//CLKMSR |= (1<<CLKMS0);
	
	DDRB |= (1 << PINB0);
	
	TCCR0A |= (1 << COM0A1)  | (1 << WGM00);
	TCCR0B |= (1 << CS01) | (1 << WGM02);
	OCR0A = 0;
	for (uint8_t i=0; i<0xFF; i++)
	{
		_delay_us(1500);
		OCR0A = i;
	}
	OCR0A = 0xFF;
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

