//
// Created by 林智聪 on 2021/11/17.
//

#include "include/led.h"
#include <stdio.h>


#ifdef CATHODE_COMMON
// 共阴极
unsigned char fseg[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
#else
// 共阳极
unsigned char fseg[] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
#endif

// 此管脚上升沿时将8位数据从缓存写出
#define SCLK 11
#define RCLK 12
// 此管脚用于传输一位数据
#define DIO 13

/*
 *
 */
void show(unsigned char data, unsigned int seg) {

    write_byte(fseg[data]);
    // 位选从1开始
    write_byte(0x01 << seg);
    out(RCLK);

}

void init(){

    init_pin(SCLK, GPIO_OUT);
    init_pin(RCLK, GPIO_OUT);
    init_pin(DIO, GPIO_OUT);

    // 清0
    write_byte(0x00);
    write_byte(0x00);
    out(RCLK);

}

void write_byte(unsigned char b) {

    // 从数据的高位写起->因为每写入一个数据，会将前一个数据往高位移动
    // Q0->Q1->Q2->Q3->Q4->Q5->Q6->Q7
    for (int i = 0; i < 8; i++) {
        if(b & 0x80){
            gpio_put(DIO, 1);
        } else{
            gpio_put(DIO, 0);
        }
        write(SCLK);
        b <<= 1;
    }

}

void write(unsigned char pin) {
    // SCLK 在上升沿中将数据写入寄存器
    gpio_put(pin, 0);
    gpio_put(pin, 1);
}

void init_pin(unsigned int pin, bool out) {
    gpio_init(pin);
    gpio_set_dir(pin, out);
}

void out(unsigned char pin) {

    // RCLK 在上升沿中将数据从寄存器输出到数码管
    gpio_put(pin, 0);
    gpio_put(pin, 1);
}

