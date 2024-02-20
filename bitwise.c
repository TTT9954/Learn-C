#include <stdio.h>
#include <stdint.h>

uint8_t check_bit(uint8_t data, uint8_t bit_num)
{
    return ((data >> bit_num) & 0x1);
}

void send_data(uint8_t data)
{
    uint16_t temp = 0;
    for(uint8_t i = 0xF0; i > 0 ; i >>= 4)
    {
        temp = data & i;
        printf("%d",temp);
    }
}


int main()
{
    uint16_t a = 0;


    return 0;
}