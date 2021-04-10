Домашнее задание
Тема: Рекурсия.

Задание 1:
Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.
Решение:
#include <iostream>

using namespace std;

int MaxDivider (int a, int b, int d) {
    
    if (a % d == 0 && b % d == 0) {
        return d;
    } else {
        return MaxDivider(a, b, d - 1);
    }
}

int main() {
    
    int firstUserNumber, secondUserNumber;
    
    cout << "Введите два целых числа:\n";
    cout << "Первое число: ";
    cin >> firstUserNumber;
    cout << "Второе число: ";
    cin >> secondUserNumber;
    
    int divider = firstUserNumber < secondUserNumber ? firstUserNumber : secondUserNumber;
    
    cout << "Максимальный делитель обоих чисел: " << MaxDivider(firstUserNumber, secondUserNumber, divider) << endl;
    
    return 0;
}

Задание 2:
Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его. После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы). После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе необходимо использовать рекурсию. 
Решение:
#include <iostream>

using namespace std;

int FindIn (int base, int elementToFind, int count) {
    if (!base) {
        return count;
    } else {
        if (base % 10 == elementToFind) {
            count++;
            return count;
        }
    }
    return FindIn(base / 10, elementToFind, count);
}

int Bulls(int a, int b, int count) {
    if (!b) {
        return count;
    } else {
        count = FindIn(a, b % 10, count);
        return Bulls(a, b / 10, count);
    }
}
    
int Cows(int hiddenNumber, int userNumber, int count) {
    if (hiddenNumber % 10 == userNumber % 10) {
        count++;
    }
    if (hiddenNumber) {
        return Cows(hiddenNumber / 10, userNumber / 10, count);
    }
    return count;
}

int GuessNumber(int hiddenNumber, int tries ) {
    int userNumber;
    cout << "Введите четырехзначное число: ";
    cin >> userNumber;
    
    if ( userNumber != hiddenNumber) {
        cout << "Быки (угадано цифр): " << Bulls(hiddenNumber, userNumber, 0) << endl;
        cout << "Коровы (цифры на нужном месте): " << Cows(hiddenNumber, userNumber, -1) << endl;
        return GuessNumber(hiddenNumber, tries + 1);

    } else {
        return tries;
    }
}

int main() {
    srand((unsigned int) time(NULL));
    int hiddenNumber = rand() % 10000;
    
    int allTries = GuessNumber(hiddenNumber, 1);
    
   cout << "Вы угадали! Количество попыток: " << allTries << endl;
    
    return 0;
}

Задание 3:
Дана шахматная доска размером 8х8 и шахматный конь. Программа должна запросить у пользователя координаты клетки поля и поставить туда коня. Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку только один раз. (Так как процесс отыскания пути для разных начальных клеток может затянуться, то рекомендуется сначала опробовать задачу на поле размером 6х6). В программе необходимо использовать рекурсию.
Решение:
#include <iostream>
 
#define SIZE 6
 
using namespace std;
 
void ShowBoard(int arr[][SIZE], int countY = 0, int countX = 0) {
    if (arr[countY][countX] < 10)
        cout << ' ';
    cout << arr[countY][countX] << ' ';
    if (countX < SIZE - 1)
        ShowBoard(arr, countY, countX + 1);
    else if (countY < SIZE - 1) {
        cout << endl;
        ShowBoard(arr, countY + 1, 0);
    }
}
 
void StartHorsePosition(int arr[][SIZE], int* x, int* y) {
    cout << "Введите начальную позицию фигуры:\n";
    cout << "по вертикали (от 1 до " << SIZE << "): ";
    cin >> *x;
    cout << "по горизонтали (от 1 до " << SIZE << "): ";
    cin >> *y;
    arr[--*x][--*y] = 1;
}
 
void NewHistory(int historyArr[][2], int elemToDelete) {
    if (elemToDelete < 7) {
        historyArr[elemToDelete][0] = historyArr[elemToDelete + 1][0];
        historyArr[elemToDelete][1] = historyArr[elemToDelete + 1][1];
        NewHistory(historyArr, elemToDelete + 1);
    }
}
 
