// Тема: Многомерные динамические массивы
// Домашнее задание
// Задание 1:
// Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.

// Задание 2:
// Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.

#include <iostream>
using namespace std;

void fillMassiv(int** pArray, int rowCount, int columnCount);
void printArray(int** pArray, int rowCount, int columnCount);
void addColumn(int** pArray, int rowCount, int columnCount, int index);
void deleteColumn(int** pArray, int rowCount, int columnCount, int index);

int main()
{
    setlocale(LC_ALL, "Rus");

    int const rowCount = 3;
    int const startColumnCount = 10;
    int columnCount = 3;
    int userIndex;
    int** simpleArray = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        simpleArray[i] = new int[startColumnCount];
    }
    fillMassiv(simpleArray, rowCount, columnCount);
    cout << "Стартовый массив: " << endl;
    printArray(simpleArray, rowCount, columnCount);
    //столбец можно добавить как в середину, так и в конец массива. поэтому 0...3
    cout << "Введите номер столбца от 0 до " << columnCount << " какой столбец вы хотите добавить? ";
    cin >> userIndex;
    if (userIndex >= 0 && userIndex <= columnCount)
    {
        columnCount++;
        addColumn(simpleArray, rowCount, columnCount, userIndex);
        printArray(simpleArray, rowCount, columnCount);
    }
    else
    {
        cout << "Не верное значение" << endl;
    }
    //удаление столбца
    cout << "Введите номер столбца от 0 до " << columnCount - 1 << " какой столбец вы ходите удалить? ";
    cin >> userIndex;
    if (userIndex >= 0 && userIndex < columnCount)
    {
        deleteColumn(simpleArray, rowCount, columnCount, userIndex);
        columnCount--;
        printArray(simpleArray, rowCount, columnCount);
    }
    else
    {
        cout << "Не верное значение" << endl;
    }
    //удаление массива
    for (int i = 0; i < rowCount; i++)
    {
        delete[] simpleArray[i];
    }
    delete[] simpleArray;
}
//инициализация массива
void fillMassiv(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    int value = 1;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            pArray[i][j] = value;
            value++;
        }
    }
}
//вывод массива на экран
void printArray(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            cout << pArray[i][j] << " ";
        }
        cout << endl;
    }
}
//добавление столбца
void addColumn(int** pArray, int rowCount, int columnCount, int index)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            //сдвигаем вправо значения
            if (j == index)
            {
                for (int k = columnCount; k > index; k--)
                {
                    pArray[i][k] = pArray[i][k - 1];
                }
                //заполняем вставленный столбец 0ми
                pArray[i][j] = 0;
            }
        }
    }
}
//удаление столбца
void deleteColumn(int** pArray, int rowCount, int columnCount, int index)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        //j < columnCount, чтобы в крайний правый столбец записался мусор,
        //который до этого был справа, а не осталось правильное значение как до удаления.
        for (int j = index; j < columnCount; j++)
        {
            pArray[i][j] = pArray[i][j + 1];
        }
    }
}

  
// Задание 3:
// Дана матрица порядка MxN (M строк, N столбцов). Необходимо заполнить ее значениями и
// написать функцию, осуществляющую циклический сдвиг строк и/или столбцов массива
// указанное количество раз и в указанную сторону.

#include <iostream>
#include <iomanip>

using namespace std;

enum UserChoice
{
    Exit = 0,
    MoveRowsDown = 1,
    MoveRowsUp = 2,
    MoveColumnsLeft = 3,
    MoveColumnsRight = 4,
};

void fillMassiv(int** pArray, int rowCount, int columnCount);
void printArray(int** pArray, int rowCount, int columnCount);
void moveMatrix(int** pArray, int rowCount, int columnCount);

