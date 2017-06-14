#include <stdio.h>
#include <stdint.h>
 
#define LENGTH_BYTES_POSITION_ZERO 0
#define LENGTH_BYTES_POSITION_ONE 1
#define LENGTH_BYTES_POSITION_CUSTOM 7
 
char mBufHexMes[100] = {0,0,0,0,0,0,0,0,0,0,0};
 

char* convertToHexString(uint8_t* buffer, uint8_t lengthBytesPosition, uint8_t bufferSize);
 

int main(void) {
    uint8_t MSG[12] = {0x0C, 0x2E, 0x21, 0x81, 0x11, 0x22, 0x06, 0x2E, 0x21, 0x81, 0x11, 0x22};
 
    printf("%s", convertToHexString(MSG, LENGTH_BYTES_POSITION_ZERO, 0));
 
    return 0;
}
 

 
//--------------------------------------------------------------------
char* convertToHexString(uint8_t* buffer, uint8_t lengthBytesPosition, uint16_t bufferSize)
//--------------------------------------------------------------------
{
    int16_t bufLength = 0;

    if(LENGTH_BYTES_POSITION_CUSTOM == lengthBytesPosition){
        bufLength = bufferSize;
    }
    else if(LENGTH_BYTES_POSITION_ZERO == lengthBytesPosition){
        bufLength = buffer[LENGTH_BYTES_POSITION_ZERO];
    }
    else if(LENGTH_BYTES_POSITION_ONE == lengthBytesPosition){
        bufLength = buffer[LENGTH_BYTES_POSITION_ZERO]*256 + buffer[LENGTH_BYTES_POSITION_ONE];
    }
    else{
        printf("can't process buffer when length write more than in 2 bytes");
    }

    for(uint16_t i = 0; i < bufLength; i++)
        sprintf(&mBufHexMes[3*i], "%02X ", buffer[i]);

    mBufHexMes[bufLength*3 - 1] = '\0';

    return mBufHexMes;
}