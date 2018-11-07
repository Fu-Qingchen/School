/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-10-30
* @Description: 格点法求解迭代步长
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#define N 9 //等分数-1

/*************************************************
* @Description: 要找极小点的函数
*************************************************/
double function(double x) {
	return (x * x + 15 * x + 1);
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
	double a = -9, b = 1, varepsilon = 0.005, result;
	//a:区间左端点，b:区间右端点，varepsilon：精度，result：结果
	result = geDian(a,b,varepsilon);
	printf("Result:%f\n", result);
	system("pause");
}