//3.��1�� 0
//  ��2�� 1
//  ��3�� 1
//  ��4�� 0
//  ��5�� 1

//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	printf("����������������");
//	scanf_s("%d,%d,%d", &a, &b, &c);
//	if (a < b)
//		if (b < c)
//			printf("max=%d\n", c);
//		else
//			printf("max=%d\n", b);
//	else if (a < c)
//		printf("max=%d\n", c);
//	else
//		printf("max=%d\n", a);
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int main()
//{
//	float a, b;
//	printf("������һ��С��1000������:");
//	while (1)
//	{
//		scanf_s("%f", &a);
//		if (a > 0 && a < 1000)
//		{
//			b = sqrt(a);
//			printf("������ƽ��������������Ϊ��%.0f\n", b);
//			system("pause");
//		}
//		else
//		{
//			printf("�������ӦΪС��1000�����������������룺");
//		}
//	}
//	return 0;
//}
//
//
////#include<stdio.h>
//int main()
//{
//	int x, y;
//	scanf_s("%d", &x);
//	if (x < 1)
//		y = x;
//	if (1 <= x and x < 10)
//		y = 2 * x - 1;
//	if (x >= 10)
//		y = 3 * x - 11;
//	printf("%d", y);
//	return 0;
//}

#include<stdio.h>
#include<math.h>
int main()
{
	int num, indiv, ten, hundred, thousand, ten_thousand, place;
	printf("������һ��������");
	scanf_s("%d", &num);
	if (num > 9999)
		place = 5;
	else if (num > 999)
		place = 4;
	else if (num > 99)
		place = 3;
	else if (num > 9)
		place = 2;
	else place = 1;
	printf("λ��Ϊ��%d\n", place);
	printf("ÿλ����Ϊ��");
	ten_thousand = num / 10000;
	thousand = (int)(num - ten_thousand * 10000) / 1000;
	hundred = (int)(num - ten_thousand * 10000 - thousand * 1000) / 100;
	ten = (int)(num - ten_thousand * 10000 - thousand * 1000 - hundred * 100) / 10;
	indiv = (int)(num - ten_thousand * 10000 - thousand * 1000 - hundred * 100 - ten * 10);
	switch (place)
	{
	case 5:printf("%d,%d,%d,%d,%d", ten_thousand, thousand, hundred, ten, indiv);
		printf("\n��������Ϊ:");
		printf("%d,%d,%d,%d,%d\n", indiv, ten, hundred, thousand, ten_thousand);
		break;
	case 4:printf("%d,%d,%d,%d", thousand, hundred, ten, indiv);
		printf("\n��������Ϊ:");
		printf("%d,%d,%d,%d\n", indiv, ten, hundred, thousand);
		break;
	case 3:printf("%d,%d,%d", hundred, ten, indiv);
		printf("\n��������Ϊ:");
		printf("%d,%d,%d\n", indiv, ten, hundred);
		break;
	case 2:printf("%d,%d", ten, indiv);
		printf("\n��������Ϊ:");
		printf("%d,%d\n", indiv, ten);
		break;
	case 1:printf("%d", indiv);
		printf("\n��������Ϊ:");
		printf("%d\n", indiv);
		break;
	}
	return 0;
}