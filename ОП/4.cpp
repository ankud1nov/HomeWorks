Домашнее задание

Тема: Многомерные массивы
Задание 1:
Напишите программу, которая создает двухмерный̆ массив и заполняет его по следующему принципу: пользователь вводит число (например, 3) первый̆ элемент массива принимает значение этого числа, последующий̆ элемент массива принимает значение этого числа, умноженного на 2 (т.е. 6 для нашего примера), третий̆ элемент массива предыдущий̆ элемент, умноженный̆ на 2 (т.е. 6*2=12 для нашего примера). Созданный̆ массив вывести на экран.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");

int doubledArray[3][3] = {0};
int userNumber;

cout << "Введите число:";
cin >> userNumber;

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
doubledArray[i][j] = userNumber;
userNumber *= 2;
}
}

cout << "Полученный массив:\n";
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
cout << doubledArray[i][j] << "\t";
}
cout << endl;
}
}

Задание 2:
Напишите программу, которая создает двухмерный̆ массив и заполняет его по следующему принципу: пользователь вводит число (например, 3) первый̆ элемент массива принимает значение этого числа, последующий̆ элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), третий̆ элемент массива предыдущий̆ элемент + 1 (т.е. 5 для нашего примера). Созданный̆ массив вывести на экран.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");

int doubledArray[3][3] = {0};
int userNumber;

cout << "Введите число:";
cin >> userNumber;

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
doubledArray[i][j] = userNumber;
userNumber += 1;
}
}

cout << "Полученный массив:\n";
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
cout << doubledArray[i][j] << "\t";
}
cout << endl;
}
}

Задание 3:
Создайте двухмерный̆ массив. Заполните его случайными числами и покажите на экран. Пользователь выбирает количество сдвигов и положение (влево, вправо, вверх, вниз). Выполнить сдвиг массива и показать на экран полученный̆ результат. Сдвиг циклический̆. 

Например, если мы имеем следующий̆ массив
1 2 0 4 5 3
4 5 3 9 0 1
 и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
5 3 1 2 0 4
0 1 4 5 3 9
Решение:
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
setlocale(LC_ALL, "Russian");
srand(time(NULL));
 
const int row = 4;
const int col = 4;
int randomArray[row][col] = { 0 };
int toMoveSteps = 0;
int tempCell, nextCell;
char direction;
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
randomArray[i][j] = rand() % 10;
}
}
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
cout << randomArray[i][j] << "\t";
}
cout << endl;
}
 
do {
 
cout << "\nВведите направление сдвига:\n"
"1 - вверх\n"
"2 - вправо\n"
"3 - вниз\n"
"4 - влево\n"
"0 - выход\n";
cin >> direction;
 
if (direction == '0')
return 0;
 
cout << "Введите количество элементов для сдвига: ";
cin >> toMoveSteps;
 
 
switch (direction)
{
case '1':
{
for (int step = 0; step < toMoveSteps; step++)
{
for (int i = 0; i < row; i++)
{
nextCell = (i + row - 1) % row;
if (nextCell == row - 1)
continue;
for (int j = 0; j < col; j++)
{
tempCell = randomArray[i][j];
randomArray[i][j] = randomArray[nextCell][j];
randomArray[nextCell][j] = tempCell;
}
}
}
break;
}
 
case '2':
{
for (int step = 0; step < toMoveSteps; step++)
{
for (int i = 0; i < row; i++)
{
for (int j = col - 1; j > 0; j--) {
 
nextCell = (j + col + 1) % col;
if (nextCell == col)
continue;
{
tempCell = randomArray[i][j];
randomArray[i][j] = randomArray[i][nextCell];
randomArray[i][nextCell] = tempCell;
}
}
}
}
break;
}
 
case '3':
{
for (int step = 0; step < toMoveSteps; step++)
{
for (int i = row - 1; i > 0; i--)
{
for (int j = 0; j < row; j++) {
 
nextCell = (i + row + 1) % row;
if (nextCell == row)
continue;
{
tempCell = randomArray[i][j];
randomArray[i][j] = randomArray[nextCell][j];
randomArray[nextCell][j] = tempCell;
}
}
}
}
break;
}
 
case '4':
{
 
for (int step = 0; step < toMoveSteps; step++)
{
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++) {
 
nextCell = (j + col - 1) % col;
if (nextCell == col - 1)
continue;
{
tempCell = randomArray[i][j];
randomArray[i][j] = randomArray[i][nextCell];
randomArray[i][nextCell] = tempCell;
}
}
}
}
break;
}
 
}
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
cout << randomArray[i][j] << "\t";
}
cout << endl;
}
 
} while (direction);
 
