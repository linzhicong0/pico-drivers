//
// Created by 林智聪 on 2021/11/25.
//

#ifndef LCD_LCD1602_CMD_H
#define LCD_LCD1602_CMD_H

#endif //LCD_LCD1602_CMD_H


// Define the command
/*                              ---------------------------
 *                              Functional Setting Command
 *                              ---------------------------
 *    --------------------------------------------------------------------------------------------
 *      RS  |  R/W  |  DB7  |  DB6  |  DB5  |  DB4  |  DB3  |  DB2  |  DB1  |  DB0  |  Duration  |
 *    -------------------------------------------------------------------------------------------
 *      0   |   0   |   0   |   0   |   1   |   DL  |   N   |   F   |   X   |   X   |    40us    |
 *    --------------------------------------------------------------------------------------------
 *
 *    ------------------------------------------------
 *    DL: 0 -> 设置数据总线为4位; 1 -> 设置数据总线为8位;
 *    ------------------------------------------------
 *    N: 0 -> 显示一行; 1 -> 显示两行;
 *    ------------------------------------------------
 *    F: 0 -> 5*7 点阵/字符; 1 -> 5*10 点阵/字符
 *    ------------------------------------------------
 *
 *    ------------------------------------------------
 *    DL: 0 -> 4 bits data bus; 1 -> 8 bits data bus;
 *    ------------------------------------------------
 *    N: 0 -> display 1 row; 1 -> display 2 rows;
 *    ------------------------------------------------
 *    F: 0 -> 5*7 points/char; 1 -> 5*10 points/char
 *    ------------------------------------------------
 *
 */

// 0011 0000
#define CMD_ENABLE_8_BITS 0x30
// 0010 0000
#define CMD_ENABLE_4_BITS 0x20
// 0000 0000
#define CMD_ENABLE_1_ROW 0x00
// 0000 1000
#define CMD_ENABLE_2_ROWS 0x08
// 0000 0000
#define CMD_ENABLE_5_7_POINTS_CHAR 0x00
// 0000 0100
#define CMD_ENABLE_5_10_POINTS_CHAR 0x04



/*! \brief Clear all the chars, make the cursor back
 *  to left side set the AC back to 0
 */
// 0000 0001
#define CMD_CLEAR 0x01
/*! \brief Make the cursor back to the first position
 */
// Reset the cursor to the left side 0000 0010
#define CMD_RESET_CURSOR 0x02
// Move the cursor left after writing new data 0000 0100
#define CMD_NEW_DATA_CURSOR_LEFT 0x04
// 0000 0110
// Move the cursor right after writing new data
#define CMD_NEW_DATA_CURSOR_RIGHT 0x06
// 0000 0100
// Not moving the screen after writing new data
#define CMD_NEW_DATA_STATIC_SCREEN 0x02
// 0000 0101
// Move screen to right after writing new data
#define CMD_NEW_DATA_MOVE_RIGHT_SCREEN 0x05

// 0000 1000
#define CMD_DISPLAY_OFF 0x80
// 0000 1100
#define CMD_DISPLAY_ON 0x0C
// 0000 1000
#define CMD_DISPLAY_CURSOR_ON 0x0a
// 0000 1010
#define CMD_DISPLAY_CURSOR_OFF 0x08
// 0000 1000
#define CMD_DISPLAY_CURSOR_FLASH_OFF 0x08
// 0000 1001
#define CMD_DISPLAY_CURSOR_FLASH_ON 0x09

// 0001 0000
#define CMD_CURSOR_MOVE_LEFT 0x10
// 0001 0100
#define CMD_CURSOR_MOVE_RIGHT 0x14
// 0001 1000
#define CMD_ALL_CHARS_MOVE_LEFT 0x18
// 0001 1100
#define CMD_ALL_CHARS_MOVE_RIGHT 0x1c


#define CMD_FIRST_ROW_ADDR 0x80
#define CMD_SECOND_ROW_ADDR 0xc0
