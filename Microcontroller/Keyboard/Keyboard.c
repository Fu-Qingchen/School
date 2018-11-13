/*************************************************
* @Author: fuqingchen@whut.edu.cn
* @Date: 2018-11-12 20:06:29
* @Description: 电话键盘&拨号的模拟
*************************************************/

#include <reg51.h>
#include <intrins.h>
#define KEY P0	//分别读取A,B,C,D,1,2,3
#define LCD P1	//分别控制D0,D1,D2,D3,D4,D5,D6,D7
sbit RS = P2 ^ 0;	//控制RS
sbit RW = P2 ^ 1;	//控制RW
sbit E  = P2 ^ 2;	//控制E

/*************************************************
* @Description: 延时函数
* @Input: t:延长的时间
*************************************************/
void delay(unsigned int t) {
	unsigned char i;
	while (t--) {
		for (i = 0; i<120; i++);
	}
}

/*************************************************
* @Description: LCD1602读状态(查忙)
*************************************************/
void check_busy_LCD() {
	unsigned char pin;
	do
	{
		pin = 0xff;
		E = 0;
		RS = 0; RW = 1; E = 1;	//LCD读状态控制信号
		pin = LCD;
	} while (pin & 0x80);
	E = 0;
}

/*************************************************
* @Description: LCD1602写命令
* @Input: com:要写入的命令
*************************************************/
void write_command_LCD(unsigned char com) {
	check_busy_LCD();
	RS = 0; RW = 0;	//LCD写命令控制信号
	E = 0; LCD = com; E = 1;	//写命令正脉冲
	_nop_(); E = 0; delay(1);
}

/*************************************************
* @Description: LCD1602写数据
* @Input: date:要写入的数据
*************************************************/
void write_data_LCD(unsigned char date) {
	check_busy_LCD();
	RS = 1; RW = 0;	//LCD写数据控制信号
	E = 0; LCD = date; E = 1;	//写数据正脉冲
	_nop_(); E = 0; delay(1);
}

/*************************************************
* @Description: LCD1602初始化
*************************************************/
void initial_LCD() {
	write_command_LCD(0x38);	//两行显示，5*7点阵，8位数据接口
	_nop_();
	write_command_LCD(0x0C);	//整体显示，光标关，无显示
	_nop_();
	write_command_LCD(0x04);	//整屏不移位
	_nop_();
	write_command_LCD(0x01);	//显示清屏
}

/*************************************************
* @Description: LCD1602显示字符串
* @Input: address:字符串位置;*s:字符串;length:字符串长度
*************************************************/
void show_string_LCD(unsigned char address, unsigned char *s, unsigned int length) {
	unsigned int i;
	write_command_LCD(address);
	delay(5);
	for (i = 0; i < length; i++)
	{
		write_data_LCD(*(s + i));
	}
}

/*************************************************
* @Description: 输入 * 时删除一位输入
*************************************************/
void get_star() {
	;
}

/*************************************************
* @Description: 输入 # 时清屏
*************************************************/
void get_sign() {
	write_command_LCD(0x01);	//显示清屏
	delay(50);
	show_string_LCD(0x82, "#FU_QINGCHEN", 12);
	_nop_();
	delay(500);
}

/*************************************************
* @Description: 输入 数字 时显示号码
* @Input: 要显示的号码
*************************************************/
void get_num(unsigned int i) {
	show_string_LCD(0xC0, "56678", 5);
	delay(500);
	show_string_LCD(0xC0, "56678", 5);
	delay(500);
}

void main() {
	char s[16] = "0";
	initial_LCD();
	while (1)
	{
		get_sign();
		get_num(5);
		write_command_LCD(0x01);	//清屏
		delay(5);
	}
}