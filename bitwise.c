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

uint8_t count_setbit(uint8_t n)
{
    uint8_t count = 0;
    uint8_t result = 0;
    while(n>>=1 !=0)
    {
        result = n & 0x1;
        if(result == 1) count++;
    }
    return count;
}

int main()
{
    uint8_t n=0;
    scanf("%d",&n);
    printf("number of setbit: %d\n", count_setbit(n));

    return 0;
}