Домашнее задание			

Тема: Указатели.

Задание 1:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массива A, которые не включаются в массив B, без повторений.
Решение:
#include <iostream>
 
using namespace std;
 
void InitArray(int* arr, int size) {
for (int i = 0; i < size; i++)
*(arr + i) = rand() % 100;
}
 
void ShowArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
cout << *(arr + i) << '\t';
if ((i + 1) % 10 == 0)
cout << endl;
}
cout << endl;
}
 
void CopyArray(int* srcArr, int* destArr, int size) {
for (int i = 0; i < size; i++) {
destArr[i] = srcArr[i];
}
}
 
bool InArray(int elem, int* arr, int size) {
for (int i = 0; i < size; i++) {
if (arr[i] == elem) {
return true;
}
}
return false;
}
 
int main() {
srand((unsigned int)time(NULL));
 
int count = 0;
int* M = new int;
int* N = new int;
int* A;
int* B;
int* unitedArr;
 
cout << "Enter size of first array: \n";
cin >> *M;
cout << "Enter size of second array: \n";
cin >> *N;
 
A = new int[*M];
B = new int[*N];
 
InitArray(A, *M);
InitArray(B, *N);
 
cout << "\nFirst array:\n";
ShowArray(A, *M);
cout << "\nSecond array:\n";
ShowArray(B, *N);
 
unitedArr = new int[*M]{};
 
for (int i = 0; i < *M; i++) {
if (!InArray(A[i], B, *N) &&
!InArray(A[i], unitedArr, count)) {
unitedArr[count] = A[i];
count++;
}
}
 
delete M;
delete N;
delete[]A;
delete[]B;
M = nullptr;
N = nullptr;
A = nullptr;
B = nullptr;
 
int* minimalUnitedArray = new int[count];
 
CopyArray(unitedArr, minimalUnitedArray, count);
 
delete[]unitedArr;
unitedArr = nullptr;
 
if (count) {
cout << "\nElements from first not in second:\n";
ShowArray(minimalUnitedArray, count);
}
else {
cout << "\nNot elements to show\n";
}
 
return 0;
}

Задание 2:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы массивов A и B, которые не являются общими для них, без повторений.
Решение:
#include <iostream>
 
using namespace std;
 
void InitArray(int* arr, int size) {
for (int i = 0; i < size; i++)
*(arr + i) = rand() % 100;
}
 
void ShowArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
cout << *(arr + i) << '\t';
if ((i + 1) % 10 == 0)
cout << endl;
}
cout << endl;
}
 
void CopyArray(int* srcArr, int* destArr, int size) {
for (int i = 0; i < size; i++) {
destArr[i] = srcArr[i];
}
}
 
bool InArray(int elem, int* arr, int size) {
for (int i = 0; i < size; i++) {
if (arr[i] == elem) {
return true;
}
}
return false;
}
 
int main() {
srand((unsigned int)time(NULL));
 
int count = 0;
int* M = new int;
int* N = new int;
int* A;
int* B;
int* unitedArr;
 
cout << "Enter size of first array: \n";
cin >> *M;
cout << "Enter size of second array: \n";
cin >> *N;
 
A = new int[*M];
B = new int[*N];
 
InitArray(A, *M);
InitArray(B, *N);
 
cout << "\nFirst array:\n";
ShowArray(A, *M);
cout << "\nSecond array:\n";
ShowArray(B, *N);
 
unitedArr = new int[*M + *N]{};
 
for (int i = 0; i < *M; i++) {
if (!InArray(A[i], B, *N) &&
!InArray(A[i], unitedArr, count)) {
unitedArr[count] = A[i];
count++;
}
}
 
for (int i = 0; i < *N; i++) {
if (!InArray(B[i], A, *M) &&
!InArray(B[i], unitedArr, count)) {
unitedArr[count] = B[i];
count++;
}
}
 
delete M;
delete N;
delete[]A;
delete[]B;
M = nullptr;
N = nullptr;
A = nullptr;
B = nullptr;
 
int* minimalUnitedArray = new int[count];
 
CopyArray(unitedArr, minimalUnitedArray, count);
 
delete[]unitedArr;
unitedArr = nullptr;
 
if (count) {
cout << "\nElements from first and second not common:\n";
ShowArray(minimalUnitedArray, count);
}
else {
cout << "\nNot elements to show\n";
}
 
return 0;
}