return 0;
}

Задание 4:
В двумерном массиве целых чисел посчитать:
Сумму всех элементов массива
Среднее арифметическое всех элементов массива
Минимальный̆ элемент
Максимальный̆ элемент
Решение:
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
setlocale(LC_ALL, "Russian");
srand(time(NULL));
 
const int row = 5;
const int col = 5;
int totalSumOfElements = 0;
int minElement = 0, maxElement = 0;
float average;
 
int intNumbersArray[row][col];
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
intNumbersArray[i][j] = rand() % 10;
 
// Сразу посчитаем сумму всех элементов
totalSumOfElements += intNumbersArray[i][j];
 
// Минимальный элемент
if (minElement > intNumbersArray[i][j])
{
minElement = intNumbersArray[i][j];
}
 
// Максимальный элемент
if (maxElement < intNumbersArray[i][j])
{
maxElement = intNumbersArray[i][j];
}
 
}
}
 
cout << "Двумерный массив целых чисел:\n";
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
cout << intNumbersArray[i][j] << "  ";
}
cout << endl;
}
 
average = (float)totalSumOfElements / (row * col);
 
cout << "\nСумма всех элементов массива равна: " << totalSumOfElements << endl;
cout << "\nСреднее арифметическое всех элементов массива: " << average << endl;
cout << "\nМинимальный элемент: " << minElement << endl;
cout << "\nМаксимальный элемент: " << maxElement << endl;
 
return 0;
}

Задание 5:
В двумерном массиве целых чисел посчитать сумму элементов: в каждой̆ строке; в каждом столбце; одновременно по всем строкам и всем столбцам. Оформить следующим образом:
3	5	6	7	|	21
121	1	1	1	|	15
0	7	12	1	|	20
-----------------------------------------------
15	3	19	9	|	56
Решение:
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
setlocale(LC_ALL, "Russian");
srand(time(NULL));
 
const int row = 5;
const int col = 5;
int sumOfColElements = 0;
 
int intNumbersArray[row][col] = { 0 };
 
for (int i = 0; i < row - 1; i++)
{
for (int j = 0; j < col; j++)
{
if (j != col - 1) {
intNumbersArray[i][j] = rand() % 10;
sumOfColElements += intNumbersArray[i][j]; // Суммирование по строкам
 
if (i != row - 1) {
intNumbersArray[row - 1][j] += intNumbersArray[i][j]; // Суммирование по столбцам и запись в последнюю строку
}
}
else
{
intNumbersArray[i][j] = sumOfColElements; // Запись результата по строкам в последнюю колонку
intNumbersArray[row - 1][col - 1] += sumOfColElements; // Общая сумма элементов
sumOfColElements = 0; // Обнуление промежуточной суммы
}
}
}
 
cout << "Двумерный массив целых чисел:\n";
 
for (int i = 0; i < row; i++)
{
for (int j = 0; j < col; j++)
{
cout << intNumbersArray[i][j] << "\t";
}
cout << endl;
}
 
 
 
return 0;
}

Задание 6:
Напишите программу, в которой̆ объявляется массив размером 5х10 и массив размером 5х5. Первый̆ массив заполняется случайными числами, в диапазоне от 0 до 50. Второй̆ массив заполняется по следующему принципу: первый̆ элемент второго массива равен сумме первого и второго элемента первого массива, второй̆ элемент второго массива равен сумму третьего и четвертого элемента первого массива.
Решение:
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
setlocale(LC_ALL, "Russian");
srand(time(NULL));
 
