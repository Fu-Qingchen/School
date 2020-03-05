/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-11-22
* @Description: 改进鲍威尔法无约束优化
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define A0	0	//给定初值1
#define A1	0	//给定初值2
#define V	0.000001	//给定精度

#define N	2	//函数变量个数
#define H	10	//格点法步长
#define N_1d	10	//格点法等分数-1
//#define function_main(x1,x2) ((x1) * (x1) + 2 * (x2)*(x2) - 4 * (x1) - 2 * (x1)*(x2))	//要求解的函数
#define function_main(x1,x2) ((x1)*(x1)+2*(x2)*(x2)-4*(x1)-2*(x1)*(x2))	//要求解的函数

/*************************************************
* @Description: 进退法主函数
* @Input: a0:初始值,h:步长,*range:区间左右端点,*x:无约束问题的点，*S:搜索方向
* @Return: 区间左右端点
*************************************************/
void jintui(double a0, double h, double *range,double *x,double *S) {
	if (function_main(*(x)+a0*S[0],*(x+1)+a0*S[1]) == function_main(*(x)+(a0+h) * S[0], *(x + 1) + (a0+h) * S[1]))
	{
		*(range) = a0;
		*(range + 1) = a0 + h;
	}
	else if (function_main(*(x)+a0 * S[0], *(x + 1) + a0 * S[1]) > function_main(*(x)+(a0 + h) * S[0], *(x + 1) + (a0 + h) * S[1]))
	{
		*(range) = a0;
		do
		{
			a0 += h;
		} while (function_main(*(x)+a0 * S[0], *(x + 1) + a0 * S[1])>function_main(*(x)+(a0 + h) * S[0], *(x + 1) + (a0 + h) * S[1]));
		*(range + 1) = a0 + h;
	}
	else
	{
		*(range + 1) = a0 + h;
		do
		{
			a0 -= h;
		} while (function_main(*(x)+a0 * S[0], *(x + 1) + a0 * S[1])<function_main(*(x)+(a0 + h) * S[0], *(x + 1) + (a0 + h) * S[1]));
		*(range) = a0 - h;
	}
}

/*************************************************
* @Description: 平分区间[a,b]为(n+1)等分
* @Input: a:区间左端点,b:区间右端点,A:等分点数组
* @Return: A[i]
*************************************************/
void findA(double a, double b, double *A) {
	for (int i = 0; i < N_1d; i++)
	{
		*(A + i) = (b - a) / (N_1d + 1)*(i + 1) + a;
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
	for (int i = 0; i < N_1d; i++)
	{
		if (tem > *(A + i))
		{
			num = i;
			tem = *(A + i);
		}
	}
	return num;
}

/*************************************************
* @Description: 求数组最大值序号
* @Input: A:数组
* @Return: 最小值序号
*************************************************/
int findMax(double *A) {
	double tem = *(A + 0);
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		if (tem < *(A + i))
		{
			num = i;
			tem = *(A + i);
		}
	}
	return num;
}

/*************************************************
* @Description: 格点法求解主要函数
* @Input: a:区间左端点,b:区间右端点,varepsilon:精度,*x:无约束问题的点，*S:搜索方向
* @Return: A[i]
*************************************************/
double geDian(double a, double b, double varepsilon,double *x, double *S) {
	int num;
	double A[N_1d], F[N_1d];	//A为等分的点，F为等分点的函数值
	do
	{
		findA(a, b, A);	//得到等分点
		for (int i = 0; i < N_1d; i++)	//得到等分点对应函数值
		{
			F[i] = function_main(*(x)+A[i] * S[0], *(x + 1) + A[i] * S[1]);
		}
		num = findMin(F);
		switch (num)	//迭代
		{
		case 0:b = A[(num + 1)]; break;
		case N_1d:a = A[(num - 1)]; break;
		case N_1d - 1:a = A[(num - 1)]; break;
		default:a = A[(num - 1)]; b = A[(num + 1)]; break;
		}
	} while (b - a > 0 ? ((b - a) > varepsilon) : ((a - b) > varepsilon));
	return 1.0 / 2 * (a + b);
}

