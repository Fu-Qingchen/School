/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-11-7 
* @Description: ���˷��������
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#define A0 0
#define H 1

/*************************************************
* @Description: Ҫ������ĺ���
*************************************************/
double function(double x) {
	return (x * x + 15 * x + 1);
}

/*************************************************
* @Description: ���˷�������
* @Input: a0:��ʼֵ,h:����,*range:�������Ҷ˵�
* @Return: �������Ҷ˵�
*************************************************/
void jintui(double a0, double h, double *range) {
	if (function(a0)==function(a0+h))
	{
		*(range) = a0;
		*(range + 1) = a0 + h;
	}
	else if (function(a0) > function(a0 + h))
	{
		*(range) = a0;
		do
		{
			a0 += h;
		} while (function(a0)>function(a0 + h));
		*(range + 1) = a0 + h;
	}
	else
	{
		*(range + 1) = a0 + h;
		do
		{
			a0 -= h;
		} while (function(a0)<function(a0 + h));
		*(range) = a0 - h;
	}
}

void main() {
	double a0 = A0, h = H;
	double range[2] = {0,0};
	jintui(a0, h, range);
	printf("Result:%f,%f\n", range[0], range[1]);
	system("pause");
}