#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <time.h>
#include <Windows.h>

using namespace std;
#define a9 9
#define a7 7
#define a16 16
int main()
{
	setlocale(LC_ALL, "Russian");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int  N;
	srand(time(NULL));

	do
	{
		cout << "\t\t----Введите номер задания: ";
		cin >> N;
		cout << endl;
		switch (N)
		{
		case 1:
			/*1.Ввести два массива действительных чисел, состоящих из 9 и 7 элементов. Сформировать третий массив из
			упорядоченных по возрастанию значений обоих массивов*/
		{
			float a[a9] = { 0 }, b[a7] = { 0 }, c[a16] = { 0 };
			cout << "Массив из 9 элементов:" << endl;
			for (int i = 0; i < a9; i++)
			{
				a[i] = rand() % 50 * 0.22;
				c[i] = a[i];
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
			cout << "Массив из 7 элементов:" << endl;
			for (int i = 0; i < a7; i++)
			{
				b[i] = rand() % 50 * 0.22;
				c[i + 9] = b[i];
				cout << "[" << i << "]=" << b[i] << endl;
			}
			cout << endl;

			for (int i = 0; i < a16; i++)
			{
				// для всех элементов после i-ого
				for (int j = (a16 - 1); j > i; j--)
				{
					// если текущий элемент меньше предыдущего
					if (c[j - 1] > c[j])
					{
						// меняем их местами
						float temp = c[j - 1];
						c[j - 1] = c[j];
						c[j] = temp;
					}
				}
			}
			cout << "Массив из упорядоченных по возрастанию значений обоих массивов" << endl;
			for (int i = 0; i <= a16 - 1; i++)
			{
				cout << "[" << i << "] = " << c[i] << endl;
			}
		}
		cout << endl;
		break;

		case 2:
			/*2.В заданном целочисленном массиве R(9) определить индекс наибольшего из нечетных по значению положительных
			элементов*/
		{
			const int size = 9;
			int r[size] = { 0 }, index = 0, max = 0, cnt = 0;
			cout << "Массив R(9):" << endl;
			for (int i = 0; i < size; i++)
			{
				r[i] = -5 + rand() % 20;
				if (r[i] > max && r[i] % 2 != 0)
				{
					max = r[i];
					index = i; SetConsoleTextAttribute(hConsole, 12);
					cnt++;
				}
				cout << "[" << i << "] = " << r[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << endl;
			if (cnt == 0) { cout << "\tИскомый элемент отсутствует" << endl; }
			else
				cout << "\tИндекс искомого элемента : [" << index << "]" << endl;
		}
		cout << endl;
		break;

		case 3:
			/*3.Ввести массив, состоящий из 9 элементов (девять двузначных чисел) целого типа. Получить новый массив,
			состоящий из сумм цифр элементов исходного массива*/
		{
			const int size = 9;
			int a[size], b[size], sum = 0;
			cout << "Исходный массив: " << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 90 + 10;
				b[i] = (a[i] / 10) + (a[i] % 10);
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
			cout << "Массив, состоящий из сумм цифр элементов исходного массива : " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "[" << i << "]=" << b[i] << endl;
			}

		}
		cout << endl;
		break;

		case 4:
			/*4.Даны действительные числа c1, c2, …, cn. Найти произведение суммы чисел с четными индексами и суммы чисел
			с нечетными индексами.*/
		{
			const int size = 10;
			float a[size], proizv, sum1 = 0, sum2 = 0;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 20 * 0.22;
				if (i % 2 == 0)
				{
					sum1 += a[i];
					SetConsoleTextAttribute(hConsole, 10);
				}
				else
				{
					sum2 += a[i];
					SetConsoleTextAttribute(hConsole, 14);
				}
				cout << "[" << i << "]=" << a[i] << endl;
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << endl;
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Сумма чисел с четными индексам = " << sum1 << endl;
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Сумма чисел с нечетными индексам = " << sum2 << endl;
			SetConsoleTextAttribute(hConsole, 7);
			proizv = sum1*sum2;
			cout << "Произведение суммы чисел = " << proizv << endl;

		}
		cout << endl;
		break;

		case 5:
			/*5.Ввести массив, состоящий из 14 элементов действительного типа. Поменять местами первую половину со второй.
			Определить количество произведенных при этом перестановок.*/
		{
			const int size = 14;
			float a[size], cnt = 0, temp = 0;

			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
			for (int i = 0; i < size / 2; i++)
			{
				temp = a[i];
				a[i] = a[i + size / 2];
				a[i + size / 2] = temp;

			}
			cout << "Измененный массив" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "[" << i << "]=" << a[i] << endl;
				cnt++;
			}
			cout << endl;
			cout << "Количество перестановок = " << cnt << endl;
		}
		cout << endl;
		break;

		case 6:
			/*6.Определить количество локальных максимумов в заданном числовом массиве. (Локальный максимум в числовом
			массиве – это последовательность трех рядом стоящих чисел, в которой среднее число больше стоящих слева и
			справа от него).*/
		{
			const int size = 10;
			int a[size], cnt = 0;
			cout << "Массив: " << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
			}
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				if (i != 0 && a[i] > a[i + 1] && a[i] > a[i - 1] && i != size - 1)
				{
					SetConsoleTextAttribute(hConsole, 12);
					cnt++;
				}
				cout << "[" << i << "]=" << a[i] << " ";
				SetConsoleTextAttribute(hConsole, 7);
			}
			cout << endl << endl;
			cout << "Количество локальных максимумов в заданном числовом массиве = " << cnt << endl;
		}
		cout << endl;
		break;

		case 7:
			/*7.В заданном числовом массиве определить и вывести индексы последовательностей чисел, которые монотонно
			убывают (каждое следующее число меньше предыдущего).*/
		{
			const int size = 10;
			int a[size], index = 0;

			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				cout << "[" << i << "]=" << a[i] << endl;
			}
			for (int i = 0; i < size-1; i++)
			{
				index = i;
				while (a[i] > a[i + 1]&& i!=9)
				{
					i++;
				}
				if (index != i)
				
					{
					cout << "с [" << index << "] по " << "[" << i << "]; " << " ";
					}
			}
		}
		break;

		case 8:
			/*8.Ввести массив, состоящий из 10 элементов (десять двузначных чисел) целого типа. Получить новый массив,
			состоящий из разностей цифр элементов исходного массива.*/
		{
			const int size = 10;
			int a[size], b[size], sum = 0;
			cout << "Исходный массив: " << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 90 + 10;
				b[i] = (a[i] / 10) - (a[i] % 10);
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
			cout << "Массив, состоящий из разностей цифр элементов исходного массива : " << endl;

			for (int i = 0; i < size; i++)
			{
				cout << "[" << i << "]=" << b[i] << endl;
			}
		}
		cout << endl;
		break;

		case 9:
			/*9.Задан целочисленный массив. Определить количество участков массива, на котором элементы монотонно
			возрастают (каждое следующее число больше предыдущего)*/
		{
			const int size = 10;
			int cnt = 0, temp = 0, a[size];
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99;
				cout << "[" << i << "]=" << a[i] << endl;
			}
			cout << endl;
			for (int i = 0; i < size; i++)
			{
				temp = i;
				while (a[i] < a[i + 1])
				{
					i++;
				}
				if (temp != i)
				{
					cnt++;
				}
			}
			cout << "Количество участков массива, на котором элементы монотонно возрастают = " << cnt << endl;
		}
		cout << endl;
		break;

		case 10:
			/*10.Ввести два массива действительных чисел. Определить максимальные элементы в каждом массиве и поменять
			их местами.*/
		{
			const int size = 10;
			float a[size], b[size], temp;
			int max1 = 0, max2 = 0;
			cout << "\t\tДо замены: " << endl;
			cout << "1-й массив\t\t 2-й массив" << endl;
			for (int i = 0; i < size; i++)
			{
				a[i] = rand() % 99 * 0.22;
				b[i] = rand() % 99 * 0.22;
				if (a[i] > a[max1])
				{
					max1 = i;
				}
				if (b[i] > b[max2])
				{
					max2 = i;
				}
				cout << "[" << i << "]=" << a[i] << " \t\t " << "[" << i << "]=" << b[i] << endl;
			}
			cout << endl;
			cout << "Максимальный элемент 1-го массива [" << max1 << "]=" << a[max1] << endl;
			cout << "Максимальный элемент 2-го массива [" << max2 << "]=" << b[max2] << endl;
			temp = a[max1];
			a[max1] = b[max2];
			b[max2] = temp;

			cout << "После замены: " << endl;
			cout << "1-й массив\t\t 2-й массив" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "[" << i << "]=" << a[i] << " \t\t " << "[" << i << "]=" << b[i] << endl;
			}
		}
		break;
		default: {cout << "Задания с таким номером не существует" << endl; }
		}
	} while (N > 0 && N < 11);
	cout << "\t\t\t\t\tКОНЕЦ." << endl;
	system("pause");
}