int main()
{
    setlocale(LC_ALL, "Rus");

    int rowCount;
    int columnCount;
    cout << "Введите количество строк (1...10): ";
    cin >> rowCount;

    if (rowCount <= 0 || rowCount > 10)
    {
        cout << "Не верное значение количества строк" << endl;
        return 1;
    }

    cout << "Введите количество столбцов (1...10): ";
    cin >> columnCount;

    if (columnCount <= 0 || columnCount > 10)
    {
        cout << "Не верное значение количества столбцов" << endl;
        return 1;
    }

    int** simpleArray = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
    {
        simpleArray[i] = new int[columnCount];
    }
    //заполнение и вывод на экран
    fillMassiv(simpleArray, rowCount, columnCount);
    cout << "Стартовый массив: " << endl;
    printArray(simpleArray, rowCount, columnCount);
    //работа с массивом
    moveMatrix(simpleArray, rowCount, columnCount);

    //удаление массива
    for (int i = 0; i < rowCount; i++)
    {
        delete[] simpleArray[i];
    }
    delete[] simpleArray;
}
//инициализация массива
void fillMassiv(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    int value = 1;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            pArray[i][j] = value;
            value++;
        }
    }
}
//вывод массива на экран
void printArray(int** pArray, int rowCount, int columnCount)
{
    if (pArray == nullptr)
    {
        cout << "Ошибка!" << endl;
        return;
    }

    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            cout << setw(3) << pArray[i][j] << " ";
        }
        cout << endl;
    }
}
//сдвиг массива
void moveMatrix(int** pArray, int rowCount, int columnCount)
{
    int intUserChoice;
    enum UserChoice userChoice;
    int originalMovesCount = 0;
    int changedMovesCount = 0;
    int buffer;

    cout << "Меню?" << endl <<
        "0 = Выход" << endl <<
        "1 = Переместить строки вниз" << endl <<
        "2 = Переместить строки вверх" << endl <<
        "3 = Сдвиг столбца влево" << endl <<
        "4 = Сдвиг столбца вправо" << endl;
    cin >> intUserChoice;
    userChoice = (enum UserChoice)intUserChoice;

    switch (userChoice)
    {
    case Exit:
        cout << "Вы хотите выйти?" << endl;
        break;
    case MoveRowsDown:
    case MoveRowsUp:
    case MoveColumnsLeft:
    case MoveColumnsRight:
        cout << "На сколько позиций?" << endl;
        cin >> originalMovesCount;
        if (originalMovesCount <= 0)
        {
            cout << "Значение должно быть больше нуля!" << endl;
            return;
        }

        changedMovesCount = originalMovesCount;
        //для ускорения сдвига
        if ((changedMovesCount >= rowCount && userChoice == MoveRowsDown) ||
            (changedMovesCount >= rowCount && userChoice == MoveRowsUp))
        {
            changedMovesCount = changedMovesCount % rowCount;
        }
        else if ((changedMovesCount >= columnCount && userChoice == MoveColumnsLeft) ||
            (changedMovesCount >= columnCount && userChoice == MoveColumnsRight))
        {
            changedMovesCount = changedMovesCount % columnCount;
        }
        //сам сдвиг
        while (changedMovesCount != 0)
        {
            switch (userChoice)
            {
            case MoveRowsDown:
                for (int column = 0; column < columnCount; column++)
                {
                    buffer = pArray[rowCount - 1][column];
                    for (int row = rowCount - 1; row > 0; row--)
                    {
                        pArray[row][column] = pArray[row - 1][column];
                    }
                    pArray[0][column] = buffer;
                }
                break;
            case MoveRowsUp:
                for (int column = 0; column < columnCount; column++)
                {
                    buffer = pArray[0][column];
                    for (int row = 0; row < rowCount - 1; row++)
                    {
                        pArray[row][column] = pArray[row + 1][column];
                    }
                    pArray[rowCount - 1][column] = buffer;
                }
                break;
            case MoveColumnsLeft:
                for (int row = 0; row < rowCount; row++)
                {
                    buffer = pArray[row][0];
                    for (int column = 0; column < columnCount - 1; column++)
                    {
                        pArray[row][column] = pArray[row][column + 1];
                    }
                    pArray[row][columnCount - 1] = buffer;
                }
                break;
            case MoveColumnsRight:
                for (int row = 0; row < rowCount; row++)
                {
                    buffer = pArray[row][columnCount - 1];
                    for (int column = columnCount - 1; column > 0; column--)
                    {
                        pArray[row][column] = pArray[row][column - 1];
                    }
                    pArray[row][0] = buffer;
                }
                break;
            default:
                cout << "Ошибка!" << endl;
                break;
            }
            changedMovesCount--;
        }
        //конец сдвига
        printArray(pArray, rowCount, columnCount);
        break;
    default:
        cout << "Не верное значение" << endl;
        break;
    }
} 
  
// Задание 4:
// Транспонирование матрицы – это операция, после которой столбцы прежней матрицы
// становятся строками, а строки столбцами. Напишите функцию транспонирования матрицы.

