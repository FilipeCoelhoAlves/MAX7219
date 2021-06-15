#include "max7219.h"

void max7219WriteByte(uint8_t data){
    //Implements the serial comunication with the chip...on this case spi
    spiSend(data);
}

void max7219WriteData(uint8_t address,uint8_t data){
    slaveSelect();
    max7219WriteByte(address);
    max7219WriteByte(data);
     slaveDeselect();
}

void max7219Nop(){
    max7219WriteData(MAX7219_ADDR_NOP,0x00);
}

void max7219Operation(uint8_t operation){
    max7219WriteData(MAX7219_ADDR_SHUTDOWN,operation);
}

void max7219Intensity(uint8_t intensity){
    max7219WriteData(MAX7219_ADDR_INTENSITY,intensity);
}

void max7219Digit(uint8_t digit,uint8_t data){
    max7219WriteData(digit,data);
}

void max7219DecodeMode(uint8_t decodemode){
    max7219WriteData(MAX7219_ADDR_DECODMODE,decodemode);
}

void max7219ScanLimit(uint8_t scanlimit){
    max7219WriteData(MAX7219_ADDR_SCAN_LIMIT,scanlimit);
}

void max7219Flush(){
    max7219Operation(MAX7219_NORMAL_OP);
    max7219DecodeMode(MAX7219_NO_DECODE);
    for(uint8_t x=0;x<8;x++){
        max7219Digit(MAX7219_ADDR_DIG_0+x,0);
    }
    max7219Operation(MAX7219_SHUTDOWN);
}


void max7219Start(uint8_t decodemode,uint8_t intensity,uint8_t displays){
    spiStart(SPICLOCKPRESCALER16);
    max7219Operation(MAX7219_NORMAL_OP);
    max7219DecodeMode(decodemode);
    max7219Intensity(intensity);
    max7219ScanLimit(displays);
}
