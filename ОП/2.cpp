Задание 1. Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a вводится с клавиатуры).
Решение:
#include <iostream>

using namespace std;

int main()
{
  int a, amount = 0;
  cout << "Enter integer number (max = 500):";
  cin >> a;
  for (int i = a; i < 501; i++)
  {
    amount += i;
  };
  cout << "Amount from " << a << " to 500 is: " << amount;
  return 0;
}

Задание 2. Напишите программу, которая запрашивает два целых числа x и y, после чего вычисляет и выводит значение x в степени y.
Решение:
#include <iostream>

using namespace std;

int main()
{
  int x, y;
  long long poweredNumber = 1;

  cout << "Enter integer x: ";
  cin >> x;
  cout << "Enter positive integer y: ";
  cin >> y;

  if (y > 0)
  {
    poweredNumber = x;
    for (int i = 1; i < y; i++)
    {
      poweredNumber *= x;
    }
  }
  else if (y < 0)
  {
    cout << "\"y\" must be positive integer" << endl;
    return 0;
  }

  cout << x << " to the power of " << y << " is: " << poweredNumber << endl;
  return 0;
}

Задание 3. Найти среднее арифметическое всех целых чисел от 1 до 1000.
Решение:
#include <iostream>

using namespace std;

int main()
{
  float average = 0;
  for (int i = 1; i <= 1000; i++)
  {
    average += i;
  }

  cout << "arithmetic mean from 1 to 1000 is: " << (average / 1000) << endl;
  return 0;
}

Задание 4. Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры: 1 <=a <= 20).
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int a;
long long multiplicationOfNumbers = 1;
while (true)
{
cout << "Введите целое число от 1 до 20: ";
cin >> a;
if (a >= 1 && a <= 20) {
for (int i = a; i <= 20; i++) {
multiplicationOfNumbers *= i;
}
cout << "Произведение чисел от " << a << " до 20: " << multiplicationOfNumbers;
break;
}
cout << "Ошибка! Повторите ввод..." << endl;
}
return 0;
}

Задание 5. Написать программу, которая выводит на экран таблицу умножения на k, где k – номер варианта. Например, для 7-го варианта: 
7 x 2 = 14 
7 x 3 = 21
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int k;
cout << "Введите целое число: ";
cin >> k;
cout << "\nТаблица умножения на " << k << "\n\n";
for (int i = 2; i < 10; i++) {
cout << k << " x " << i << " = " << k * i << "\n\n";
}
return 0;
}

Задание 6. Вывести на экран все числа от нуля до введенного пользователем числа.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int userNumber;
while (true)
{
cout << "Введите целое положительное число: ";
cin >> userNumber;
if (userNumber >= 0) {
cout << "\nЧисла от нуля до " << userNumber << "\n\n";
for (int i = 0; i <= userNumber; i++) {
cout << i << endl;
}
break;
}
cout << "Неверный ввод. Повторите...\n";
}
return 0;
}

Задание 7. Пользователь вводит две границы диапазона, вывести на экран все числа из этого диапазона. Предусмотреть, чтобы пользователь мог вводить границы диапазона в произвольном порядке.
вывести все четные числа из диапазона.
вывести все нечетные числа из диапазона.
вывести все числа, кратные семи.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int minRange, maxRange, tempRange;
cout << "Введите диапазон чисел\n";
cout << "Первая граница: ";
cin >> minRange;
cout << "Вторая граница: ";
cin >> maxRange;

// Сортировка диапазона
if (minRange > maxRange) {
tempRange = minRange;
minRange = maxRange;
maxRange = tempRange;
}

cout << "\nДиапазон от " << minRange << " до " << maxRange << endl;

// Вывод четных чисел из диапазона
cout << "\nЧетные числа из диапазона:\n";
for (int i = minRange; i <= maxRange; i++) {
if ((i % 2) == 0) {
cout << i << endl;
}
}

// Вывод нечетных чисел из диапазона
cout << "\nНечетные числа из диапазона:\n";
for (int i = minRange; i <= maxRange; i++) {
if ((i % 2) != 0) {
cout << i << endl;
}
}

// Вывод чисел из диапазона кратных 7
cout << "\nЧисла из диапазона, кратные 7:\n";
for (int i = minRange; i <= maxRange; i++) {
if ((i % 7) == 0) {
cout << i << endl;
}
}
return 0;
}

Задание 8. Пользователь вводит две границы диапазона. Посчитать сумму всех чисел диапазона.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int minRange, maxRange, tempRange, sumRangeNumbers = 0;
cout << "Введите диапазон чисел\n";
cout << "Первая граница: ";
cin >> minRange;
cout << "Вторая граница: ";
cin >> maxRange;

// Сортировка диапазона
if (minRange > maxRange) {
tempRange = minRange;
minRange = maxRange;
maxRange = tempRange;
}
cout << "\nДиапазон от " << minRange << " до " << maxRange << endl;

for (int i = minRange; i <= maxRange; i++) {
sumRangeNumbers += i;
}
cout << "\nСумма всех чисел из диапазона:\n" << sumRangeNumbers;
return 0;
}

Задание 9. Пользователь с клавиатуры вводит числа. Посчитать их сумму и вывести на экран, как только пользователь введет ноль.
Решение:
#include <iostream>

using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");
int userNumber, sumOfNumbers = 0;

while (true) {
cout << "Введите целое число:\n";
cin >> userNumber;
if (userNumber == 0) {
cout << "\nСумма всех введенных чисел: " << sumOfNumbers;
break;
}
sumOfNumbers += userNumber;
}
return 0;
}