const int rowFirstArray = 5;
const int colFirstArray = 10;
const int rowSecondArray = 5;
const int colSecondArray = 5;
int firstArrayCounter = 0;
 
int firstArray[rowFirstArray][colFirstArray] = { 0 };
int secondArray[rowSecondArray][colSecondArray] = { 0 };
 
for (int i = 0; i < rowFirstArray; i++)
{
for (int j = 0; j < colFirstArray; j++)
{
firstArray[i][j] = rand() % 51;
}
}
 
for (int i = 0; i < rowSecondArray; i++)
{
for (int j = 0; j < colSecondArray; j++)
{
secondArray[i][j] = firstArray[i][firstArrayCounter] + firstArray[i][firstArrayCounter + 1];
firstArrayCounter += 2;
}
firstArrayCounter = 0;
}
 
cout << "Исходный двумерный массив целых чисел:\n\n";
 
for (int i = 0; i < rowFirstArray; i++)
{
for (int j = 0; j < colFirstArray; j++)
{
cout << firstArray[i][j] << "\t";
}
cout << endl;
}
 
cout << "Полученный двумерный массив целых чисел:\n\n";
 
for (int i = 0; i < rowSecondArray; i++)
{
for (int j = 0; j < colSecondArray; j++)
{
cout << secondArray[i][j] << "\t\t";
}
cout << endl;
}
 
return 0;
}


Тема: Функции
Задание 1:
Написать функцию, которая принимает два параметра: основание степени и показатель степени, и вычисляет степень числа на основе полученных данных. 
Решение:
#include <iostream>
 
using namespace std;
 
int PoweredNumber(int base, int power)
{
if (power == 0)
return 1;
int poweredNumber = 1;
for (int i = 0; i < power; i++)
{
poweredNumber *= base;
}
 
return poweredNumber;
}
int main()
{
setlocale(LC_ALL, "Russian");
 
int userNumber, userPower;
 
cout << "Введите целое число: ";
cin >> userNumber;
cout << "Введите степень для возведения числа: ";
cin >> userPower;
 
cout << "Ваше число " << userNumber << " возведенное в степень " << userPower << " равно: " << PoweredNumber(userNumber, userPower);
 
return 0;
}

Задание 2:
Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними. 
Решение:
#include <iostream>
 
using namespace std;
 
int SumOfRange(int minNumber, int maxNumber)
{
int sumOfRange = 0;
int tempNumber;
if (minNumber > maxNumber) {
tempNumber = minNumber;
minNumber = maxNumber;
maxNumber = tempNumber;
}
 
for (int i = minNumber + 1; i < maxNumber; i++)
{
sumOfRange += i;
}
 
return sumOfRange;
}
int main()
{
setlocale(LC_ALL, "Russian");
int minUserRange, maxUserRange;
 
cout << "Введите нижний диапазон целых чисел: ";
cin >> minUserRange;
cout << "Введите верхний диапазон целых чисел: ";
cin >> maxUserRange;
 
cout << "Сумма чисел диапазона равна: " << SumOfRange(minUserRange, maxUserRange);
 
return 0;
}

Задание 3:
Число называется совершенным, если сумма всех его делителей̆ равна ему самому. Напишите функцию поиска таких чисел во введенном интервале. 
Решение:
#include <iostream>
 
using namespace std;
 
int PerfectNumber(int number)
{
int sumOfDivisors = 0;
for (int i = 1; i < number; i++)
{
if (number % i == 0) 
{
sumOfDivisors += i;
}
}
 
if (sumOfDivisors == number)
{
return number;
}
else
{
return 0;
}
}
 
 
int main()
{
setlocale(LC_ALL, "Russian");
int minUserRange, maxUserRange, zeroOfPerfectNumbers = 0;
 
cout << "Введите нижний диапазон целых чисел: ";
cin >> minUserRange;
cout << "Введите верхний диапазон целых чисел: ";
cin >> maxUserRange;
 
cout << "Совершенные числа в указанном диапазоне:\n";
for (int i = minUserRange; i < maxUserRange; i++)
{
if (PerfectNumber(i)) {
cout << i << " ";
zeroOfPerfectNumbers += i;
}
}
if (!zeroOfPerfectNumbers) {
cout << "таковых чисел нет";
}
return 0;
}

