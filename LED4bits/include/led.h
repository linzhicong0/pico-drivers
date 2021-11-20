//
// Created by 林智聪 on 2021/11/17.
//
#include "stdbool.h"
#include "pico/stdlib.h"

#ifndef LED4BITS_LED_H
#define LED4BITS_LED_H

#endif //LED4BITS_LED_H

/*! \brief Show the digit
 * \param data The digit need to be show
 * \param seg The position you want to show, start from 0
 */
void show(unsigned char data, unsigned int seg);
/*! \brief Init the pins
 */
void init();
/*! \brief Init the given pin, set it's direction
 *  \param pin The GPIO number need to be initialized
 *  \param out The direction want to be set
 */
static void init_pin(unsigned int pin, bool out);
/*! \brief Set byte to send to 74HC595
 *  \param b The byte
 */
static void write_byte(unsigned char b);
/*! \brief Send the byte to 74HC595
 *  \param pin The GPIO for SCLK
 */
static void write(unsigned char pin);
/*! \brief Output the bytes
 *  \param pin The GPIO for RCLK
 */
static void out(unsigned char pin);