Задание 3:
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать элементы обоих массивов. 
Решение:
#include <iostream>
 
using namespace std;
 
void InitArray(int* arr, int size) {
for (int i = 0; i < size; i++)
*(arr + i) = rand() % 100;
}
 
void ShowArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
cout << *(arr + i) << '\t';
if ((i + 1) % 10 == 0)
cout << endl;
}
cout << endl;
}
 
int main() {
srand((unsigned int)time(NULL));
 
int count = 0;
int* M = new int;
int* N = new int;
int* A;
int* B;
int* unitedArr;
 
cout << "Enter size of first array: \n";
cin >> *M;
cout << "Enter size of second array: \n";
cin >> *N;
 
A = new int[*M];
B = new int[*N];
 
InitArray(A, *M);
InitArray(B, *N);
 
cout << "\nFirst array:\n";
ShowArray(A, *M);
cout << "\nSecond array:\n";
ShowArray(B, *N);
 
unitedArr = new int[*M + *N]{};
 
for (int i = 0; i < *M; i++) {
unitedArr[count] = A[i];
count++;
}
 
for (int i = 0; i < *N; i++) {
unitedArr[count] = B[i];
count++;
}
 
delete M;
delete N;
delete[]A;
delete[]B;
M = nullptr;
N = nullptr;
A = nullptr;
B = nullptr;
 
cout << "\nTotal array:\n";
ShowArray(unitedArr, count);
 
return 0;
}

Задание 4: 				
Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры). Необходимо создать третий массив минимально возможного размера, в котором нужно собрать общие элементы двух массивов без повторений.
Решение:
#include <iostream>
 
using namespace std;
 
void InitArray(int* arr, int size) {
for (int i = 0; i < size; i++)
*(arr + i) = rand() % 100;
}
 
void ShowArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
cout << *(arr + i) << '\t';
if ((i + 1) % 10 == 0)
cout << endl;
}
cout << endl;
}
 
void CopyArray(int* srcArr, int* destArr, int size) {
for (int i = 0; i < size; i++) {
destArr[i] = srcArr[i];
}
}
 
bool InArray(int elem, int* arr, int size) {
for (int i = 0; i < size; i++) {
if (arr[i] == elem) {
return true;
}
}
return false;
}
 
int main() {
srand((unsigned int)time(NULL));
 
int count = 0;
int* M = new int;
int* N = new int;
int* A;
int* B;
int* unitedArr;
 
cout << "Enter size of first array: \n";
cin >> *M;
cout << "Enter size of second array: \n";
cin >> *N;
 
A = new int[*M];
B = new int[*N];
 
InitArray(A, *M);
InitArray(B, *N);
 
cout << "\nFirst array:\n";
ShowArray(A, *M);
cout << "\nSecond array:\n";
ShowArray(B, *N);
 
int* minSize = *M > *N ? N : M;
int* minArr = *M > *N ? B : A;
int* maxArr = *M > *N ? A : B;
 
unitedArr = new int[*minSize]{};
 
for (int i = 0; i < *minSize; i++) {
if (InArray(minArr[i], maxArr, *minSize) &&
!InArray(minArr[i], unitedArr, count)) {
unitedArr[count] = minArr[i];
count++;
}
}
 
delete M;
delete N;
delete[]A;
delete[]B;
M = nullptr;
N = nullptr;
A = nullptr;
B = nullptr;
 
int* minimalUnitedArray = new int[count];
 
CopyArray(unitedArr, minimalUnitedArray, count);
 
delete[]unitedArr;
unitedArr = nullptr;
 
if (count) {
cout << "\nCommon elements from first and second:\n";
ShowArray(minimalUnitedArray, count);
}
else {
cout << "\nNot elements to show\n";
}
 
return 0;
}

Задание 5: 				
Дан массив: А[M] (M вводится с клавиатуры). Необходимо удалить из массива четные или нечетные значения. Пользователь вводит данные в массив, а также с помощью меню решает, что нужно удалить. 
Решение:
#include <iostream>
 
using namespace std;
 
void InitArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
int x;
cout << "New element:";
cin >> x;
*(arr + i) = x;
}
}
 