/*************************************************
* @Description: 鲍威尔法求解主要函数
* @Input: *a0:初始点,varepsilon：精度
* @Return: *a0极小点
*************************************************/
int powell(double *a0, double varepsilon) {
	//设置初值
	double S[N+1][N+1] = { 0 };	//前进方向
	double S_new[N+1] = { 0 },sn1 = 0,sn2 = 0;	//构造的新方向
	double f[N + 1] = { 0 };	//迭代中的极小点
	double size[N] = { 0 };	//步长
	double delta[N] = { 0 };	//每前进一步的下降量
	int delta_max = 0;	//最大下降量对应序号
	double a00[N] = { 0 };	//初始点
	double a000[N] = { 0 };	//反射点
	double f1 = 0, f2 = 0, f3 = 0;	//方向有效性中的f1,f2,f3
	double h = H, range[2] = { 0,0 };	//一维搜索相关参数
	int i = 0, j = 0, k = 0;
	for (i = 0; i < N; i++)
	{
		S[i][i] = 1;
	}
	do
	{
		k++;
		printf("%d\n", k);
		f[0] = function_main(*(a0), *(a0 + 1));
		a00[0] = *(a0);
		a00[1] = *(a0 + 1);
		for (i = 0; i < N; i++)	//一维搜索
		{
			jintui(a0[i], h, range, a0, S[i]);
			size[i] = geDian(range[0], range[1], varepsilon, a0, S[i]);	//获取最优步长
			*(a0 + 0) = *(a0 + 0) + size[i] * S[i][0];	//获取极值点
			*(a0 + 1) = *(a0 + 1) + size[i] * S[i][1];
			f[i + 1] = function_main(*(a0), *(a0 + 1));	//获取极值点函数值
			delta[i] = f[i] - f[i + 1];
		}
		if (sqrt(pow(*(a0)-a00[0], 2) + pow(*(a0+1)-a00[1], 2))<varepsilon)	//收敛判断
		{
			return 0;
		}
		delta_max = findMax(delta);	//找到最大下降值
		for (i = 0; i < N; i++)
		{
			S_new[i] = *(a0 + i) - a00[i];	//构造新方向
			a000[i] = 2 * (*(a0 + i)) - a00[i];
		}
		sn1 = S_new[0];
		sn2 = S_new[1];
		f1 = f[0], f2 = f[N], f3 = function_main(a000[0], a000[1]);
		if (f3<f1 && ((f1 - 2 * f2 + f3)*pow(f1 - f2 - delta[delta_max], 2)<0.5*delta[delta_max] * pow(f1 - f3, 2)))	//方向有效
		{
			jintui(a0[0], h, range, a00, S_new);
			size[0] = geDian(range[0], range[1], varepsilon, a00, S_new);	//获取最优步长
			*(a0 + 0) = *(a00 + 0) + size[0] * S_new[0];	//获取极值点
			*(a0 + 1) = *(a00 + 1) + size[0] * S_new[1];
			f[0] = function_main(*(a0), *(a0 + 1));	//获取极值点函数值
			for (i = 0; i < N; i++)
			{
				if (i>=delta_max)
				{
					for ( j = 0; j < N; j++)
					{
						S[i - 1][j] = S[i][j];
					}
				}
			}
			S[N - 1][0] = sn1;
			S[N - 1][1] = sn2;
		}
		else	//方向无效
		{
			if (f3<f2)
			{
				*(a0 + 0) = a000[0];	//获取新初值
				*(a0 + 1) = a000[1];
			}
		}
	} while (1);
}

void main() {
	double a0[N], varepsilon = V;
	a0[0] = A0;
	a0[1] = A1;
	powell(a0, varepsilon);
	printf("x1:%lf\nx2:%lf\n", a0[0], a0[1]);
	system("pause");
}