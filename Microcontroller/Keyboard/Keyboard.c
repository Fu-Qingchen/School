/*************************************************
* @Author: fuqingchen@whut.edu.cn
* @Date: 2018-11-12 20:06:29
* @Description: 电话键盘&拨号的模拟
*************************************************/

#include <reg51.h>
#include <intrins.h>
#include <string.h>
#define KEY P0	//分别读取A,B,C,D,1,2,3
#define LCD P1	//分别控制D0,D1,D2,D3,D4,D5,D6,D7
sbit RS = P2 ^ 0;	//控制RS
sbit RW = P2 ^ 1;	//控制RW
sbit E  = P2 ^ 2;	//控制E
unsigned char str[16];	//LCD1602第二行输出内容

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
* @Description: 根据输入在LCD上的操作
* @Input: no:读取的键盘字符[0,1,2,3,4,5,6,7,8,9,*,#]
*************************************************/
void get_No(int no) {
	char str2;
	if (no < 10)	//输入数字时，加一位数字
	{
		str2 = no + 48;	//将no给str2,48为ASCII码
		if (strlen(str)<16)
		{
			strcat(str, &str2);	//加一位数字
		}
	}
	else if (no == 10)	//输入 * 时，去一位数字
	{
		write_command_LCD(0x01);	//显示清屏
		delay(5);
		show_string_LCD(0x82, "#FU_QINGCHEN", 12);
		*(str + strlen(str) - 1) = 0;
		*(str + strlen(str)) = 0;
	}
	else    //输入 # 时，清屏
	{
		*str = 0;
		write_command_LCD(0x01);	//显示清屏
		delay(5);
		show_string_LCD(0x82, "#FU_QINGCHEN", 12);
		_nop_();
		delay(500);
	}
	show_string_LCD(0xC0, str, strlen(str));
	delay(5);
}

/*************************************************
* @Description: 输入 # 时清屏
*************************************************/
void get_sign() {
	//write_command_LCD(0x01);	//显示清屏
	delay(50);
	show_string_LCD(0x82, "#FU_QINGCHEN", 12);
	_nop_();
	delay(100);
}

/*************************************************
* @Description: 读取键盘的输入内容
*************************************************/
void getKeyValue() {
	int i;
	unsigned char R;	//行扫描值
	unsigned char C;	//列扫描值
	unsigned char RC;	//坐标
	KEY = 0x0F;	//ABCD取高电平，123取低电平
	if (KEY!=0x0F)	//KEY出现变化说明输入
	{
		delay(10);	//去抖动
		if (KEY!=0x0F)
		{
			R = (~KEY) & 0x0F;	//获取行值
			KEY = 0xEF;
			C = 0x10;
			for (i = 0; i < 3; i++)
			{
				if ((KEY|F0)!=0xFE)
				{
					break;
					RC = R | C;
					switch (RC)
					{
					case 0x28:get_No(0); break;
					case 0x11:get_No(1); break;
					case 0x21:get_No(2); break;
					case 0x41:get_No(3); break;
					case 0x12:get_No(4); break;
					case 0x22:get_No(5); break;
					case 0x42:get_No(6); break;
					case 0x14:get_No(7); break;
					case 0x24:get_No(8); break;
					case 0x44:get_No(9); break;
					case 0x18:get_No(10); break;
					case 0x48:get_No(11); break;
					}
				}
				KEY = _crol_(KEY, 1);
				C = _crol_(C, 1);
			}
		}
	}
}

void main() {
	initial_LCD();
	while (1)
	{
		get_sign();
		getKeyValue();
		//write_command_LCD(0x01);	//清屏
		delay(100);
	}
}