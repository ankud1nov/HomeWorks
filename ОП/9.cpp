//Сделал Федоров Сергей
//Основной файл программы (с функцией main)
// Тема: Препроцессор
// Домашнее задание
// Задание 1:
// Создать проект в котором :
// 1. создать три файла: ( function.h , function.cpp , prog.cpp )
// 2. в файле function.cpp необходимо написать следующие функции для работы с массивом
// данных:
// а) функцию для заполнения массива случайными значениями ;
// б) функцию для вывода значений массива на консоль ;
// в) функцию для поиска минимального элемента;
// г) функцию для поиска максимального элемента;
// д) функцию для сортировки ;
// е) функцию для редактирования значения массива.
// Данные функции необходимо написать для работы с массивом целых, действительных и
// символьных значений. (Для каждого типа написать отдельную функцию) .
// 3. в файле function.h нужно:
// а) описать прототипы всех функций;
// 4. в файле prog.cpp нужно :
// а) в функции main вызвать все функции через переозначеные( обобщенные ) имена из файла
// function.h ( show ( ))
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include "function.h"
using namespace std;

//////////////////////////////////////////////// intовый массив
///////////////////////////////////////////////////////////////

// Задание 2:
// С помощью директивы #define написать следующие макросы:
//  Нахождение меньшего из двух чисел;
//  Нахождение большего из двух чисел;
//  Возведение числа в квадрат;
//  Возведение числа в степень;
//  Проверка числа на четность;
//  Проверка числа на нечетность;
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define step(x, y) (x * y)
#define kvadr(a, b) ((b) = (a) * (a))
#define chetn(a) ((a) % (2) == (0))
#define nechetn(a) ((a) % (2) != (0))
///////////////////////////////////////////////////////////////

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");

	const int chi1 = 15;
	int arr1[chi1];

	const int chi2 = 10;
	double arr2[chi2];

	const int chi3 = 5;
	char arr3[chi3];

	cout << "ЦЕЛОЧИСЛЕННЫЙ МАССИВ " << endl;

	cout << "Исходный массив " << endl;
	initMass(arr1, chi1);
	showMass(arr1, chi1);
	cout << "Отсортированный массив " << endl;
	sortMass(arr1, chi1);
	showMass(arr1, chi1);
	cout << "\nМинимальное значение массива " << endl;
	minMass(arr1, chi1);
	cout << "\nМаксимальное значение массива " << endl;
	maxMass(arr1, chi1);
	cout << "Редактируйте массив " << endl;
	editMass(arr1, chi1);
	cout << "Отредактированный массив " << endl;
	showMass(arr1, chi1);
	cout << endl << endl;

	cout << "ДВОЙНОЙ МАССИВ " << endl;

	cout << "Исходный массив " << endl;
	initMass(arr2, chi2);
	showMass(arr2, chi2);
	cout << "Отсортированный массив " << endl;
	sortMass(arr2, chi2);
	showMass(arr2, chi2);
	cout << "\nМинимальное значение массива " << endl;
	minMass(arr2, chi2);
	cout << "\nМаксимальное значение массива " << endl;
	maxMass(arr2, chi2);
	cout << "Редактируйте массив " << endl;
	editMass(arr2, chi2);
	cout << "Отредактированный массив " << endl;
	showMass(arr2, chi2);
	cout << endl << endl;

	cout << "СИМВОЛЬНЫЙ МАССИВ " << endl;

	cout << "Исходный массив " << endl;
	initMass(arr3, chi3);
	showMass(arr3, chi3);
	cout << "Отсортированный массив " << endl;
	sortMass(arr3, chi3);
	showMass(arr3, chi3);
	cout << "\nМинимальное значение массива " << endl;
	minMass(arr3, chi3);
	cout << "\nМаксимальное значение массива " << endl;
	maxMass(arr3, chi3);
	cout << "Редактируйте массив " << endl;
	editMass(arr3, chi3);
	cout << "Отредактированный массив " << endl;
	showMass(arr3, chi3);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//function.cpp
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

void initMass(int arr[], const int chi) //инициализация массива
{

	for (int i = 0; i < chi; i++)
	{
		arr[i] = rand() % 15;
	}
}

