/**************************************************************************
  * @brief           : C51 16个LED顺次点亮
  * @author        : fuqingchen@whut.edu.cn
  * @data  				 : 2018-10-16
***************************************************************************/

#include <reg51.h>
#define uchar unsigned char //刚好8位
#define uint unsigned int

void delay(uint i){ //抄的课本上的
	uchar t;
	while(i--){
		for(t = 0;t<120;t++);
	}
}

/*
控制开灯
输入：i 循环次数；P 各个接口的状态
返回循环次数
*/
uint light(uint i,uchar *P){
	if(i <= 8){
		*(P) = *(P) << 1;
		i++;
	}else if(i == 9){
		*(P) = 0x00;
		*(P+1) = 0x01; //第一个灯点亮
		i++;
	}else if(i <= 16){
		*(P+1) = *(P+1) << 1;
		i++;
	}else{ //恢复初始
		*(P) = 0x01; //我不知道怎么一次给一个数组全赋值，然后就分开写了
		*(P+1) = 0x00;
		i = 1;
	}
	return i;
}

void main(){
	uchar temp[2] = {0x01,0x00};
	uint j = 1;
  delay(100);
  P0 = ~temp[0]; //第一个灯点亮
  P1 = ~temp[1];
	while(1){
		delay(100);
		j = light(j,temp);
		P0 = ~temp[0];
		P1 = ~temp[1];
	}
}
/**
*
* ━━━━━━神兽出没━━━━━━
* 　　 ┏┓     ┏┓
* 　　┏┛┻━━━━━┛┻┓
* 　　┃　　　　　 ┃
* 　　┃　　━　　　┃
* 　　┃　┳┛　┗┳  ┃
* 　　┃　　　　　 ┃
* 　　┃　　┻　　　┃
* 　　┃　　　　　 ┃
* 　　┗━┓　　　┏━┛　Code is far away from bug with the animal protecting
* 　　　 ┃　　　┃    神兽保佑,代码无bug
* 　　　　┃　　　┃
* 　　　　┃　　　┗━━━┓
* 　　　　┃　　　　　　┣┓
* 　　　　┃　　　　　　┏┛
* 　　　　┗┓┓┏━┳┓┏┛
* 　　　　 ┃┫┫ ┃┫┫
* 　　　　 ┗┻┛ ┗┻┛
*
* ━━━━━━感觉萌萌哒━━━━━━
*/
