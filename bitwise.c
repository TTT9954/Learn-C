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
    uint8_t a = 0b11001011; // result: 0xE8
    int temp = 0;
    uint8_t output = 0;
    for(int i = 0; i < 8; i++)
    {
        temp = (a >> i) & 1;
        output |= temp << i;
        printf("%d\n",temp);
    }
            printf("%d\n",output);


    return 0;
}