#include "include/led.h"
int main(){
    init();
    unsigned char data = 0;
    unsigned char seg = 0;
    while(true) {
        show(data,seg);
        sleep_ms(1000);
        data += 1;
        if (data == 16) {
            seg = (seg + 1) % 4;
        }
        data %= 16;

    }

}