void CopyArr(const int arr[8][2], int newArr[8][2], int count = 0) {
    newArr[count][0] = arr[count][0];
    newArr[count][1] = arr[count][1];
    if (count < 7)
        CopyArr(arr, newArr, count + 1);
}
 
void ArrayToZero(int(*arr)[SIZE], int row = 0, int col = 0) {
    arr[row][col] = 0;
    if (col < SIZE - 1) {
        ArrayToZero(arr, row, col + 1);
    }
    else if (row < SIZE - 1) {
        ArrayToZero(arr, row + 1);
    }
}
 
bool HorseStep(int arr[][SIZE], int history[][2], int* xMove, int* yMove, int stepsRemain = 7) {
    if (stepsRemain < 0) {
        return false;
    }
    else {
        int rndStep = stepsRemain == 0 ? 0 : rand() % stepsRemain;
        int tmpXMove = *xMove + history[rndStep][0];
        int tmpYMove = *yMove + history[rndStep][1];
        if (tmpXMove >= 0 &&
            tmpYMove >= 0 &&
            tmpXMove < SIZE &&
            tmpYMove < SIZE &&
            arr[tmpXMove][tmpYMove] == 0) {
            *xMove += history[rndStep][0];
            *yMove += history[rndStep][1];
            return true;
        }
        else {
            NewHistory(history, rndStep);
            HorseStep(arr, history, xMove, yMove, stepsRemain - 1);
        }
    }
}
 
void HorseMove(int(*arr)[SIZE], const int(*steps)[2], int* xPos, int* yPos, int xCopy, int yCopy, int moveCount = 2) {
    int movesHistory[8][2] = {0};
    CopyArr(steps, movesHistory);
    bool canStep = HorseStep(arr, movesHistory, xPos, yPos);
    if (canStep &&
        moveCount < SIZE * SIZE) {
        arr[*xPos][*yPos] = moveCount;
        HorseMove(arr, steps, xPos, yPos, xCopy, yCopy, moveCount + 1);
    }
    else if (canStep &&
        moveCount == SIZE * SIZE){
        cout << "\nУра!!!\n" << endl;
        arr[*xPos][*yPos] = moveCount;
    }
    else {
        cout << endl;
        //ShowBoard(arr);
        cout << endl;
        ArrayToZero(arr);
        *xPos = xCopy;
        *yPos = yCopy;
        arr[*xPos][*yPos] = 1;
        // HorseMove(arr, steps, xPos, yPos, xCopy, yCopy); не хватает памяти
    }
}
 
int main()
{
    setlocale(0, "Ru");
    srand((unsigned int)time(NULL));
 
    int board[SIZE][SIZE] = {0};
    int x, y, xCopy, yCopy;
 
    const int steps[8][2] = {
        {-1, -2},
        {-2, -1},
        {1, -2},
        {2, -1},
        {-1, 2},
        {-2, 1},
        {1, 2},
        {2, 1},
    };
 
    StartHorsePosition(board, &x, &y);
    xCopy = x;
    yCopy = y;
    // использовал while, потому что рекурсия съедает память
    while (board[x][y] == 1) {
        HorseMove(board, steps, &x, &y, xCopy, yCopy);
    }
    ShowBoard(board);
 
    return 0;
}


Задание 4:
Написать рекурсивную функцию нахождения степени числа. 
Решение:
#include <iostream>

using namespace std;

int PowerOfNumber(int number, int power, int sum = 1) {
    if (power == 0)
        return 1;
    sum *= number;
    return power > 1 ? PowerOfNumber(number, power - 1, sum) : sum;
}

int main() {
    
    int userNumber, power;
    
    cout << "Введите число: ";
    cin >> userNumber;
    cout << "Введите степень: ";
    cin >> power;
    
    cout << "Число " << userNumber;
    cout << " в степени " << power;
    cout << " равно " << PowerOfNumber(userNumber, power) << endl;
    
    return 0;
}


Задание 5:
Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь. Проиллюстрируйте работу функции примером.
Решение:
#include <iostream>

using namespace std;

void StarsInLine(int number) {
    if (number == 0)
        exit(0);
    cout << '*';
    if (number > 1)
        StarsInLine(number - 1);
}