#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

	float A[5][4], TA[4][5];
	int i, j;

	cout << "Стартовый массив" << endl;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			A[i][j] = rand() % 10;
			cout << " " << A[i][j];
		}
		cout << "\n" << " ";
	}
	cout << "\n";

	cout << "Транспортированный массив" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			TA[i][j] = A[j][i];
			cout << " " << TA[i][j];
		}
		cout << "\n" << " ";
	}
}
 
  
// Задание 5:
// Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон.
// Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных.

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 3;
struct directory {

	char name[100];
	char telefon[100];
};
directory L[N];
// поиск абонента по телефону или имени
int serch()//поиск абонента по телефону или имени

{
	char name[100];
	cout << " \n\n\nВведите имя или телефон для поиска\t" << endl;
	cin >> name;
	cout << " \nРезултат поиска\t" << name;
	int i;
	for (i = 0; i < N; i++)
	{
		if (!(strcmp(name, L[i].name))) { break; }
		if (!(strcmp(name, L[i].telefon))) { break; }
	}
	if (i == N) { return -1; }
	cout << "\n Имя\t" << L[i].name;

	cout << "\n Телефон\t" << L[i].telefon;
	return i;
}
int main()
{
	setlocale(LC_ALL, "Rus");

	char y; int num = 0;
	//////////////////////////////////////
	for (int i = 0; i < N; i++)

	{
		cout << "\n Введите имя\t";
		cin >> L[i].name;
		cout << "\n Введите телефон\t";
		cin >> L[i].telefon;
	}

	for (int i = 0; i < N; i++)

	{
		cout << "\n  Имя\t" << L[i].name;

		cout << "\n Телефон\t" << L[i].telefon;
	}
	//////////////////////////////////////////////////
	num = serch();

	while (num >= 0)
	{

		cin >> y;
		if (y == 'y' || y == 'Y')
		{
			cout << "\n Введите имя\t";
			cin >> L[num].name;
			cout << "\n Введите телефон\t";
			cin >> L[num].telefon;
		}
		else
		{
			break;
		}
		for (int i = 0; i < N; i++)

		{
			cout << "\n  Имя\t" << L[i].name;

			cout << "\n Телефон\t" << L[i].telefon;
		}
	}
	return 0;
}


// Тема: Структуры
// Домашнее задание
// Задание 1:
// Создайте структуру, описывающую комплексное число. Реализуйте арифметические операции
// с комплексными числами: сумму, разность, умножение, деление.

#include <iostream>
using namespace std;

struct ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    ComplexNumber plus(ComplexNumber&);
    ComplexNumber minus(ComplexNumber&);
    ComplexNumber multiply(ComplexNumber&);
    ComplexNumber divide(ComplexNumber&);
    void print();
    void setA(double a);
    void setB(double b);
    void read();
private:
    double a, b;
};

ComplexNumber::ComplexNumber() {
    a = 0;
    b = 0;
}

ComplexNumber::ComplexNumber(double a, double b) {
    this->a = a;
    this->b = b;
}

void ComplexNumber::setA(double a) {
    this->a = a;
}

void ComplexNumber::setB(double b) {
    this->b = b;
}

void ComplexNumber::read() {
    cout << "Введите вещественную часть: ";
    cin >> a;
    cout << "Введите мнимую часть: ";
    cin >> b;
}

void ComplexNumber::print() {
    cout << a << (b > 0 ? "+" : +"") << b << "*i\n";
}

ComplexNumber ComplexNumber::plus(ComplexNumber& right) {
    return ComplexNumber(this->a + right.a, this->b + right.b);
}

ComplexNumber ComplexNumber::minus(ComplexNumber& right) {
    return ComplexNumber(this->a - right.a, this->b - right.b);
}

ComplexNumber ComplexNumber::multiply(ComplexNumber& right) {
    double a = this->a,
        b = this->b,
        c = right.a,
        d = right.b;
    return ComplexNumber(a * c - b * d, b * c + a * d);
}

ComplexNumber ComplexNumber::divide(ComplexNumber& right) {
    double a = this->a,
        b = this->b,
        c = right.a,
        d = right.b;
    double resultA = (a * c + b * d) / (c * c + d * d),
        resultB = (b * c - a * d) / (c * c + d * d);
    return ComplexNumber(resultA, resultB);
}

