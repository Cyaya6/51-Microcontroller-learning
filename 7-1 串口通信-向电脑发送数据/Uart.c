#include <REGX52.H>

//配置串口
/**
  * @brief 串口初始化
  * @param 无
  * @retval  无
  */
void UartInit(void)		//4800bps@11.0592MHz
{
	PCON |= 0x80;		//使能波特率倍速位SMOD
	SCON = 0x50;		//8位数据,可变波特率
//	AUXR &= 0xBF;		//定时器1时钟为Fosc/12,即12T
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//清除定时器1模式位
	TMOD |= 0x20;		//设定定时器1为8位自动重装方式
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

//发送一个字节
/**
  * @brief 串口发送一个数据
  * @param  byte 要发送的一个字节数据
  * @retval 无
  */
void UartSendByte(unsigned char byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
	
}