int main() {
    
    setlocale(0, "Ru");
    
    int userNumber;
    
    cout << "Введите число: ";
    cin >> userNumber;
    
    StarsInLine(userNumber);
    cout << endl;
    
    return 0;
}


Задание 6:
Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b. Пользователь вводит a и b. Проиллюстрируйте работу функции примером.
Решение:
#include <iostream>

using namespace std;

int FromAtoB ( int start, int end, int sum = 0) {
    sum += start;
    return start < end ? FromAtoB(start + 1, end, sum) : sum;
}

int main() {
    
    setlocale(0, "Ru");
    
    int a, b;
    
    cout << "Введите диапазон: " << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    
    cout << "Сумма чисел от " << a << " до " << b << " равна " << FromAtoB(a, b) << endl;
    
    return 0;
}


Задание 7:
Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел, заполненных случайным образом, и находит позицию, с которой начинается последовательность из 10 чисел, сумма которых минимальна.
Решение:
#include <iostream>

#define SIZE 100

using namespace std;

void InitArray (int *arr, int count = 0) {
    *(arr + count) = rand() % 10;
    if (count < SIZE - 1)
        InitArray(arr, count + 1);
}

void ShowArray (int *arr, int count = 0) {
    cout << *(arr + count) << ' ';
    if (count < SIZE - 1)
        ShowArray(arr, count + 1);
}

void SumOfMinArray (int *arr, int *sum, int count, int endCount) {
    *sum += *(arr + count);
    if (count < endCount)
        SumOfMinArray(arr, sum, count + 1, endCount);
}

void RecurOfArray (int *arr, int *sum, int *pos, int count = 0) {
    int newSum = 0;
    SumOfMinArray(arr, &newSum, count, count + 9);
    if (*sum > newSum || *sum == 0) {
        *sum = newSum;
        *pos = count;
    }
    if (count < SIZE - 10)
        RecurOfArray(arr, sum, pos, count + 1);
    
}

int main () {
    
    setlocale(0, "Ru");
    srand((unsigned int)time(NULL));
    
    int arr[SIZE];
    int sum = 0;
    int position = 0;
    
    InitArray(arr);
    ShowArray(arr);
    cout << endl;
    RecurOfArray(arr, &sum, &position);
    cout << "Сумма минимальной десятки: " << sum << endl;
    cout << "Начинается на позиции: " << position << endl;
    
    return 0;
}


Тема: Указатели.
Задание 1:
Используя два указателя на массив целых чисел, скопировать один массив в другой. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
Решение:
#include <iostream>

using namespace std;

int main() {
    
    setlocale(0, "Ru");
    
    int arr[5] = {1, 2, 3, 4, 5};
    int secondArr[5];
    
    int* ptr = arr;
    int* secondPtr = secondArr;
    
    // Копируем первый массив во второй (чтобы увидеть изменение, добавим 1)
    for (int i = 0; i < 5; i++) {
        *(secondPtr + i) = *(ptr + i) + 1;
    }
    
    cout << "Первый массив: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << ' ';
    }
    
    cout << "\nВторой массив: ";
    for (int i = 0; i < 5; i++) {
        cout << *(secondPtr + i) << ' ';
    }
    
    cout << endl;
    
    return 0;
}

Задание 2:
Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный.
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
Решение:
#include <iostream>

#define SIZE 10

using namespace std;

void ShowArr (int *arr) {
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << ' ';
    }
    cout << endl;
}

int main() {
    
    setlocale(0, "Ru");
    
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* ptr = &arr[0];
    int tmp;
    
    cout << "Исходный массив: ";
    ShowArr(&arr[0]);
    
    int start = 0;
    int end = SIZE - 1;
    
    for (int i = 0; i < SIZE / 2; i++) {
            tmp = *(ptr + start);
            *(ptr + start) = *(ptr + end);
            *(ptr + end) = tmp;
        start++;
        end--;
    }
    
    cout << "Реверс массив: ";
    ShowArr(&arr[0]);
    
    cout << endl;
    
    return 0;
}

Задание 3:
Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы во втором массиве элементы находились в обратном порядке.
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
Решение:
#include <iostream>

#define SIZE 10

using namespace std;