Задание 4:
Написать функцию, выводящую на экран переданную ей̆ игральную карту. 
Решение:
#include <iostream>
#include <stdlib.h>
 
using namespace std;
 
void PrintCard(char mast, char numb) {
 
char suitName[4] = { 'П', 'Ч', 'К', 'Б' };
int intMast = mast - '0';
 
cout << " ________ " << endl;
 
cout << "|    " << numb << " " << suitName[intMast - 1] << " |" << endl;
 
cout << "|        |" << endl;
 
cout << "|        |" << endl;
 
cout << "|        |" << endl;
 
cout << "|        |" << endl;
 
cout << "|        |" << endl;
 
cout << "|________|" << endl;
}
 
void PrintCardMenu() {
 
cout << "Информация по картам:";
 
cout << "\n A - Туз";
 
cout << "\n K - Король";
 
cout << "\n K - Дама";
 
cout << "\n J - Валет";
 
cout << "\n T - Десятка";
 
cout << "\n 9 - Девятка";
 
cout << "\n 8 - Восьмерка";
 
cout << "\n 7 - Семерка";
 
cout << "\n 6 - Шестерка\n";
 
}

void PrintSuitMenu() {
 
cout << "\n1 - Пики"
 
"\n2 - Черви"
 
"\n3 - Крести"
 
"\n4 - Буби\n";
 
}

bool isACard(char card) {
const int realNumbCount = 9;
 
char realNumb[realNumbCount] = { 'A','K', 'D', 'J', 'T', '9', '8', '7', '6' };
 
for (int i = 0; i < realNumbCount; i++) {
 
if (card == realNumb[i])
 
return true;
}
 
return false;
}

bool IsASuit(char suit) {
 
const int suitListCount = 4;
 
char suitList[suitListCount] = { '1', '2', '3', '4' };
  
for (int i = 0; i < suitListCount; i++) {
 
if (suit == suitList[i])
 
return true;
 
}
 
return false;
 
}
 
 
 
int main() {
 
 
 
setlocale(LC_ALL, "Russian");
char suit, numb;
 
PrintCardMenu();
 
cin >> numb;
 
while (!isACard(numb)) {
 
cout << " Такой карты нет, введите карту из списка\n";
 
cin >> numb;
 
}
 
 
 
PrintSuitMenu();
 
cin >> suit;
 
while (!IsASuit(suit)) {
 
cout << " Такой масти нет, введите другую из списка\n";
 
cin >> suit;
 
}
 
PrintCard(suit, numb);
 
return 0;
 
}

Задание 5:
Написать функцию, которая определяет, является ли «счастливым» шестизначное число. 
Решение:
#include <iostream>
 
using namespace std;
 
bool IsSixDigits(char number[]) {
if (number[6] == '\0')
return true;
return false;
}
 
bool IsLuckyNumber(char number[]) {
int leftSum = 0;
int rightSum = 0;
for (int i = 0; i < 6; i++) {
if (i < 3) {
leftSum += number[i] - '0';
}
else {
rightSum += number[i] - '0';
}
}
 
return leftSum == rightSum ? true : false;
}
 
int main() {
 
setlocale(LC_ALL, "Russian");
 
char userNumber[7];
 
cout << "Введите шестизначное число:\n";
cin >> userNumber;
while (!IsSixDigits(userNumber)) {
cout << "\nНеверный ввод. Повторите\n";
cin >> userNumber;
}
 
if (IsLuckyNumber(userNumber) ){
cout << "Счастливое число!!!";
}
else {
cout << "Грустное число.";
}
 
return 0;
 
}

Задание 6:
Написать функцию, которая принимает две даты (т.е. функция принимает шесть параметров) и вычисляет разность в днях между этими датами. Для решения этой̆ задачи необходимо также написать функцию, которая определяет, является ли год високосным. 
Решение:
#include <iostream>
 
