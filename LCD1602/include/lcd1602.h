//
// Created by 林智聪 on 2021/11/12.
//

#ifndef LCD_LCD1602_H
#define LCD_LCD1602_H

#endif //LCD_LCD1602_H

#include "pico/stdlib.h"
#include "lcd1602_cmd.h"

#define LCD1602_RS 16
#define LCD1602_RW 12
#define LCD1602_E 17

#define LCD1602_D0 0
#define LCD1602_D1 1
#define LCD1602_D2 2
#define LCD1602_D3 3
#define LCD1602_D4 4
#define LCD1602_D5 5
#define LCD1602_D6 6
#define LCD1602_D7 7


//static void write_data(unsigned char com);
//static void write_com(unsigned char data);

void lcd_init();
void lcd_write_chars(char *c);
void lcd_move_cursor_left();
void lcd_move_cursor_right();
void lcd_clear();