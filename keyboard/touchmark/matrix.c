/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = 0;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static bool read_matrix(matrix_row_t *mat);
static void init_rows(void);
static matrix_row_t read_row(uint8_t r);

static void init_cols(void);
static void select_col(uint8_t c);
static void deselect_col(uint8_t c);


void matrix_init(void)
{
    // initialize row and col
	init_rows();
	init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
	if (read_matrix(matrix_debouncing)) {
		debouncing = DEBOUNCE;
	}

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

static bool read_matrix(matrix_row_t *mat)
{
	// Return true if the output was changed
	bool changed = false;
	matrix_row_t pressed = 0;
    
	for (uint8_t c = 0; c < MATRIX_COLS; c++) {
        select_col(c);

		for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
			pressed = read_row(r)<<c;
			changed = changed || (mat[r] & 1<<c) != pressed;
			mat[r] = ( mat[r] & ~(1<<c) ) | pressed;
		}

        deselect_col(c);
    }
	return changed;
}

/* Row pin configuration
 * row: 0   1   2   3
 * pin: B3  B7  F5  F6
 */
static void init_rows(void)
{
	// Inputs wit pullup (DDR:0, PORT:1)
	DDRB	&= ~(1<<3 | 1<<7);
	PORTB	|=  (1<<3 | 1<<7);
	DDRF	&= ~(1<<5 | 1<<6);
	PORTF	|=  (1<<5 | 1<<6);
}

static matrix_row_t read_row(uint8_t r)
{
	// Pin low, button pressed
	switch (r) {
		case 0:
			return PINB & (1<<3) ? 0 : 1;
		case 1:
			return PINB & (1<<7) ? 0 : 1;
		case 2:
			return PINF & (1<<5) ? 0 : 1;
		case 3:
			return PINF & (1<<6) ? 0 : 1;
	}
}


/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11 
 * pin: C7  C6  D3  D2  D1  D0  F7  B6  B5  B4  D7  D6
 */
static void init_cols(void)
{
	// Output High(DDR:1, PORT:1)
	DDRB	|= (1<<4 | 1<<5 | 1<<6);
	PORTB	|= (1<<4 | 1<<5 | 1<<6);
	DDRC	|= (1<<6 | 1<<7);
	PORTC	|= (1<<6 | 1<<7);
	DDRD	|= (1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7);
	PORTD	|= (1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7);
	DDRF	|= (1<<7);
	PORTF	|= (1<<7);

	// Except D6 due to the LED on the same pin, put as Hi-Z(DDR:0, PORT:0)
	// This might require some delays when changing to low output when scaning
	DDRD	&= ~(1<<6);
	PORTD	&= ~(1<<6);
}
static void select_col(uint8_t c)
{
    // Output low(PORT:0) to select
	switch (c) {
		case 0:
			PORTC &= ~(1<<7);
			break;
		case 1:
			PORTC &= ~(1<<6);
			break;
		case 2:
			PORTD &= ~(1<<3);
			break;
		case 3:
			PORTD &= ~(1<<2);
			break;
		case 4:
			PORTD &= ~(1<<1);
			break;
		case 5:
			PORTD &= ~(1<<0);
			break;
		case 6:
			PORTF &= ~(1<<7);
			break;
		case 7:
			PORTB &= ~(1<<6);
			break;
		case 8:
			PORTB &= ~(1<<5);
			break;
		case 9:
			PORTB &= ~(1<<4);
			break;
		case 10:
			PORTD &= ~(1<<7);
			break;
		case 11:
			// Was in Hi-Z to avoid driving the LED on the same pin
			DDRD |= (1<<6);
			PORTD &= ~(1<<6);
			// without this wait read unstable value. At least it seemed like it
			_delay_us(10);
			break;
	}
}

static void deselect_col(uint8_t c)
{
    // Output low(DDR:1, PORT:0) to select
	switch (c) {
		case 0:
			PORTC |= (1<<7);
			break;
		case 1:
			PORTC |= (1<<6);
			break;
		case 2:
			PORTD |= (1<<3);
			break;
		case 3:
			PORTD |= (1<<2);
			break;
		case 4:
			PORTD |= (1<<1);
			break;
		case 5:
			PORTD |= (1<<0);
			break;
		case 6:
			PORTF |= (1<<7);
			break;
		case 7:
			PORTB |= (1<<6);
			break;
		case 8:
			PORTB |= (1<<5);
			break;
		case 9:
			PORTB |= (1<<4);
			break;
		case 10:
			PORTD |= (1<<7);
			break;
		case 11:
			// Hi-Z to avoid turning on LED
			DDRD &= ~(1<<6);
			PORTD &= ~(1<<6);
			// without this wait read unstable value. At least it seemed like it
			_delay_us(10);
			break;
	}
}

