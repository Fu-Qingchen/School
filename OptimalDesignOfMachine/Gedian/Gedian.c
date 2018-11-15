/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-10-30
* @Description: ��㷨����������
*************************************************/
#include<stdio.h>
#include<string.h>
#define A0 -9999	
#define H 9999
#define N 10 //�ȷ���-1����ൽ10000
#define V 0.00001	//����

/*************************************************
* @Description: Ҫ�Ҽ�С��ĺ���
*************************************************/
double function(double x) {
	return (x * x + 2 * x + 1);
}


/*************************************************
* @Description: ���˷�������
* @Input: a0:��ʼֵ,h:����,*range:�������Ҷ˵�
* @Return: �������Ҷ˵�
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
* @Description: ƽ������[a,b]Ϊ(n+1)�ȷ�
* @Input: a:������˵�,b:�����Ҷ˵�,A:�ȷֵ�����
* @Return: A[i]
*************************************************/
void findA(double a, double b, double *A) {
	for (int i = 0; i < N; i++)
	{
		*(A + i) = (b - a) / (N + 1)*(i + 1) + a;
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
* @Description: ��㷨�����Ҫ����
* @Input: a:������˵�,b:�����Ҷ˵�,varepsilon������
* @Return: A[i]
*************************************************/
double geDian(double a, double b, double varepsilon) {
	int num;
	double A[N], F[N];	//AΪ�ȷֵĵ㣬FΪ�ȷֵ�ĺ���ֵ
	do
	{
		findA(a, b, A);	//�õ��ȷֵ�
		for (int i = 0; i < N; i++)	//�õ��ȷֵ��Ӧ����ֵ
		{
			F[i] = function(A[i]);
		}
		num = findMin(F);
		switch (num)	//����
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