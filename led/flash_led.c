//
// Created by 林智聪 on 2021/11/11.
//
#include "include/flash_led.h"

void flash_led_ms(uint gpio, uint32_t interval) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
    while (true){
        gpio_put(gpio, 1);
        sleep_ms(interval);
        gpio_put(gpio, 0);
        sleep_ms(interval);
    }
}

void flash_led_sec(uint gpio, uint32_t interval) {
    flash_led_ms(gpio, interval * 1000);
}
