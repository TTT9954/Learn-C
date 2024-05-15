#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define uchar   uint8_t
typedef struct Node
{
    int head;
    int tail;
    struct Node *next;
} node;

typedef struct 
{
    uint8_t number;
    uint8_t mode;
} GPIO_config;


typedef struct NODE
{
    int top;
    struct NODE *next;
} node1;

int top = -1;
int max_record;
int a[100];


void push(int n)
{
    top++;
    if(top >= max_record) printf("List is full !\n");  
    else a[top] = n;
}

void pop()
{
    a[top--] = 0;
    if(top == -1) printf("List is empty !");
}

void display(int a[])
{
  
    for(int i = 0; i <= top; i++)
    {
        printf("\na[%d]= %d\n", i, a[i]);
    }
    printf("Top: a[%d] = %d", top, a[top]);

}


#define GPIOA ((GPIO_x*)&gpioa)


void SPI_Transmit(uint8_t *a, uint8_t *TxBuffer, uint32_t size)
{
    if(size == 0) return;
	else
	{
		while(size > 0)
		{		
			*a = *(TxBuffer);			
			size--;
            //a++;
            TxBuffer++;
		}
	}
}

uint8_t checkMA (uchar *data, uint32_t data_length, uchar *pattern, uint32_t pattern_length)
{
    // uchar UART_DATA[150] = {0x12, 0x13, 0xE1, 0xE2, 0x32, 0xE3, 0xE4, 0x34, 0xE5, 0x78, 0xE6, 0xE7, 0x15, 0xE8};
    // uchar MA[8]  = {0xE1 , 0xE2 , 0xE3 , 0xE4 , 0xE5 , 0xE6, 0xE7 , 0xE8};
    uchar indexData=0,indexMA=0,haveObject=1,indexStart=0;
    uchar is_checked = 0;
    uint32_t sum = 0;
    uint32_t sum1 = 0;
    uchar *arrStartAdd = malloc(pattern_length * sizeof(uint8_t)); // Mảng lưu vị trí phát hiện khả năng bắt đầu của chuỗi MA
        for(uchar i=0;i<data_length;i++)
        {
            for(uchar j=0;j<pattern_length;j++)
            {
                if(data[i] == pattern[j])
                {
                    arrStartAdd[indexStart] = i;
                    indexStart++;
                }
            }
        }
        for(uchar j=0;j<pattern_length;j++)
        {
            sum += data[arrStartAdd[j]] - pattern[j];  
        }
        if(sum) return 1;
        else return 0; 

        // for(uchar j=0;j<indexStart;j++)
        // {
        //     indexData = _arrStartAdd[j];
        //     for(uchar i=indexData;i<150;i++)
        //     {
        //         if(*data++ == *(pattern+indexMA)) // check
        //         {
        //             haveObject=1;
        //             indexMA+=1; // Lần check sau sẽ kiểm tra mã tiếp theo
        //             indexData = i; // Lần quét sau sẽ bắt đầu tại vị trí i này
        //         }
        //         else
        //         {
        //             haveObject = 0;
        //             return 0;
        //         }
        //     }
        //     if(indexMA>=pattern_length) // Nếu đúng hết các vị trí thì có xuất hiện
        //     {
        //         return 1;
        //     }
        // }
    
}

int main()
{ 
    // char arr[5];
    // uint8_t arr1[6] = {0x13, 0x12, 0x14, 0x12, 0x15, 0x12};
    // uint8_t *TxBufferMain = arr1; 
    // char *c[2] = {"Hello", "World"};
    // uint32_t len = sizeof(arr1)/sizeof(*arr1);
    // int i = 0;
    // printf("size: %d\n", strlen(c[0]));
    // printf("%c\n", *(c[1]+2));
    // while (len)
    // {
    //     SPI_Transmit(arr+i, (uint8_t *)(arr1+i), sizeof(arr1[i]));
    //     printf("%#x\n", *(arr+i));
    //     len--;
    //     i++;
    // }

    // uchar UART_DATA[] = {0x12, 0x13, 0xE1, 0xE2, 0x32, 0xE3, 0x34, 0xE5, 0x78, 0xE6, 0xE7, 0x15, 0xE8, 0xE4, 0xE8};
    // uchar MA[]  = {0xE1 , 0xE2 , 0xE3 , 0xE4 , 0xE5 , 0xE6, 0xE7 , 0xE8, 0xE8, 0xE1, 0xE4, 0xE9};
    
    // uint32_t size_of_data = sizeof(UART_DATA)/sizeof(UART_DATA[0]);
    // uint32_t size_of_pattern = sizeof(MA)/sizeof(MA[0]);

    // uint32_t *p = (uint32_t *)0x64feaa;
    // p++;
    // *p = 0x34;
    // printf("%x", MA[5]);
    uint8_t Addr = 0;

    scanf("%x", &Addr);
	
    Addr = Addr << 1;
    Addr = Addr & (uint8_t)(~(1));

    printf("R/W: %#x\n", Addr & 0x1);
    printf("Address: %#x", (Addr >> 1) & 0x7F);




    return 0;
}

    