void showMass(int arr[], const int chi) //вывод массва на экарн
{

	for (int i = 0; i < chi; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sortMass(int arr[], const int chi) //сортировка массива по возрастанию
{
	for (int i = 0; i < chi; ++i)
	{
		for (int j = 0; j < chi - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void minMass(int arr[], const int chi) //минимальное значение массива
{
	int min = 1;

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << min << endl;
}

void maxMass(int arr[], const int chi) //максимальное значение массива
{
	int max = 0;

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max << endl;
}

void editMass(int arr[], int chi) //редактирование массива
{
	int edit;
	cout << "Введите номер элемента массива: ";
	cin >> edit;
	cout << "\nВы выбрали элемент массива: " << arr[edit - 1] << endl;

	cout << "Введите новый элемент массива: ";
	cin >> arr[edit - 1];
}


//////////////////////////////////////////////// doubleовый массив
//////////////////////////////////////////////////////////////////

void initMass(double arr[], const int chi) //инициализация массива
{

	for (int i = 0; i < chi; i++)
	{
		arr[i] = (rand() % 1500) / 100.0 + (rand()%999/1000);
	}
}

void showMass(double arr[], const int chi) //вывод массва на экарн
{

	for (int i = 0; i < chi; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sortMass(double arr[], const int chi) //сортировка массива по возрастанию
{

	for (int i = 0; i < chi; ++i)
	{
		for (int j = 0; j < chi - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void minMass(double arr[], const int chi) //минимальное значение массива
{
	double min = arr[0];

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << min << endl;
}

void maxMass(double arr[], const int chi) //максимальное значение массива
{
	double max = 0;

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max << endl;
}

void editMass(double arr[], int chi) //редактирование массива
{
	int edit;
	cout << "Введите номер элемента массива: ";
	cin >> edit;
	cout << "\nВы выбрали элемент массива: " << arr[edit - 1] << endl;

	cout << "Введите новый элемент массива: ";
	cin >> arr[edit - 1];
}

//////////////////////////////////////////////// charовый массив
////////////////////////////////////////////////////////////////

void initMass(char arr[], const int chi)//инициализация массива
{

	for (int i = 0; i < chi; i++)
	{
		arr[i] = rand() % 15;
	}
}

void showMass(char arr[], const int chi) //вывод массва на экарн
{

	for (int i = 0; i < chi; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void sortMass(char arr[], const int chi) //сортировка массива по возрастанию
{

	for (int i = 0; i < chi; ++i)
	{
		for (int j = 0; j < chi - 1; ++j)
		{
			if (arr[j] < arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void minMass(char arr[], const int chi) //минимальное значение массива
{
	char min = 1;

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	cout << min << endl;
}

void maxMass(char arr[], const int chi) //максимальное значение массива
{
	char max = 0;

	for (int i = 0; i < chi; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	cout << max << endl;
}

void editMass(char arr[], int chi) //редактирование массива
{
	char edit;
	cout << "Введите номер элемента массива: ";
	cin >> edit;
	cout << "\nВы выбрали элемент массива: " << arr[edit - 1] << endl;

	cout << "Введите новый элемент массива: ";
	cin >> arr[edit - 1];
}
//function.h
#pragma once

void initMass(int arr[], const int chi);
void showMass(int arr[], const int chi); //вывод массва на экарн
void sortMass(int arr[], const int chi);
void minMass(int arr[], const int chi);
void maxMass(int arr[], const int chi);
void editMass(int arr[], int chi);
//////////////////////////////////////////////// doubleовый массив
//////////////////////////////////////////////////////////////////
void initMass(double arr[], const int chi); //инициализация массива
void showMass(double arr[], const int chi); //вывод массва на экарн
void sortMass(double arr[], const int chi); //сортировка массива по возрастанию
void minMass(double arr[], const int chi); //минимальное значение массива
void maxMass(double arr[], const int chi); //максимальное значение массива
void editMass(double arr[], int chi); //редактирование массива
//////////////////////////////////////////////// charовый массив
////////////////////////////////////////////////////////////////
void initMass(char arr[], const int chi);//инициализация массива
void showMass(char arr[], const int chi);//вывод массва на экарн
void sortMass(char arr[], const int chi); //сортировка массива по возрастанию
void minMass(char arr[], const int chi); //минимальное значение массива
void maxMass(char arr[], const int chi); //максимальное значение массива
void editMass(char arr[], int chi); //редактирование массива
