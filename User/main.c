#include "stm8l15x.h"
#include "user_usart.h"
#include "stdio.h"
#include "pcf8563.h"

#define LED_GPIO_PORT  GPIOD
#define LED_GPIO_PINS  (GPIO_Pin_4 | GPIO_Pin_1)
extern unsigned char time_buf1[8];
void delay(uint32_t time)
{
    uint32_t i,j;
    for(i=0;i<time;i++)
    {
        for(j=0;j<1000;j++)
        ;   
    }    
}
void main(void)
{
    CLK_HSICmd(ENABLE);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);

    uart1Init();
    enableInterrupts();
    userIICInit();
    uint8_t time;
    
  /* Infinite loop */
    while (1)
    {
		PCF8563_Read_Time();
		delay(70);
        printf("time:%d%d--%d%d--%d%d\r\n",time_buf1[1]/10,time_buf1[1]%10,time_buf1[2]/10,time_buf1[2]%10,time_buf1[3]/10,time_buf1[3]%10);
		printf("time:%d%d--%d%d--%d%d\r\n",time_buf1[4]/10,time_buf1[4]%10,time_buf1[5]/10,time_buf1[5]%10,time_buf1[6]/10,time_buf1[6]%10);
//		pcf8563ReadOneByte(PCF8563_SECOND_ADDRESS);
//		time = PCF8563_ReadOneByte(PCF8563_SECOND_ADDRESS);
//        GPIO_ToggleBits(GPIOD,GPIO_Pin_4);
//        GPIO_ToggleBits(GPIOD,GPIO_Pin_1);
    }
}