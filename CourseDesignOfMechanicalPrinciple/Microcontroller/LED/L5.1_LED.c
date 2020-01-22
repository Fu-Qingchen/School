/**************************************************************************
  * @brief           : C51 LED变速亮灯
  * @author        : fuqingchen@whut.edu.cn
  * @data  				 : 2018-10-13
***************************************************************************/

#include <reg51.h>
#include <intrins.h>
#include <math.h>
#define uchar unsigned char //刚好8位
#define uint unsigned int
#define N 16 //LED灯的数量
#define Loop 50 //控制一次循环采样次数

void delay(uint i){ //抄的课本上的
	uchar t;
	while(i--){
		for(t = 0;t<120;t++);
	}
}

/*
控制开灯
输入：i 时间（循环次数）；P 各个接口的状态
返回灯的序号
*/
void light(uint i,uint *P) {
	uint D[8] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
    //每个灯的代号，用于后面的逻辑运算
	uint speed = N*pow(i*1.0/Loop,0.5); //开灯的函数(上图曲线的函数)
	//return N*pow(i*1.0/Loop,1); //这是课本例题的函数
	if (speed < 8) {
		*(P) &= D[speed]; //P0
	}else{
		*(P+1) &= D[speed - 8];  //P1
	}
}

/*
控制关灯
输入：i 时间（循环次数）；P 各个接口的状态；
返回灯的序号
*/
void unlight(uint i,uint *P) {
	uint D[8] = {0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};
    //每个灯的代号，用于后面的逻辑运算
	uint speed = N*pow(i*1.0/Loop,2); //关灯的函数(上图曲线的函数)
    //return N*pow(i*1.0/Loop,1); //这是课本例题的函数
	if (speed < 8) {
		*(P) |= (~D[speed]); //P0
	}else{
		*(P+1) |= (~D[speed - 8]); //P1
	}
}

void main(){
	uint temp[2] = {0xFE,0xFF};
	uint j = 1;
	while(1){
		P0 = temp[0];
		P1 = temp[1];
		for (; j <= Loop; j++) {
			delay(50);
			light(j,temp);
			unlight(j,temp);
			P0 = temp[0];
			P1 = temp[1];
		}
		temp[0] = 0xFE; //我不知道怎么一次给一个数组全赋值，然后就分开写了
		temp[1] = 0xFF;
		j = 1;
	}
}
