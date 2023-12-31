#include <REGX52.H>
#include "I2C.h"

#define AT24C02_SLAVE_ADDRESS_W 0xA0  //从机写地址
#define AT24C02_SLAVE_ADDRESS_R 0xA1  //从机读地址

/**
  * @brief AT24C02写入一个字节
  * @param  WordAddress 要写入字节的地址
	* @param  Data 要写入的数据
  * @retval 无
  */
void AT24C02_WriteByte(unsigned char WordAddress,Data)  //在WordAddress处写入Data
{
	I2C_Start();
	
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_W);  
	I2C_ReceiveAck();
	
	
	I2C_SendByte(WordAddress);  
	I2C_ReceiveAck();
	
	I2C_SendByte(Data);
	I2C_ReceiveAck();
	
	I2C_Stop();
}

/**
  * @brief AT24C02读取一个字节
  * @param  WordAddress 要读入字节的地址
  * @retval Data 读出的数据
  */
unsigned char AT24C02_ReadByte(unsigned char WordAddress)
{
	unsigned char Data;
	I2C_Start();
	
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_W);  
	I2C_ReceiveAck();
	
	I2C_SendByte(WordAddress);  
	I2C_ReceiveAck();
	
	I2C_Start();
	I2C_SendByte(AT24C02_SLAVE_ADDRESS_R);  
	I2C_ReceiveAck();
	
	Data=I2C_ReceiveByte();
	I2C_SendAck(1);
	I2C_Stop();
	return Data;
}