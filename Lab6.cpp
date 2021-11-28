#include <iostream>
#include <cmath>
#include <iomanip>
#include "Lab6.h"

using namespace std;

void ArrayOutput(int  mas[15])
{
	for (int i = 0; i < 15; ++i) {
		cout << mas[i] << " ";
	}
	cout << endl;
}
void TaskVariant()
{
	//подсчет варианта
	int K, N, Z;
	K = 0;
	N = 0;
	cout << "Variant:\n";
	cin >> N;
	for (K = 1; K <= 6; K++)
	{
		Z = (N + (K - 1) * 35);
		cout << "Z(" << K << ") = " << Z;
		cout << "\n\n";
	}
	cout << "\n\n";
}
void Task11()
{
	//Заполнить массив :
	//а) двадцатью первыми натуральными числами, делящимися нацело на 13 или на 17 и
	//большими 300;
	//б) тридцатью первыми простыми числами.
	int k, mas[20], mas2[30], i, j, l;
	//1
	k = 0;
	i = 300;
	while (k < 20)
	{
		if (i % 13 == 0) { mas[k] = i; k++; }
		if (i % 17 == 0) { mas[k] = i; k++; }
		i++;
	}
	for (i = 0; i < 20; i++)
		printf("%4d", mas[i]);
	//2
	k = 1;
	i = 1;
	mas2[0] = 2;
	while (k < 30) {
		for (j = 1; j <= i; j++)
			if (i % j == 0) l++;
		if (l == 2) { mas2[k] = i; k++; }
		l = 0;
		i += 2;
	}
	printf("\n\n");
	for (i = 0; i < 30; i++)
		printf("%4d", mas2[i]);

	cout << "\n\n";
}
void Task46()
{
	//Задана последовательность X из N вещественных чисел.Вычислить
	//	S = skrt((X - M)^2/(N-1))
	//	, где М - среднее арифметическое данной последовательности.
	int S, X = 0, M = 0;
	const int N = 10;
	int mas[N]={2,5,7,3,-2,-8,8,4,1,4};
	for (int i = 0; i < 10; i++)
	{
		M += mas[i];
	}
	M = M / 10;
	for(;X<N;X++)
	S = sqrt(pow(X - M, 2) / (N - 1));
	cout << "ans: "<< S;
	cout << "\n\n";
}
void Task81()
{
	//Дана последовательность натуральных чисел а1, a2, ..., а15.Определить, есть ли в
	//последовательности хотя бы одна пара одинаковых соседних чисел.В случае положительного
	//ответа определить порядковые номера чисел первой из таких пар.
	int i = 1, num = 1, prev, k = 0;
	const int N = 15;
	int mas[N] = { 2,5,5,3,2,3,8,4,1,4,6,3,5,7,8 };
	for (;i<15;num++)
	{
		prev = mas[num-1];
		if (k == 0 && prev == mas[num]) k = i;
		i++;
	}

	if (k) cout << k << " " << k++ << "\n";
	else cout << "NO\n";
	//dop
	int dop;
	cout << "Enter 1(Exit: 0):\n";
	cin >> dop;
	if (dop == 1)
	{
		int i = 1, num, prev, k = 0;

		cout << "Enter integer numbers (Exit: 000):\n";
		cin >> num;
		while (num != 000)
		{
			prev = num;
			cin >> num;
			if (k == 0 && prev == num) k = i;
			i++;
		}

		if (k) cout << k << " " << k + 1 << "\n";
		else cout << "NO\n";
	}
	else
	{
		cout << "\n\n";
	}

}
void Task116()
{
	//На k - e место одномерного массива целых чисел вставить элемент, равный разности
	//двух введенных с клавиатуры элементов.
	int numOne, numTwo, Num, Z;
	const int N = 15;
	int mas[N] = { 2,5,5,3,2,3,8,4,1,4,6,3,5,7,8 };
	cout << "Enter numbers one : \n";
	cin >> numOne;
	cout << "Enter numbers two : \n";
	cin >> numTwo;
	Num = numOne - numTwo;
	ArrayOutput(mas);
	cout << "\nreplace the number : \n";
	cin >> Z;
	mas[Z-1] = Num;
	ArrayOutput(mas);

}
void Task151()
{
	//Дан массив X[N] целых чисел.Не используя других массивов, переставить его элементы
	//в обратном порядке.
	const int N = 15;
	int mas[N] = { 2,5,5,3,2,3,8,4,1,4,6,3,5,7,8 };
	ArrayOutput(mas);
	for (int i = 0; i < N / 2; ++i)
	{
		int temp = mas[i];
		mas[i] = mas[N - i - 1];
		mas[N - i - 1] = temp;
	}
	ArrayOutput(mas);

}
void Task186()
{
	//В одномерном массиве все отрицательные элементы переместить в начало массива, а
	//остальные — в конец с сохранением порядка следования.Дополнительный массив
	//использовать не разрешается.
	const int N = 15;
	int mas[N] = { 2,5,5,3,-2,3,-8,4,1,-4,6,3,-5,7,8 };

	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - 1 - i; j++)
			if (mas[j] > 0)
				if (mas[j + 1] < 0)
				{
					int temp;
					temp = mas[j];
					mas[j] = mas[j + 1];
					mas[j + 1] = temp;
				}
	ArrayOutput(mas);

	cout << "\n\n";
}


int main()
{
	int Num, i;
	for (i = 0; i <= 8; i++)
	{
		cout << "chose 11, 46, 81, 116, 151, 186: ";
		cin >> Num;
		switch (Num)
		{
		case 11:
			Task11();
			break;
		case 46:
			Task46();
			break;
		case 81:
			Task81();
			break;
		case 116:
			Task116();
			break;
		case 151:
			Task151();
			break;
		case 186:
			Task186();
			break;
		case 000:
			TaskVariant();
			break;

		default:
			break;
		}
	}
}