int menu() {
    int answer;
    cout << "\n1 - Сложить\n"
        << "2 - Вычесть\n"
        << "3 - Умножить\n"
        << "4 - Разделить\n"
        << "0 - Выход из программы\n"
        << "> ";
    cin >> answer;
    cout << endl;
    return answer;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    ComplexNumber a, b, result;
    int answer;
    do {
        answer = menu();
        if (answer != 0) {
            cout << "Число А\n";
            a.read();
            cout << "Число B\n";
            b.read();
        }
        switch (answer) {
        case 0:
            break;
        case 1:
            result = a.plus(b);
            break;
        case 2:
            result = a.minus(b);
            break;
        case 3:
            result = a.multiply(b);
            break;
        case 4:
            result = a.divide(b);
            break;
        }
        if (answer != 0) {
            cout << "Результат: ";
            result.print();
        }
    } while (answer != 0);
}

  
// Задание 2:
// Реализовать структуру «Автомобиль» (длина, клиренс (высота посадки), объем двигателя,
// мощность двигателя, диаметр колес, цвет, тип коробки передач). Создайте функции для задания
// значений, отображения значений, поиска значений.

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 3;
struct car {

	float dlina;
	float clirenc;
	float V;
	float R;
	char color[100];
	char AT[100];
};
car avto[N];
int serch_i()
{
	int k1;
	for (k1 = 0; k1 < N; k1++)
	{

		if (!avto[k1].dlina) { break; }
	}

	return k1;
}
void print1(int i)
{

	cout << "\nВведите длину\t" << avto[i].dlina;
	cout << "\nВведите клиренс\t" << avto[i].clirenc;
	cout << "\nВведите обьем двигателя\t" << avto[i].V;
	cout << "\nВведите мощность двигателя\t" << avto[i].R;
	cout << "\nВведите цвет автомобиля\t" << avto[i].color;
	cout << "\nВведите тип трнсмиссии\t" << avto[i].AT;
}
void enter(int i)
{
	cout << "\nВведите длину\t";
	cin >> avto[i].dlina;
	cout << "\nВведите клиренс\t";
	cin >> avto[i].clirenc;
	cout << "\nВведите обьем двигателя\t";
	cin >> avto[i].V;
	cout << "\nВведите мощность двигателя\t";
	cin >> avto[i].R;
	cout << "\nВведите цвет автомобиля\t";
	cin >> avto[i].color;
	cout << "\nВведите тип трнсмиссии\t";
	cin >> avto[i].AT;
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		cout << "\nХарактеристики вашего автомобиля:";
		cout << "\nВведите длину\t" << avto[i].dlina;
		cout << "\nВведите клиренс\t" << avto[i].clirenc;
		cout << "\nВведите обьем двигателя\t" << setw(12) << avto[i].V;
		cout << "\nВведите мощность двигателя\t" << setw(12) << avto[i].R;
		cout << "\nВведите цвет автомобиля\t" << avto[i].color;
		cout << "\nВведите тип трнсмиссии\t" << avto[i].AT;
	}

}

void serch(int dlina)
{
	int i;
	for (i = 0; i, N; i++)
		if (avto[i].dlina == dlina) { break; }
	print1(i);
}
int main()
{
	setlocale(LC_ALL, "Rus");

	char k = 'q';
	int k1;

	for (int i = 0; i < N; i++)
	{
		cout << "\nАвтомобиль № " << i + 1;
		enter(i);
		cout << "\n Если вы хотите продолжить, нажмите q, чтобы остановить ввод, нажмите любую клавишу.";
		cin >> k;
		if (k != 'q') { break; }
	}

	cout << "\n Введите длину указанного автомобиля ";
	cin >> k1;
	serch(k1);

	//enter(serch_i());
//print();
	return 0;
}


// Задание 3:
// Разработайте программу «Библиотека». Создайте структуру «Книга» (название, автор,
// издательство, жанр). Создайте массив из 10 книг. Реализуйте для него следующие возможности:
// Редактировать книгу
// Печать всех книг
// Поиск книг по автору
// Поиск книги по названию
// Сортировка массива по названию книг (по желанию)
// Сортировка массива по автору (по желанию)
// Сортировка массива по издательству (по желанию)

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];
struct library
{
	char title[100];
	char author[100];
	char pub_house[100];
	char genre[100];
	void editBook(char _title[100], char _autor[100], char _pub_house[100], char _genre[100]) {
		for (size_t i = 0; i < 100; i++)
		{
			title[i] = _title[i];
		}
	}
	void Show()
	{
		cout << title;
	}
};
library L[N];
void liun() //заполнение нулями
{
	for (int t = 0; t < N; t++)
		L[t].title[0] = '\0';
}

