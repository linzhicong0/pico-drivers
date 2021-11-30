//
// Created by 林智聪 on 2021/11/11.
//


#include "include/lcd1602.h"
int main(){

    lcd_init();
    lcd_write_chars("hello world!\nJack Lin!");

    sleep_ms(2000);
    lcd_move_cursor_left();
    sleep_ms(2000);
    lcd_move_cursor_right();
    sleep_ms(2000);
    lcd_clear();

    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    while(true) {

        gpio_put(25, 1);
        sleep_ms(200);
        gpio_put(25, 0);
        sleep_ms(200);
    }
}