#include <stm32f4xx.h>
#include <includes.h>
#include <stdio.h>

int main()
{
	//u32 comp = 0;
	//u8 temp = 0,humi = 0;
	RTC_TimeTypeDef RTC_TimeStruct;
	RTC_DateTypeDef RTC_DateStruct;
	
	
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
	rtc_init();
	rtc_alarm_init();

	printf("app start!\r\n");
	
	//等待dht11 >1s
	delay_s(2);
	
	if(dht11_check()==0){
		printf("dht11 check!\r\n");
	}
	
	//iwdg_init();
	
	//parse_cmd();
	
	//配置蓝牙
	//ble_config();
	
	
	while(1){
		RTC_GetDate(RTC_Format_BCD,&RTC_DateStruct);
		RTC_GetTime(RTC_Format_BCD,&RTC_TimeStruct);
		
		printf("20%hhx-%hhx-%hhx %hhx %hhx:%hhx:%hhx\r\n",
				RTC_DateStruct.RTC_Year,RTC_DateStruct.RTC_Month,RTC_DateStruct.RTC_Date,RTC_DateStruct.RTC_WeekDay,
				RTC_TimeStruct.RTC_Hours,RTC_TimeStruct.RTC_Minutes,RTC_TimeStruct.RTC_Seconds);
		
		delay_s(1);
	}
	
}
