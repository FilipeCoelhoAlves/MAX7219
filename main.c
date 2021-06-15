#include "core328p/hal.h"
#include "max7219.h"

int main(void){
    _delay_ms(1000);
    serialStart();
    serialStringLN_P(PSTR("MAX7219"));
    max7219Start(MAX7219_DECODE_8,MAX7219_INTENSITY_MAX,MAX7219_SCAN_DISP_8);
_delay_ms(1000);
_delay_ms(1000);
_delay_ms(1000);
 max7219Flush();
 _delay_ms(1000);
 max7219Start(MAX7219_DECODE_8,MAX7219_INTENSITY_MAX,MAX7219_SCAN_DISP_8);
    for(uint8_t x=0;x<8;x++){
        max7219Digit(MAX7219_ADDR_DIG_0+x,x);
        _delay_ms(100);
    }
    _delay_ms(1000);
    _delay_ms(1000);
    max7219Flush();

    while(1){

    }


    return 0;
}

/*

#include "core328p/hal.h"

int main(void){

    serialStart();
    serialStringLN_P(PSTR("MAX7219"));
    spiStart(SPICLOCKPRESCALER16);

         slaveSelect();
        spiSend(0x0C);
        spiSend(0x01);
        slaveDeselect();
        slaveSelect();
        spiSend(0x09);
        spiSend(0xFF);
        slaveDeselect();
         slaveSelect();

        spiSend(0x01);
        spiSend(0x00);
        slaveDeselect();
        uint8_t x=0;

    while(1){
        slaveSelect();
        spiSend(0x01);
        spiSend(x++);
        slaveDeselect();
        _delay_ms(500);
    }


    return 0;
}


*/
