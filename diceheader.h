#include <lpc21xx.h>
#define DATA_PIN 0xff
#define RS 1<<8
#define E 1<<9
#define seg_d  0xff<<23
#define seg_1 1<<16
#define seg_2 1<<17
#define seg_3 1<<18
#define seg_4 1<<19
void DATA(unsigned char);
void CMD(unsigned char);
unsigned char seg_lut[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
/*unsigned char cg_lut[]={0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,
		  0x00,0x00,0x00,0xa0,0xa0,0x00,0x00,0x00,
		  0x00,0xa0,0xa0,0x00,0x40,0x40,0x00,0x00,
		  0x00,0xa0,0xa0,0x00,0xa0,0xa0,0x00,0x00,
		  0x00,0x15,0x15,0x00,0xa0,0xa0,0x00,0x00,
		  0x00,0x15,0x15,0x00,0x15,0x15,0x00,0x00};
		  */
unsigned char cg_lut[]={0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF};
void delay_ms(int ms){
	T1PR=15000-1;
	T1TCR=0X01;	
	while(T1TC<ms);
	T1TCR=0X03;
	T1TCR=0x00;
	
}
void STR(unsigned char *s){
	while(*s)
	DATA(*s++);
}
void display_plr1(int n){
	int dly;
	for(dly=0;dly<200;dly++)
	{
	IOCLR1=seg_d;
	IOSET1=(seg_lut[n/10])<<23;
	IOCLR1=seg_1;
	delay_ms(5);
	IOSET1=seg_1;

	IOCLR1=seg_d;
	IOSET1=(seg_lut[n%10])<<23;
	IOCLR1=seg_2;
	delay_ms(5);
	IOSET1=seg_2;
}
}
void display_plr2(int n){
	int dly;
	for (dly=0;dly<200;dly++)
	{
	IOCLR1=seg_d;
	IOSET1=(seg_lut[n%10])<<23;
	IOCLR1=seg_3;
	delay_ms(5);
	IOSET1=seg_3;

	IOCLR1=seg_d;
	IOSET1=(seg_lut[n/10])<<23;
	IOCLR1=seg_4;
	delay_ms(5);
	IOSET1=seg_4;
}
}
void INIT(void){
 IODIR0=DATA_PIN|RS|E;				
 CMD(0X01);
 CMD(0X02);
 CMD(0X0C);
 CMD(0X38);
}
void CGRAM_WRITE(unsigned char nbytes){
	unsigned char i;
	CMD(0X40);
	for(i=0;i<nbytes;i++)
		DATA(cg_lut[i]);
}

void CMD(unsigned char cd){
	IOCLR0=DATA_PIN;
	IOSET0=cd;
	IOCLR0=RS;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
	}

void DATA(unsigned char d) {
	IOCLR0=DATA_PIN;
	IOSET0=d;
	IOSET0=RS;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
}
