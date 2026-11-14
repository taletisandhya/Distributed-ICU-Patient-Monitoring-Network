#ifndef HEADER_H
#define HEADER_H

#include<lpc21xx.h>

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short int s16;

extern void delay_sec(unsigned int sec);
extern void delay_ms(unsigned int ms);

extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string(char *ptr);
extern void uart0_binary(int num);
extern void uart0_integer(int num);
extern void uart0_hex(int num);

extern u32 adc_read(u8 ch_num);
extern void adc_init(void);

extern void i2c_init(void);
extern void i2c_send(u8, u8, u8);
extern u8 i2c_receive(u8 , u8);
extern void i2c_read_buf(u8 sa,u8 mr,u8 *buf,u8 len);
extern u8 i2c_read(u8 sa,u8 mr);

typedef struct CAN1_MSG{

	u32 id;
	u32 byteA;
	u32 byteB;
	u8 rtr;
	u8 dlc;
	u8 ff;//ide

}CAN1;

extern void can1_rx(CAN1 *ptr);
extern void can1_tx(CAN1 v);
extern void can1_init(void);

#endif
