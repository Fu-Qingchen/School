/*************************************************
* @Author: Fu_Qingchen
* @Date: 2018-11-22
* @Description: �Ľ�����������Լ���Ż�
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define A0	0	//������ֵ1
#define A1	0	//������ֵ2
#define V	0.000001	//��������

#define N	2	//������������
#define H	10	//��㷨����
#define N_1d	10	//��㷨�ȷ���-1
//#define function_main(x1,x2) ((x1) * (x1) + 2 * (x2)*(x2) - 4 * (x1) - 2 * (x1)*(x2))	//Ҫ���ĺ���
#define function_main(x1,x2) ((x1)*(x1)+2*(x2)*(x2)-4*(x1)-2*(x1)*(x2))	//Ҫ���ĺ���

/*************************************************
* @Description: ���˷�������
* @Input: a0:��ʼֵ,h:����,*range:�������Ҷ˵�,*x:��Լ������ĵ㣬*S:��������
* @Return: �������Ҷ˵�
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
* @Description: ���������ֵ���
* @Input: A:����
* @Return: ��Сֵ���
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
* @Description: ��㷨�����Ҫ����
* @Input: a:������˵�,b:�����Ҷ˵�,varepsilon:����,*x:��Լ������ĵ㣬*S:��������
* @Return: A[i]
*************************************************/
double geDian(double a, double b, double varepsilon,double *x, double *S) {
	int num;
	double A[N_1d], F[N_1d];	//AΪ�ȷֵĵ㣬FΪ�ȷֵ�ĺ���ֵ
	do
	{
		findA(a, b, A);	//�õ��ȷֵ�
		for (int i = 0; i < N_1d; i++)	//�õ��ȷֵ��Ӧ����ֵ
		{
			F[i] = function_main(*(x)+A[i] * S[0], *(x + 1) + A[i] * S[1]);
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

/*************************************************
* @Description: �������������Ҫ����
* @Input: *a0:��ʼ��,varepsilon������
* @Return: *a0��С��
*************************************************/
int powell(double *a0, double varepsilon) {
	//���ó�ֵ
	double S[N+1][N+1] = { 0 };	//ǰ������
	double S_new[N+1] = { 0 },sn1 = 0,sn2 = 0;	//������·���
	double f[N + 1] = { 0 };	//�����еļ�С��
	double size[N] = { 0 };	//����
	double delta[N] = { 0 };	//ÿǰ��һ�����½���
	int delta_max = 0;	//����½�����Ӧ���
	double a00[N] = { 0 };	//��ʼ��
	double a000[N] = { 0 };	//�����
	double f1 = 0, f2 = 0, f3 = 0;	//������Ч���е�f1,f2,f3
	double h = H, range[2] = { 0,0 };	//һά������ز���
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
		for (i = 0; i < N; i++)	//һά����
		{
			jintui(a0[i], h, range, a0, S[i]);
			size[i] = geDian(range[0], range[1], varepsilon, a0, S[i]);	//��ȡ���Ų���
			*(a0 + 0) = *(a0 + 0) + size[i] * S[i][0];	//��ȡ��ֵ��
			*(a0 + 1) = *(a0 + 1) + size[i] * S[i][1];
			f[i + 1] = function_main(*(a0), *(a0 + 1));	//��ȡ��ֵ�㺯��ֵ
			delta[i] = f[i] - f[i + 1];
		}
		if (sqrt(pow(*(a0)-a00[0], 2) + pow(*(a0+1)-a00[1], 2))<varepsilon)	//�����ж�
		{
			return 0;
		}
		delta_max = findMax(delta);	//�ҵ�����½�ֵ
		for (i = 0; i < N; i++)
		{
			S_new[i] = *(a0 + i) - a00[i];	//�����·���
			a000[i] = 2 * (*(a0 + i)) - a00[i];
		}
		sn1 = S_new[0];
		sn2 = S_new[1];
		f1 = f[0], f2 = f[N], f3 = function_main(a000[0], a000[1]);
		if (f3<f1 && ((f1 - 2 * f2 + f3)*pow(f1 - f2 - delta[delta_max], 2)<0.5*delta[delta_max] * pow(f1 - f3, 2)))	//������Ч
		{
			jintui(a0[0], h, range, a00, S_new);
			size[0] = geDian(range[0], range[1], varepsilon, a00, S_new);	//��ȡ���Ų���
			*(a0 + 0) = *(a00 + 0) + size[0] * S_new[0];	//��ȡ��ֵ��
			*(a0 + 1) = *(a00 + 1) + size[0] * S_new[1];
			f[0] = function_main(*(a0), *(a0 + 1));	//��ȡ��ֵ�㺯��ֵ
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
		else	//������Ч
		{
			if (f3<f2)
			{
				*(a0 + 0) = a000[0];	//��ȡ�³�ֵ
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