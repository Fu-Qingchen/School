/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-10-30
* @Description: 格点法求解迭代步长
*************************************************/
#include<stdio.h>
#include<string.h>
#define A0 -9999	
#define H 9999
#define N 10 //等分数-1，最多到10000
#define V 0.00001	//精度

/*************************************************
* @Description: 要找极小点的函数
*************************************************/
double function(double x) {
	return (x * x + 2 * x + 1);
}


/*************************************************
* @Description: 进退法主函数
* @Input: a0:初始值,h:步长,*range:区间左右端点
* @Return: 区间左右端点
*************************************************/
void jintui(double a0, double h, double *range) {
	if (function(a0) == function(a0 + h))
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


/*************************************************
* @Description: 平分区间[a,b]为(n+1)等分
* @Input: a:区间左端点,b:区间右端点,A:等分点数组
* @Return: A[i]
*************************************************/
void findA(double a, double b, double *A) {
	for (int i = 0; i < N; i++)
	{
		*(A + i) = (b - a) / (N + 1)*(i + 1) + a;
	}
}

/*************************************************
* @Description: 求数组最小值序号
* @Input: A:数组
* @Return: 最小值序号
*************************************************/
int findMin(double *A) {
	double tem = *(A + 0);
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		if (tem > *(A+i))
		{
			num = i;
			tem = *(A + i);
		}
	}
	return num;
}

/*************************************************
* @Description: 格点法求解主要函数
* @Input: a:区间左端点,b:区间右端点,varepsilon：精度
* @Return: A[i]
*************************************************/
double geDian(double a, double b, double varepsilon) {
	int num;
	double A[N], F[N];	//A为等分的点，F为等分点的函数值
	do
	{
		findA(a, b, A);	//得到等分点
		for (int i = 0; i < N; i++)	//得到等分点对应函数值
		{
			F[i] = function(A[i]);
		}
		num = findMin(F);
		switch (num)	//迭代
		{
		case 0:a = a; b = A[num + 1]; break;
		case N:b = b; a = A[num - 1]; break;
		default:a = A[num - 1]; b = A[num + 1]; break;
		}
	} while (b - a > 0 ? ((b - a) > varepsilon) : ((a - b) > varepsilon));
	return 1.0 / 2 * (a + b);
}

void main() {
	double a0 = A0, h = H, range[2] = { 0,0 }, varepsilon = V, result;
	jintui(a0, h, range);
	result = geDian(range[0],range[1],varepsilon);
	printf("Result:%f\n", result);
	getchar();
}