void ShowArray(int* arr, int size) {
for (int i = 0; i < size; i++) {
cout << *(arr + i) << '\t';
if ((i + 1) % 10 == 0)
cout << endl;
}
cout << endl;
}
 
int CountNotDeletedElements(int* arr, int size, char select) {
int count = 0;
switch (select) {
case '1':
for (int i = 0; i < size; i++) {
if (arr[i] % 2 != 0)
count++;
}
break;
case '2':
for (int i = 0; i < size; i++) {
if (arr[i] % 2 == 0)
count++;
}
break;
default:
return -1;
break;
}
return count;
}
 
void DeleteElements(int arr[], int size, int newArr[], char select) {
int count = 0;
switch (select) {
case '1':
for (int i = 0; i < size; i++) {
if (arr[i] % 2 != 0) {
newArr[count] = arr[i];
count++;
}
}
break;
case '2':
for (int i = 0; i < size; i++) {
if (arr[i] % 2 == 0) {
newArr[count] = arr[i];
count++;
}
}
break;
default:
exit(100);
}
}
 
int main() {
int M;
int* A;
 
cout << "Enter size of array: \n";
cin >> M;
 
A = new int[M];
 
cout << "\nInit array:\n";
InitArray(A, M);
 
cout << "\nArray:\n";
ShowArray(A, M);

cout << "\nSelect to delete:\n";
cout << "1. even\n";
cout << "2. odd\n";
 
char select;
cin >> select;	
 
int newSize = CountNotDeletedElements(A, M, select);
 
int* newArr = new int[newSize];
 
DeleteElements(A, M, newArr, select);
 
delete[]A;
A = nullptr;
 
ShowArray(newArr, newSize);
 
return 0;
}

Задание 6: 					
Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив. 
Решение:
#include <iostream>
 
using namespace std;
 
void ShowArr(int arr[], int size) {
for (int i = 0; i < size; i++) {
cout << arr[i] << ' ';
}
cout << endl;
}
 
bool IsPrimeNumber(int number) {
for (int i = 2; i < number; i++) {
if (number % i == 0)
return false;
}
return true;
}
 
int CountNonPrimeNumbers(int arr[], int size) {
int count = 0;
for (int i = 0; i < size; i++) {
if (!IsPrimeNumber(arr[i]))
count++;
}
return count;
}
 
int* DelPrimeNumbers(int arr[], int *size) {
int count = 0;
int newSize = CountNonPrimeNumbers(arr, *size);
int* newArr = new int[newSize];
for (int i = 0; i < *size; i++) {
if (!IsPrimeNumber(arr[i])) {
newArr[count] = arr[i];
count++;
}
}
*size = newSize;
return newArr;
}
 
int main() {
int* size = new int (12);
int* arr = new int[*size] {1, 1000, 2, 3, 4, 5, 6, 7, 8, 9, 100, 137};
 
cout << "Start array:\n";
ShowArr(arr, *size);

int* newArr = DelPrimeNumbers(arr, size);
 
delete[]arr;
 
cout << "\nArray with prime numbers deleted:\n";
ShowArr(newArr, *size);
}

Задание 7:
Написать функцию, которая получает указатель на статический массив и его размер. Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы.
Решение:
#include <iostream>
 
using namespace std;
 
void ShowArr(int arr[], int size) {
for (int i = 0; i < size; i++) {
cout << arr[i] << ' ';
}
cout << endl;
}
 
void SortBySign(int* arr, int size) {
int* positiveNumbers = new int[size];
int* negativeNumbers = new int[size];
int* zeroNumbers = new int[size];
 
int countPos = 0;
int countNeg = 0;
int countZero = 0;
 
for (int i = 0; i < size; i++) {
if (arr[i] > 0) {
positiveNumbers[countPos] = arr[i];
countPos++;
}
else if (arr[i] < 0) {
negativeNumbers[countNeg] = arr[i];
countNeg++;
}
else {
zeroNumbers[countZero] = arr[i];
countZero++;
}
}
 
cout << "\nPositive numbers:\n";
ShowArr(positiveNumbers, countPos);
cout << "\nNegative numbers:\n";
ShowArr(negativeNumbers, countNeg);
cout << "\nZero:\n";
ShowArr(zeroNumbers, countZero);
 
delete[]positiveNumbers;
delete[]negativeNumbers;
delete[]zeroNumbers;
 
}
 
