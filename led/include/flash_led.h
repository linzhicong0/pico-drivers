//
// Created by 林智聪 on 2021/11/11.
//

#ifndef LED_FLASH_LED_H
#define LED_FLASH_LED_H

#endif //LED_FLASH_LED_H

#include "pico/stdlib.h"

/*! \brief Flash a led with the given interval
 *
 * \param gpio GPIO number
 * \param interval the time in ms the led will flash
 */
void flash_led_ms(uint gpio, uint32_t interval);
void flash_led_sec(uint gpio, uint32_t interval);
