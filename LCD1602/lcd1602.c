//
// Created by 林智聪 on 2021/11/12.
//

#include "include/lcd1602.h"

static void write_data(unsigned char data);
static void write_com(unsigned char com);
static void init_pin(unsigned pin, bool out);
static void initPins();
static void setBits(unsigned char data);
static void new_line();

static bool is_new_line = false;

void lcd_init(){

    initPins();
    write_com(CMD_ENABLE_8_BITS | CMD_ENABLE_2_ROWS);
    write_com(CMD_DISPLAY_ON | CMD_DISPLAY_CURSOR_ON | CMD_DISPLAY_CURSOR_FLASH_ON);
    write_com(CMD_NEW_DATA_CURSOR_RIGHT);
    write_com(CMD_CLEAR);
    write_com(CMD_FIRST_ROW_ADDR);

}

void lcd_write_chars(char *c) {
    while( *c != '\0'){
        if (*c == '\n') {
            new_line();
            c++;
            continue;
        }
        write_data(*c++);
    }
}
void lcd_move_cursor_left() {
    write_com(CMD_CURSOR_MOVE_LEFT);
}

void lcd_move_cursor_right() {
    write_com(CMD_CURSOR_MOVE_RIGHT);
}

void lcd_clear() {
    write_com(CMD_CLEAR);
}

static void initPins() {

    init_pin(LCD1602_RS, GPIO_OUT);
    init_pin(LCD1602_E, GPIO_OUT);

    init_pin(LCD1602_D0, GPIO_OUT);
    init_pin(LCD1602_D1, GPIO_OUT);
    init_pin(LCD1602_D2, GPIO_OUT);
    init_pin(LCD1602_D3, GPIO_OUT);
    init_pin(LCD1602_D4, GPIO_OUT);
    init_pin(LCD1602_D5, GPIO_OUT);
    init_pin(LCD1602_D6, GPIO_OUT);
    init_pin(LCD1602_D7, GPIO_OUT);
}

static void write_com(unsigned char com) {
    gpio_put(LCD1602_E, 0);
    // Write command: rs -> L rw -> L
    gpio_put(LCD1602_RS, 0);
//    gpio_put(LCD1602_RW, 0);

    // high bits
    setBits(com);
    sleep_ms(1);

    gpio_put(LCD1602_E, 1);
    sleep_ms(1);
    gpio_put(LCD1602_E, 0);
    sleep_ms(0.5);

}

static void write_data(unsigned char data) {

    gpio_put(LCD1602_E, 0);
    // Write command: rs -> L rw -> L
    gpio_put(LCD1602_RS, 1);

    setBits(data);
    sleep_ms(1);

    gpio_put(LCD1602_E, 1);
    sleep_ms(1);
    gpio_put(LCD1602_E, 0);
}
// Set bit to each gpio by given byte data
void setBits(unsigned char data){
    gpio_put(LCD1602_D0, (data & 0b00000001) >> 0);
    gpio_put(LCD1602_D1, (data & 0b00000010) >> 1);
    gpio_put(LCD1602_D2, (data & 0b00000100) >> 2);
    gpio_put(LCD1602_D3, (data & 0b00001000) >> 3);
    gpio_put(LCD1602_D4, (data & 0b00010000) >> 4);
    gpio_put(LCD1602_D5, (data & 0b00100000) >> 5);
    gpio_put(LCD1602_D6, (data & 0b01000000) >> 6);
    gpio_put(LCD1602_D7, (data & 0b10000000) >> 7);
}

void init_pin(unsigned int pin, bool out) {
    gpio_init(pin);
    gpio_set_dir(pin, out);
}
static void new_line(){
    if (is_new_line){
        write_com(CMD_FIRST_ROW_ADDR);
    }
    write_com(CMD_SECOND_ROW_ADDR);

    is_new_line = ~is_new_line;
}

