#include <stm32f4xx.h>
#include <includes.h>
#include <stdio.h>

int main()
{
	//u32 comp = 0;
	//u8 temp = 0,humi = 0;
	//RTC_TimeTypeDef RTC_TimeStruct;
	//RTC_DateTypeDef RTC_DateStruct;
	
	
	//1.配置中断优先级分组 2:2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	led_init();
	//beep_reg_init();
	beep_lib_init();
	//key_init();
	exti_init();
	mq2_init();
	//timer10_init();
	//timer14_pwm_init();
	//timer1_pwm_init();
	usart1_init();
	usart3_init();
	//timer2_init();
	sr04_init();
	//rtc_init();
	//rtc_alarm_init();
	iic_init();

	printf("app start!\r\n");
	
	//等待dht11 >1s
	delay_s(2);
	
	if(dht11_check()==0){
		printf("dht11 check!\r\n");
	}
	
	//iwdg_init();
	
	parse_cmd();
	
	//配置蓝牙
	//ble_config();
	at24c02_write_byte(0x0,0x88);
	delay_ms(100);
	printf("data = %#x\r\n",at24c02_read_byte(0x0));
	
	while(1){
		
		delay_s(1);
	}
	
}
