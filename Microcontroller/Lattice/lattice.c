/**************************************************************************
* @brief : C51 32×32点阵
* @author : fuqingchen@whut.edu.cn
* @data : 2018-10-31
***************************************************************************/
#include <reg51.h>
#define  R0 P0 //1为暗
#define  R1 P2 //1为暗
#define  C  P1 //0为暗

void delay(unsigned int i){
	unsigned char t;
	while(i--){
		for(t = 0;t<120;t++);
	}
}

void main() {
  while (1) {
    int x = 1,y = 1;
    unsigned char temR,temC;
    findP(x,y,&temR,&temC);
    R = ~temR;
    C = temC;
    delay(100);
  }
}