using namespace std;
 
bool IsLeapYear(int year) {
if (year % 4 != 0)
return false;
 
if (year % 100 != 0)
return true;
 
if (year % 400 != 0)
return false;
 
return true;
}
 
int MonthsInDays(int month, int year) {
int days = 0;
int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
if (IsLeapYear(year))
daysInMonth[1] = 29;
 
for (int i = 0; i < month; i++) {
days += daysInMonth[i];
}
 
return days;
}
 
int YearsInDays(int year) {
int days = 0;
int daysInYear;
for (int i = 0; i < year; i++) {
daysInYear = IsLeapYear(i) ? 366 : 365;
days += daysInYear;
}
return days;
}
 
int CountOfDays(int startDay, int endDay, int startMonth, int endMonth, int startYear, int endYear) {
 
int sumOfStartDays = startDay + MonthsInDays(startMonth, startYear ) + YearsInDays(startYear);
int sumOfEndDays = endDay + MonthsInDays(endMonth, endYear) + YearsInDays(endYear);
int differenceInDays = sumOfEndDays - sumOfStartDays;
 
 
return differenceInDays;
}
 
int main() {
 
setlocale(LC_ALL, "Russian");
 
int startDay, endDay, startMonth, endMonth, startYear, endYear;
 
cout << "Введите начальную дату:\n";
cout << "День(DD): ";
cin >> startDay;
cout << "Месяц(MM): ";
cin >> startMonth;
cout << "Год(YYYY): ";
cin >> startYear;
cout << "\nВведите конечную дату:\n";
cout << "День(DD): ";
cin >> endDay;
cout << "Месяц(MM): ";
cin >> endMonth;
cout << "Год(YYYY): ";
cin >> endYear;
 
cout << "Разность в днях между датами составляет: ";
cout << CountOfDays(startDay, endDay, startMonth, endMonth, startYear, endYear);
cout << endl;
return 0;
 
}

Задание 7:
Написать функцию, определяющую среднее арифметическое элементов передаваемого ей̆ массива.
Решение:
#include <iostream>
 
using namespace std;
 
float AverageSum(int array[], int size) {
int sum = 0;
for (int i = 0; i < size; i++)	{
sum += array[i];
}
return sum / (float)size;
}
 
void PrintArray(int array[], int size) {
for (int i = 0; i < size; i++) {
cout << array[i] << " ";
}
}
 
int main() {
 
setlocale(LC_ALL, "Russian");
 
const int arraySize = 5;
int userArray[arraySize] = { 1, 2 , 0, 3, 5 };
 
cout << "Имеется массив:\n";
 
PrintArray(userArray, arraySize);
 
cout << "\nСреднее арифметическое массива: " << AverageSum(userArray, arraySize) << endl;
return 0;
 
}

Задание 8:
Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей̆ массива.
Решение:
#include <iostream>
 
using namespace std;
 
void PrintCounterOfDifferentElements(int array[], int size) {
int countPositiveElements = 0;
int countZeroElements = 0;
int countNegativeElements = 0;
for (int i = 0; i < size; i++)	{
if (array[i] > 0) {
countPositiveElements++;
}
else if (array[i] == 0) {
countZeroElements++;
 
}
else {
countNegativeElements++;
}
}
 
cout << "\nВ представленноммассиве:"
"\nколичество позитивных элементов составляет: " << countPositiveElements << endl;
cout << "нулевых: " << countZeroElements << endl;
cout << "отрицательных: " << countNegativeElements << endl;
}
 
void PrintArray(int array[], int size) {
for (int i = 0; i < size; i++) {
cout << array[i] << " ";
}
}
 
int main() {
 
setlocale(LC_ALL, "Russian");
 
const int arraySize = 10;
int userArray[arraySize] = { 1, -2 , 0, 3, -5, 0, -3, 8, 10, 342 };
 
cout << "Имеется массив:\n";
 
PrintArray(userArray, arraySize);
 
PrintCounterOfDifferentElements(userArray, arraySize);
return 0;
 
}