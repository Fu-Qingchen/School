/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-10-20
* @Description: ��㷨����������
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#define	A0		100			//������ֵ
#define	V		0.000001	//��������
#define N		2			//������������
#define H		10			//��㷨����
#define N_1d	10			//��㷨�ȷ���

/*************************************************
* @Description: ����С�㺯��
*************************************************/
double function_main(double x1,double x2) {
	return 10 * (x1 + x2 - 5)*(x1 + x2 - 5) + (x1 - x2)*(x1 - x2);
}

/*************************************************
* @Description: һά����Ҫ�Ҽ�С��ĺ���
*************************************************/
double function_1d(double x) {
	return (x * x - 2 * x + 1);
}

/*************************************************
* @Description: ���˷�������
* @Input: a0:��ʼֵ,h:����,*range:�������Ҷ˵�
* @Return: �������Ҷ˵�
*************************************************/
void jintui(double a0, double h, double *range) {
	if (function_1d(a0) == function_1d(a0 + h))
	{
		*(range) = a0;
		*(range + 1) = a0 + h;
	}
	else if (function_1d(a0) > function_1d(a0 + h))
	{
		*(range) = a0;
		do
		{
			a0 += h;
		} while (function_1d(a0)>function_1d(a0 + h));
		*(range + 1) = a0 + h;
	}
	else
	{
		*(range + 1) = a0 + h;
		do
		{
			a0 -= h;
		} while (function_1d(a0)<function_1d(a0 + h));
		*(range) = a0 - h;
	}
}

/*************************************************
* @Description: ƽ������[a,b]Ϊ(n+1)�ȷ�
* @Input: a:������˵�,b:�����Ҷ˵�,A:�ȷֵ�����
* @Return: A[i]
*************************************************/
void findA(double a, double b, double *A) {
	for (int i = 0; i < N_1d; i++)
	{
		*(A + i) = (b - a) / (N_1d + 1)*(i + 1) + a;
	}
}

/*************************************************
* @Description: ��������Сֵ���
* @Input: A:����
* @Return: ��Сֵ���
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
* @Description: ��㷨�����Ҫ����
* @Input: a:������˵�,b:�����Ҷ˵�,varepsilon������
* @Return: A[i]
*************************************************/
double geDian(double a, double b, double varepsilon) {
	int num;
	double A[N_1d], F[N_1d];	//AΪ�ȷֵĵ㣬FΪ�ȷֵ�ĺ���ֵ
	do
	{
		findA(a, b, A);	//�õ��ȷֵ�
		for (int i = 0; i < N_1d; i++)	//�õ��ȷֵ��Ӧ����ֵ
		{
			F[i] = function_1d(A[i]);
		}
		num = findMin(F);
		switch (num)	//����
		{
		case 0:b = A[(num + 1)]; break;
		case N_1d:a = A[(num - 1)]; break;
		case N_1d - 1:a = A[(num - 1)]; break;
		default:a = A[(num - 1)]; b = A[(num + 1)]; break;
		}
	} while (b - a > 0 ? ((b - a) > varepsilon) : ((a - b) > varepsilon));
	return 1.0 / 2 * (a + b);
}

void main() {
	double a0 = A0, h = H, range[2] = { 0,0 }, varepsilon = V, result;
	jintui(a0, h, range);
	result = geDian(range[0], range[1], varepsilon);
	printf("Result:%lf\n", result);
	system("pause");
}