int main() {
const int SIZE = 10;
int arr[SIZE] = { 11, -18, 98, 33, 0, -1, -44, 7, 0, 475 };
 
ShowArr(arr, SIZE);
 
SortBySign(arr, SIZE);
}


Тема: Строки
 
Задание 1:
Написать функцию, которая удаляет из строки символ с заданным номером.
Решение:
#include <iostream>
 
using namespace std;
 
char* DeleteLetter(char* word, int position) {
if (strlen(word) < position) {
cout << "Too big number";
exit(100);
}
else {
for (int i = position - 1; i < strlen(word); i++) {
word[i] = word[i + 1];
}
}
return word;
}
 
int main() {
char word[] = "For test words";
int posToDel;
cout << word << endl;
cout << "Enter position to delete: ";
cin >> posToDel;
 
cout << "Word with deleted letter:" << endl;
cout << DeleteLetter(word, posToDel) << endl;
}

Задание 2:
Написать функцию, которая удаляет из строки все вхождения в нее заданного символа.
Решение:
#include <iostream>
 
using namespace std;
 
int SizeNewText(char text[], char charToDel) {
int count = 0;
for (int i = 0; i < strlen(text); i++) {
if (text[i] != charToDel)
count++;
}
return count + 1;
}
 
void DeleteChars(char* oldText, char* newText, char toDelChar) {
int countForNewText = 0;
for (int i = 0; i < strlen(oldText); i++) {
if (oldText[i] != toDelChar) {
newText[countForNewText] = oldText[i];
countForNewText++;
}
}
}
 
int main() {
char text[] = "For test words";
char charToDel;
cout << text << endl;
cout << "Enter character to delete: ";
cin >> charToDel;
 
char* newText = new char[SizeNewText(text, charToDel)]{};
DeleteChars(text, newText, charToDel);
cout << "Text with deleted letters:" << endl;
cout << newText << endl;
}

Задание 3: 					
Написать функцию, которая вставляет в строку в указанную позицию заданный символ.
Решение:
#include <iostream>
 
using namespace std;
 
char* InputCharacter(char oldText[], char element, int position) {
int count = 0;
int newSize = (strlen(oldText) + 2);
char* newText = new char[newSize];
for (int i = 0; i < newSize; i++) {
if (i < position) {
newText[i] = oldText[count];
count++;
}
else if (i == position) {
newText[i] = element;
}
else {
newText[i] = oldText[count];
count++;
}
}
return newText;
}
 
int main() {
char text[] = "For test words";
char charToInput;
int pos;
cout << text << endl;
cout << "Enter character to input: ";
cin >> charToInput;
cout << "Enter position(max = " << strlen(text) << "): ";
cin >> pos;
 
char* newText = InputCharacter(text, charToInput, pos);
cout << newText << endl;
}

Задание 4:					
Написать программу, которая заменяет все символы точки "." в строке, введенной пользователем, на символы восклицательного знака "!". 
Решение:
#include <cstdio>
 
using namespace std;
 
int main() {
char userText[256];
puts("Enter string: ");
gets_s(userText);
 
int i = 0;
while (userText[i] != '\0') {
if (userText[i] == '.') {
userText[i] = '!';
}
i++;
}
 
puts(userText);
}

Задание 5:
Пользователь вводит строку символов и искомый символ, посчитать сколько раз он встречается в строке. 
Решение:
#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main() {
char userText[256];
char charToFind;
puts("Enter string: ");
gets_s(userText);
puts("Enter character to find: ");
cin >> charToFind;
 
int i = 0;
int count = 0;
while (userText[i] != '\0') {
if (userText[i] == charToFind)
count++;
i++;
}
 
cout << "Count of finded characters: " << count << endl;
}

Задание 6:
Пользователь вводит строку. Определить количество букв, количество цифр и количество остальных символов, присутствующих в строке.

Рекомендации:					
Для проверки, что символ является числом, не обязательно сравнивать его со всеми 10-ю цифрами, достаточно сравнить код символа с диапазоном кодов цифр. Код символа 0 – 48, 1 – 49, 2 – 50 .... 9 – 57.
Решение:
#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main() {
char userText[256];
puts("Enter string: ");
gets_s(userText);
 
