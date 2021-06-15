#ifndef MAX7219_H_INCLUDED
#define MAX7219_H_INCLUDED

#include "core328p/spi.h"


//Register Address of max7219
#define MAX7219_ADDR_NOP          0x00
#define MAX7219_ADDR_DIG_0        0x01
#define MAX7219_ADDR_DIG_1        0x02
#define MAX7219_ADDR_DIG_2        0x03
#define MAX7219_ADDR_DIG_3        0x04
#define MAX7219_ADDR_DIG_4        0x05
#define MAX7219_ADDR_DIG_5        0x06
#define MAX7219_ADDR_DIG_6        0x07
#define MAX7219_ADDR_DIG_7        0x08
#define MAX7219_ADDR_DECODMODE    0x09
#define MAX7219_ADDR_INTENSITY    0x0A
#define MAX7219_ADDR_SCAN_LIMIT   0x0B
#define MAX7219_ADDR_SHUTDOWN     0x0C
#define MAX7219_ADDR_DISPLAY_TEST 0x0F

//Options for Shutdown register
#define MAX7219_SHUTDOWN         0x00
#define MAX7219_NORMAL_OP        0x01

//Options for Intensity
#define MAX7219_INTENSITY_0      0x00
#define MAX7219_INTENSITY_1      0x01
#define MAX7219_INTENSITY_2      0x02
#define MAX7219_INTENSITY_3      0x03
#define MAX7219_INTENSITY_4      0x04
#define MAX7219_INTENSITY_5      0x05
#define MAX7219_INTENSITY_6      0x06
#define MAX7219_INTENSITY_7      0x07
#define MAX7219_INTENSITY_8      0x08
#define MAX7219_INTENSITY_9      0x09
#define MAX7219_INTENSITY_10     0x0A
#define MAX7219_INTENSITY_11     0x0B
#define MAX7219_INTENSITY_12     0x0C
#define MAX7219_INTENSITY_13     0x0D
#define MAX7219_INTENSITY_14     0x0E
#define MAX7219_INTENSITY_15     0x0F
#define MAX7219_INTENSITY_MIN    MAX7219_INTENSITY_0
#define MAX7219_INTENSITY_MAX    MAX7219_INTENSITY_15


//DECODE MODES... IF BIT ENABLE  THE CHIP WILL INTERPRET BCD TO THE OUTPUT
#define MAX7219_NO_DECODE        0x00
#define MAX7219_DECODE_1         0x01
#define MAX7219_DECODE_2         0x03
#define MAX7219_DECODE_3         0x07
#define MAX7219_DECODE_4         0x0F
#define MAX7219_DECODE_5         0x1F
#define MAX7219_DECODE_6         0x3F
#define MAX7219_DECODE_7         0x7F
#define MAX7219_DECODE_8         0xFF

//SCAN LIMITS...NUMBER OS DISPLAYS PER CHIP ENAB

#define MAX7219_SCAN_DISP_1      0x00
#define MAX7219_SCAN_DISP_2      0x01
#define MAX7219_SCAN_DISP_3      0x02
#define MAX7219_SCAN_DISP_4      0x03
#define MAX7219_SCAN_DISP_5      0x04
#define MAX7219_SCAN_DISP_6      0x05
#define MAX7219_SCAN_DISP_7      0x06
#define MAX7219_SCAN_DISP_8      0x07


void        max7219WriteByte(uint8_t data);                                      //Writes a byte on the bus
void        max7219WriteData(uint8_t address,uint8_t data);                      //Writes 16bits data on the bus
void        max7219Operation(uint8_t operation);                                 //Configures the operation mode enable or disable
void        max7219Nop();                                                        //Send a nop
void        max7219Intensity(uint8_t intensity);                                 //Set the intensity of the leds
void        max7219Digit(uint8_t digit,uint8_t data);                            //writes data to the digit
void        max7219DecodeMode(uint8_t decodemode);                               //Sets decod mode
void        max7219ScanLimit(uint8_t scanlimit);                                 //Number of displays or collums show
void        max7219Flush();                                                       //Reset data on the digits memory
void        max7219Start(uint8_t decodemode,uint8_t intensity,uint8_t displays); //Start routine




#endif // MAX7219_H_INCLUDED