char menu()//выбор меню, проверка выбора, через функцию strchr
{
	char ch;
	do {

		cout << "\n Введите'q' для поиска по редакции";
		cout << "\n Введите'e' для печати всех книг";
		cout << "\n Введите'u' для поиска книг по автору";
		cout << "\n Введите'd' для поиска по названию";
		cout << "\n'z' Если вы хотите выйти из программы нажмите пробел";
		cout << endl;
		cin >> ch;
		if (ch == 'z') { return ch; }
	} while (!strchr("eduq ", tolower(ch)));
	return ch;
}
void enter()//ввод значений
{

	int t = 0; char povtor = 'y';
	do {
		for (t = 0; t < N; t++)
			if (!L[t].title[0]) { break; }
		if (t == N) { cout << "Ошибка"; return; }
		cout << "\nРедакция\t";
		cin >> L[t].title;
		cout << "\nАвтор\t";
		cin >> L[t].author;
		cout << "\nИздательство\t";
		cin >> L[t].pub_house;
		cout << "\nenter  Жанр\t";
		cin >> L[t].genre;
		cout << "\nЕсли вы хотите ввести ещё нажмите 'Y'\t";
		cin >> povtor;
	} while ((povtor) == 'Y' || povtor == 'y');
}
void print()//Печать всех книг
{
	int t = 0;
	for (t = 0; t < N; t++)
	{
		if (L[t].title[0] == '\0') { break; }
		cout << "\n" << t + 1 << "Книга" << endl;
		cout << "\nРедакция\t" << L[t].title;
		cout << "\nАвтор\t" << L[t].author;
		cout << "\nИздательство\t" << L[t].pub_house;
		cout << "\nЖанр\t" << L[t].genre << endl;
	}
}
void Search_title()//фукция поиска по названию книги через функцию strcmp
{
	char name[100];
	cout << "\nПоиск";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].title))) { break; }
	if (t == N) { cout << "\nНет такой книги"; }
	else
	{
		cout << "\n Редакция" << setw(8) << L[t].title;
		cout << "\n Автор\t" << setw(10) << L[t].author;
		cout << "\n Издательство\t" << setw(2) << L[t].pub_house;
		cout << "\n Жанр\t" << setw(10) << L[t].genre << endl;
	}
}
void Search_author()//поиск книги по автору через функцию strcmp
{

	char name[100];
	cout << "\nПоиск по автору";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].author))) { break; }
	if (t == N) { cout << "\nНет такой книги"; }
	cout << "\n Редакция" << setw(8) << L[t].title;
	cout << "\n Автор\t" << setw(10) << L[t].author;
	cout << "\n Издательство\t" << setw(2) << L[t].pub_house;
	cout << "\n  Жанр\t" << setw(10) << L[t].genre << endl;
}
void edit_book()
{

	char name[100];
	cout << "\nПоиск";
	cin >> (name);
	int t;
	for (t = 0; t < N; t++)
		if (!(strcmp(name, L[t].title))) { break; }
	if (t == N) { cout << "Нет такой книги"; return; }
	cout << "\nРедакция\t";
	cin >> L[t].title;
	cout << "\nАвтор\t";
	cin >> L[t].author;
	cout << "\nИздательсвто\t";
	cin >> L[t].pub_house;
	cout << "\nЖанр\t";
	cin >> L[t].genre;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	L[0].editBook();
	for (size_t i = 0; i < 2; i++)
	{
		L[i].Show();
	}
	char choice; char vyxod = 'a';
	liun();//присваеваем нули всему массиву
	enter();// осуществляем поиск свободного элемента и делаем ввод данных

	do {

		choice = menu();// выбор действия которое необходимо провести

		switch (choice)
		{
		case 'e':

			print();

			break;
		case 'd':
			Search_title();
			break;
		case 'u':
			Search_author();
			break;
		case 'q':
			edit_book();
			break;
		case 'z':
			vyxod = 'z';

			break;
		default:
			vyxod = 'z';

			break;
		}
	} while (!((vyxod) == 'z'));

	return 0;
}


// Задание 4:
// Реализовать структуру «Машина» (цвет, модель, номер). Номер машины может представлять из
// себя или пятизначный номер или слово до 8 символов.
// Рекомендации: номер реализовать как объединение.
// Создать экземпляр структуры «Машина» и реализовать для него следующие функции:
// Заполнение машины
// Печать машины
// Создать массив из 10 экземпляров структуры «Машина» и реализовать для него следующие
// функции:
// Редактировать машину
// Печать всех машин
// Поиск машины по номеру