int countElseCharacters = 0;
int countLetters = 0;
int countNumbers = 0;
int i = 0;
int count = 0;
while (userText[i] != '\0') {
int code = userText[i];
if (code >= 48 &&
code <= 57 ||
code >= -208 &&
code <= -199)
countNumbers++;
else if (code >= 65 &&
code <= 90 ||
code >= 97 &&
code <= 122 ||
code >= 128 &&
code <= 175 ||
code >= 224 &&
code <= 241 ||
code >= -191 &&
code <= -166 ||
code >= -159 &&
code <= -134 ||
code >= -128 &&
code <= -81 ||
code >= -32 &&
code <= -15)
countLetters++;
else countElseCharacters++;
i++;
}
 
cout << "Count of letters: " << countLetters << endl;
cout << "Count of numbers: " << countNumbers << endl;
cout << "Count of else characters: " << countElseCharacters << endl;
}

Задание 7:
Дана строка символов. Заменить в ней все пробелы на табуляции. 
Решение:
#include <iostream>
 
using namespace std;
 
int main() {
setlocale(0, "");
char text[] = "1. Тест of counts";
 
cout << text << endl;
 
int i = 0;
while (text[i] != '\0') {
if (text[i] == ' ')
text[i] = '\t';
i++;
}
 
cout <<  text << endl;
}

Задание 8: 
Дана строка символов. Определить количество букв, цифр и остальных символов, присутствующих в строке.
Решение:
#include <cstdio>
#include <iostream>
 
using namespace std;
 
int main() {
setlocale(0, "");
char text[] = "1. Тест of counts";
 
cout << text << endl;
 
int countElseCharacters = 0;
int countLetters = 0;
int countNumbers = 0;
int i = 0;
int count = 0;
while (text[i] != '\0') {
int code = text[i];
if (code >= 48 &&
code <= 57 ||
code >= -208 &&
code <= -199)
countNumbers++;
else if (code >= 65 &&
code <= 90 ||
code >= 97 &&
code <= 122 ||
code >= 128 &&
code <= 175 ||
code >= 224 &&
code <= 241 ||
code >= -191 &&
code <= -166 ||
code >= -159 &&
code <= -134 ||
code >= -128 &&
code <= -81 ||
code >= -32 &&
code <= -15)
countLetters++;
else countElseCharacters++;
i++;
}
 
cout << "Count of letters: " << countLetters << endl;
cout << "Count of numbers: " << countNumbers << endl;
cout << "Count of else characters: " << countElseCharacters << endl;
}

Задание 9: 
Подсчитать количество слов во введенном предложении. 
Решение:
#include <iostream>
#include <stdio.h>
 
using namespace std;
 
bool IsLetter(char letter) {
int code = letter;
if (code >= 65 &&
 
code <= 90 ||
 
code >= 97 &&
 
code <= 122 ||
 
code >= 128 &&
 
code <= 175 ||
 
code >= 224 &&
 
code <= 241 ||
 
code >= -191 &&
 
code <= -166 ||
 
code >= -159 &&
 
code <= -134 ||
 
code >= -128 &&
 
code <= -81 ||
 
code >= -32 &&
 
code <= -15)
return true;
else return false;
}
 
int main() {
setlocale(0, "");
char text[256];
 
puts("Введите предложение:\n");
gets_s(text);
 
int count = 0;
int i = 0;
while (text[i] != '\0') {
if (IsLetter(text[i]) &&
!IsLetter(text[i + 1]))
count++;
i++;
}

cout << count << endl;
}

Задание 10: 
Дана строка символов. Необходимо проверить является ли эта строка палиндромом.
Решение:
#include <iostream>
 
using namespace std;
 
bool IsPalindrom(char* text) {
char reverseText [6];
strcpy_s(reverseText, text);
_strrev(reverseText);

for (int i = 0; i < strlen(text); i++) {
if (text[i] != reverseText[i])
return false;
}
return true;
}
 
int main() {
setlocale(0, "");
char text1[6] = "доход";
char text2[6] = "Добор";

cout << "Строка " << text1;
IsPalindrom(text1) ? cout << " палиндром." : cout << " не палиндром.";
cout << endl << endl;
cout << "Строка " << text2;
IsPalindrom(text2) ? cout << " палиндром." : cout << " не палиндром.";
cout << endl;
}