void ShowArr (int *arr) {
    for (int i = 0; i < SIZE; i++) {
        cout << *(arr + i) << ' ';
    }
    cout << endl;
}

int main() {
    
    setlocale(0, "Ru");
    
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int secondArr[SIZE];
    int* ptr = &arr[0];
    int* secondPtr = &secondArr[0];
    
    cout << "Первый массив: ";
    ShowArr(&arr[0]);
    
    int end = SIZE - 1;
    
    for (int i = 0; i < SIZE; i++) {
        *(secondPtr + end) = *(ptr + i);
        end--;
    }
    
    cout << "Реверс массив: ";
    ShowArr(&secondArr[0]);
    
    cout << endl;
    
    return 0;
}

Задание 4:
Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
Решение:
#include <iostream>

using namespace std;

void MaxNumber (int *a, int *b) {
    *a > *b ? *a : *a = *b;
}

int main() {
    
    setlocale(0, "Ru");
    
    int a, b;
    
    cout << "Введите два целых числа:\n";
    cout << "Первое число: ";
    cin >> a;
    cout << "Второе число: ";
    cin >> b;
    
    MaxNumber(&a, &b);
    
    cout << a << " наибольшее число\n";
    
    return 0;
}

Задание 5:
Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.
Решение:
#include <iostream>

using namespace std;

void IsPositive(int *number) {
    *number = *number > 0 ? 1 : 0;
}

int main() {
    
    setlocale(0, "Ru");
    
    int userNumber;
    
    cout << "Введите целое число: ";
    cin >> userNumber;
    
    IsPositive(&userNumber);
    cout << "Знак введенного числа: ";
    userNumber == 1 ? cout << "плюс\n" : cout << "минус\n";
    
    return 0;
}

Задание 6:
Используя указатели и оператор разыменования, обменять местами значения двух переменных.
Решение:
#include <iostream>

using namespace std;

void replaceNumbers (int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    
    setlocale(0, "Ru");
    
    int a, b;
    
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    
    replaceNumbers(&a, &b);
    
    cout << "Первое число = " << a << endl;
    cout << "Второе число = " << b << endl;
    
    return 0;
}

Задание 7:
Написать примитивный калькулятор, пользуясь только указателями.
Решение:
#include <iostream>

using namespace std;

template <typename T>
void Calculate (int *num1, int *num2, char *act, T *res) {
    switch (*act) {
        case '+':
            *res = *num1 + *num2;
            break;
        case '-':
            *res = *num1 - *num2;
            break;
        case '*':
            *res = *num1 * *num2;
            break;
        case '/':
            *res = *num1 / (double)*num2;
            break;
        default:
            cout << "Неверный ввод\n";
            exit(10);
    }
}

int main () {
    
    setlocale(0, "Ru");
    
    int firstNumber, secondNumber;
    int result = 0;
    double doubleResult = 0;
    char action;
    
    cout << "Введите первое число: ";
    cin >> firstNumber;
    cout << "Введите второе число: ";
    cin >> secondNumber;
    cout << "Введите действие (+ - * /): ";
    cin >> action;
    
    int* firstNumberPtr = &firstNumber;
    int* secondNumberPtr = &secondNumber;
    char* actionPtr = &action;
    int* resultPtr = &result;
    double* doubleResultPtr = &doubleResult;
    
    action == '/' ?
    Calculate(firstNumberPtr, secondNumberPtr, actionPtr, doubleResultPtr) :
    Calculate (firstNumberPtr, secondNumberPtr, actionPtr, resultPtr);
    
    cout << "Результат равен: ";
    action == '/' ? cout << *doubleResultPtr : cout << *resultPtr;
    cout << endl;
    
    return 0;
}

Задание 8:
Используя указатель на массив целых чисел, посчитать сумму элементов массива. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
Решение:
#include <iostream>

using namespace std;

int main () {
    
    setlocale(0, "Ru");
    
    const int SIZE = 5;
    
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int*ptrArr = &arr[0];
    int sum = 0;
    
    for (int i = 0; i < SIZE; i++) {
        sum += *ptrArr;
        ptrArr++;
    }
    
    cout << "Сумма чисел массива: " << sum << endl;
    
    return 0;
}