#include "iostream"
#include "tchar.h"
#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "math.h"
#include "iomanip"
using namespace std;
const size_t N = 2;
typedef char T[N];

union MyUn
{
	char h[7];
	int i;
};
MyUn number[N];

struct avto
{
	MyUn number[N];
	char color[100];
	char model[100];
	int flag;
};
avto myavto[N];

void liun() //заполнение нулями
{
	for (int t = 0; t < N; t++)
		myavto[t].number[t].h[0] = '\0';
}
//функция strlen
int StringToNumber(char* str)//функция strlen
{
	int k1 = 0;
	while (str[k1])
	{
		k1++;

	}
	return k1;
}
//функция конвертирует строку в число и возвращает это число
int StringToNumber1(char* str)//функция конвертирует строку в число и возвращает это число
{
	char A[10]; int k = 0; int d = 0; int res = 0;
	for (char i = '0'; i <= '9'; i++)
	{
		A[k] = i;
		k++;

	}
	d = StringToNumber(str);
	for (int i = d, k = 0; i >= 0; i--)
		for (int j = 0; j < 10; j++)
			if (str[i] == A[j]) { res = res + j * pow(10, k); k++; }

	return res;
}
//выбор меню, проверка выбора, через функцию strchr

char menu()//выбор меню, проверка выбора, через функцию strchr
{
	char ch;
	do {

		cout << "\n\n\n enter'q' Edit car";
		cout << "\n enter'e' Print all cars";
		cout << "\n enter'u' Search for cars by number";
		cout << "\n'z' if you want to exit the program press space";
		cout << endl;
		cin >> ch;
		if (ch == 'z') { return ch; }
	} while (!strchr("euq ", tolower(ch)));
	return ch;
}

// ввод n ой машины
void enter(int n)
{
	int i;
	do
	{
		cout << "\n Enter the number: if the number? then select 1, if characters select 2\t";
		cin >> i;
		switch (i)
		{
		case 1:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].i;

			break;
		case 2:
			cout << "\n enter number\t";
			cin >> myavto[n].number[n].h;

			break;
		default:
			break;
		}

	} while (!(i == 1 || i == 2));

	cout << "\nenter color\t";
	cin >> myavto[n].color;
	cout << "\nenter model\t";
	cin >> myavto[n].model;
	myavto[n].flag = i;
}
// печать n ой машины

void print(int n)
{

	cout << "\n YOUR CARS\t";
	cout << "\n Your value number\t";

	if (myavto[n].flag == 1) { cout << myavto[n].number[n].i; }
	else
	{
		cout << myavto[n].number[n].h;
	}
	cout << "\n Your value color\t" << myavto[n].color;
	cout << "\n Your value model\t" << myavto[n].model;
}

//фукция поиска по номеру машины через функцию strcmp
void Search_number()
{
	char name[100]; char* a; int ai;
	cout << "\nenter number cars to search";
	cin >> (name);
	a = name;
	ai = StringToNumber1(name);
	int t;
	for (t = 0; t < N; t++)
	{
		if (!(strcmp(name, myavto[t].number[t].h)) || myavto[t].number[t].i == ai) { break; }
	}
	if (t == N) { cout << "\nno search cars\t" << endl; }
	else
	{
		print(t);
	}
}

void edit()
{

	char name[100]; char* a; int ai;
	cout << "\nenter number cars to search";
	cin >> (name);
	a = name;
	ai = StringToNumber1(name);
	int t;
	for (t = 0; t < N; t++)
	{
		if (!(strcmp(name, myavto[t].number[t].h)) || myavto[t].number[t].i == ai) { break; }
	}
	if (t == N) { cout << "\nno search cars\t" << endl; }

	enter(t);
}
int main()
{
	char choice; char vyxod = 'a'; int a;
	liun();
	for (int n = 0; n < N; n++)
	{
		enter(n);
	}

	do {

		choice = menu();// выбор действия которое необходимо провести

		switch (choice)
		{
		case 'e':
			for (int n = 0; n < N; n++)
				print(n);

			break;

		case 'u':
			Search_number();
			break;
		case 'q':
			edit();
			break;
		case 'z':
			vyxod = 'z';

			break;
		default:
			vyxod = 'z';

			break;
		}

	} while (!((vyxod) == 'z'));
	return 0;
}
