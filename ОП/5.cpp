Домашнее задание

Тема: Функции. Перегрузка функций
Задание 1:
Написать перегруженные функции (int, double, char) для выполнения следующих задач:
Инициализация квадратной матрицы;
Вывод матрицы на экран;
Определение максимального и минимального элемента на главной диагонали матрицы;
Сортировка элементов по возрастанию отдельно для каждой строки матрицы.
Решение:
#include <iostream>
#define SIZE 4

using namespace std;

void InitializationOfMatrix ( int matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        matrix[i][j] = rand() % 100;
        }
    }
}

void InitializationOfMatrix ( double matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
                matrix[i][j] = rand() % 10000 / 100.;
        }
    }
}

void InitializationOfMatrix (char matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 93 + 33;
        }
    }
}

void ShowMatrix (int matrix[][SIZE]) {
    cout << "Int Matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j=0; j< SIZE; j++) {
        cout << matrix[i][j] << '\t';
    }
        cout << endl;
    }
    cout << endl << endl;
}

void ShowMatrix (double matrix[SIZE][SIZE]) {
    cout << "Double Matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl << endl;
}

void ShowMatrix (char matrix[SIZE][SIZE]) {
    cout << "Char Matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
        cout << matrix[i][j] << '\t';
    }
        cout << endl;
    }
    cout << endl << endl;
}

void MinMaxElement (int matrix[SIZE][SIZE]) {
    int minElement = matrix[0][0];
    int maxElement = matrix[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                if (minElement > matrix[i][j]) {
                    minElement = matrix[i][j];
                }
                if (maxElement < matrix[i][j]) {
                    maxElement = matrix[i][j];
                }
            }
        }
    }
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl << endl;
}

void MinMaxElement (double matrix[SIZE][SIZE]) {
    double minElement = matrix[0][0];
    double maxElement = matrix[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                if (minElement > matrix[i][j]) {
                    minElement = matrix[i][j];
                }
                if (maxElement < matrix[i][j]) {
                    maxElement = matrix[i][j];
                }
            }
        }
    }
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl << endl;
}

void MinMaxElement (char matrix[SIZE][SIZE]) {
    char minElement = matrix[0][0];
    char maxElement = matrix[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                if (minElement > matrix[i][j]) {
                    minElement = matrix[i][j];
                }
                if (maxElement < matrix[i][j]) {
                    maxElement = matrix[i][j];
                }
            }
        }
    }
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl << endl;
}

void SortRows (int matrix[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++) {
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (matrix[row][j] > matrix[row][j + 1]) {
                int tmp = matrix[row][j];
                matrix[row][j] = matrix[row][j + 1];
                matrix[row][j+1] = tmp;
            }
        }
                                 }
    }
    
    cout << "Построчная сортировка ";
    ShowMatrix(matrix);
}

void SortRows (double matrix[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++) {
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (matrix[row][j] > matrix[row][j + 1]) {
                int tmp = matrix[row][j];
                matrix[row][j] = matrix[row][j + 1];
                matrix[row][j+1] = tmp;
            }
        }
                                 }
    }
    
    cout << "Построчная сортировка ";
    ShowMatrix(matrix);
}

void SortRows (char matrix[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++) {
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (matrix[row][j] > matrix[row][j + 1]) {
                int tmp = matrix[row][j];
                matrix[row][j] = matrix[row][j + 1];
                matrix[row][j+1] = tmp;
            }
        }
                                 }
    }
    
    cout << "Построчная сортировка ";
    ShowMatrix(matrix);
}

int main() {
    setlocale(LC_ALL, ("Russian"));
    srand((unsigned int)time(NULL));
    
    int matrixInt[SIZE][SIZE];
    double matrixDouble[SIZE][SIZE];
    char matrixChar[SIZE][SIZE] = {0};
    
    // Инициализация матриц
    InitializationOfMatrix(matrixInt);
    InitializationOfMatrix(matrixDouble);
    InitializationOfMatrix(matrixChar);
    
    // Вывод матриц на экран
    ShowMatrix(matrixInt);
    ShowMatrix(matrixDouble);
    ShowMatrix(matrixChar);
    
    // Определение максимального и минимального элемента на главной диагонали
    cout << "В главной диагонали матрицы Int:" << endl;
    MinMaxElement(matrixInt);
    cout << "В главной диагонали матрицы Double:" << endl;
    MinMaxElement(matrixDouble);
    cout << "В главной диагонали матрицы Char:" << endl;
    MinMaxElement(matrixChar);
    
    cout << endl;
    
    SortRows(matrixInt);
    SortRows(matrixDouble);
    SortRows(matrixChar);
    
    return 0;
}

Задание 2: 
Написать перегруженные функции и протестировать их в основной программе:
Нахождения максимального значения в одномерном массиве; 
Нахождения максимального значения в двумерном массиве; 
Нахождения максимального значения в трёхмерном массиве; 
Нахождения максимального значения двух целых; 
Нахождения максимального значения трёх целых.
Решение:
#include <iostream>


#define SIZE 5


using namespace std;


int maxElementInArray(int array[]) {
    int maxElement = array[0];
    for (int i = 0; i < SIZE; i++) {
        if (maxElement < array[i]) {
            maxElement = array[i];
        }
    }
    return maxElement;
}


int maxElementInArray(int array[][SIZE]) {
    int maxElement = array[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maxElement < array[i][j]) {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}


int maxElementInArray(int array[][SIZE][SIZE]) {
    int maxElement = array[0][0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (maxElement < array[i][j][k]) {
                    maxElement = array[i][j][k];
                }
            }
        }
    }
    return maxElement;
}


double maxElementInArray(double array[]) {
    double maxElement = array[0];
    for (int i = 0; i < SIZE; i++) {
        if (maxElement < array[i]) {
            maxElement = array[i];
        }
    }
    return maxElement;
}


double maxElementInArray(double array[][SIZE]) {
    double maxElement = array[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maxElement < array[i][j]) {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}


double maxElementInArray(double array[][SIZE][SIZE]) {
    double maxElement = array[0][0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (maxElement < array[i][j][k]) {
                    maxElement = array[i][j][k];
                }
            }
        }
    }
    return maxElement;
}


char maxElementInArray(char array[]) {
    char maxElement = array[0];
    for (int i = 0; i < SIZE; i++) {
        if (maxElement < array[i]) {
            maxElement = array[i];
        }
    }
    return maxElement;
}


char maxElementInArray(char array[][SIZE]) {
    char maxElement = array[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maxElement < array[i][j]) {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}


char maxElementInArray(char array[][SIZE][SIZE]) {
    char maxElement = array[0][0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (maxElement < array[i][j][k]) {
                    maxElement = array[i][j][k];
                }
            }
        }
    }
    return maxElement;
}


int maxElement (int e1, int e2) {
    if (e1 > e2) {
        return e1;
    } else {
        return e2;
    }
    
}


int maxElement (int e1, int e2, int e3) {
    int max = e1;
    if (max < e2)
        max = e2;
    if (max < e3)
        max = e3;
    return  max;
}


int main() {
    setlocale(LC_ALL, ("Russian"));
    srand((unsigned int)time(NULL));
    
    // Инициализация одномерных массивов
    int arrayInt[SIZE] = {0};
    double arrayDouble[SIZE] = {0};
    char arrayChar[SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        arrayInt[i] = rand() % 100;
        arrayDouble[i] = rand() % 100 / 10.;
        arrayChar[i] = rand() % 93 + 33;
        
    }
    
    // Вывод одномерных массивов
    cout << "Максимальное значение в одномерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(arrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(arrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(arrayChar) << endl;
    
    // Инициализация двумерных массивов
    int doubleArrayInt[SIZE][SIZE] = {0};
    double doubleArrayDouble[SIZE][SIZE] = {0};
    char doubleArrayChar[SIZE][SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            doubleArrayInt[i][j] = rand() % 100;
            doubleArrayDouble[i][j] = rand() % 100 / 10.;
            doubleArrayChar[i][j] = rand() % 93 + 33;
        }
    }
    
    // Вывод двумерных массивов
    cout << "\nМаксимальное значение в двумерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(doubleArrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(doubleArrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(doubleArrayChar) << endl;
    
    // Инициализация трехмерных массивов
    int tripleArrayInt[SIZE][SIZE][SIZE] = {0};
    double tripleArrayDouble[SIZE][SIZE][SIZE] = {0};
    char tripleArrayChar[SIZE][SIZE][SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                tripleArrayInt[i][j][k] = rand() % 100;
                tripleArrayDouble[i][j][k] = rand() % 100 / 10.;
                tripleArrayChar[i][j][k] = rand() % 93 + 33;
            }
        }
    }
    
    // Вывод трехмерных массивов
    cout << "\nМаксимальное значение в трехмерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(tripleArrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(tripleArrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(tripleArrayChar) << endl;
    
    int firstElement = rand() % 100;
    int secondElement = rand() % 100;
    int thirdElement = rand() % 100;
    
    cout << "\nИз " << firstElement << " и " << secondElement << " больше: " << maxElement(firstElement, secondElement) << endl;
    cout << "Из " << firstElement << ", " << secondElement << " и ";
    cout << thirdElement << " больше: " << maxElement(firstElement, secondElement, thirdElement) << endl;   
    return 0;
}

Задание 3:
Измените программы из первого и второго задания с помощью шаблонов
Решение:
#include <iostream>

#define SIZE 5

using namespace std;

int returnRandomValue (int element) {
    return rand() % 100;
}

double returnRandomValue (double element) {
    return rand() % 100 / 10.;
}

char returnRandomValue (char element) {
    return rand() % 93 + 33;
}

template <typename TypeOfMatrix>
void InitializationOfMatrix ( TypeOfMatrix matrix[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = returnRandomValue(matrix[0][0]);
        }
    }
}

template <typename TypeOfMatrix>
void ShowMatrix (TypeOfMatrix matrix[][SIZE]) {
    cout <<" Matrix:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j=0; j< SIZE; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl << endl;
}

template <typename TypeOfMatrix>
void MinMaxElement (TypeOfMatrix matrix[SIZE][SIZE]) {
    
    TypeOfMatrix minElement = matrix[0][0];
    TypeOfMatrix maxElement = matrix[0][0];
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == j) {
                if (minElement > matrix[i][j]) {
                    minElement = matrix[i][j];
                }
                if (maxElement < matrix[i][j]) {
                    maxElement = matrix[i][j];
                }
            }
        }
    }
    cout << "Минимальный элемент: " << minElement << endl;
    cout << "Максимальный элемент: " << maxElement << endl << endl;
}

template <typename TypeOfMatrix>
void SortRows (TypeOfMatrix matrix[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++) {
        for (int i = SIZE - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                if (matrix[row][j] > matrix[row][j + 1]) {
                    int tmp = matrix[row][j];
                    matrix[row][j] = matrix[row][j + 1];
                    matrix[row][j+1] = tmp;
                }
            }
        }
    }
    
    cout << "Построчная сортировка ";
    ShowMatrix(matrix);
}

template <typename TypeOfArray>
TypeOfArray maxElementInArray(TypeOfArray array[]) {
    TypeOfArray maxElement = array[0];
    for (int i = 0; i < SIZE; i++) {
        if (maxElement < array[i]) {
            maxElement = array[i];
        }
    }
    return maxElement;
}

template <typename TypeOfArray>
TypeOfArray maxElementInArray(TypeOfArray array[][SIZE]) {
    TypeOfArray maxElement = array[0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (maxElement < array[i][j]) {
                maxElement = array[i][j];
            }
        }
    }
    return maxElement;
}

template <typename TypeOfArray>
TypeOfArray maxElementInArray(TypeOfArray array[][SIZE][SIZE]) {
    TypeOfArray maxElement = array[0][0][0];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                if (maxElement < array[i][j][k]) {
                    maxElement = array[i][j][k];
                }
            }
        }
    }
    return maxElement;
}

template <typename T>
T returnMaxElement (T e1, T e2) {
    return e1 > e2 ? e1 : e2;   
}

template <typename T>
T returnMaxElement (T e1, T e2, T e3) {
    T max = e1 > e2 ? e1 : e2;
    return  max > e3 ? max : e3;
}

int main() {
    setlocale(LC_ALL, ("Russian"));
    srand((unsigned int)time(NULL));
    
    int matrixInt[SIZE][SIZE];
    double matrixDouble[SIZE][SIZE];
    char matrixChar[SIZE][SIZE] = {0};
    
    // Инициализация матриц
    InitializationOfMatrix(matrixInt);
    InitializationOfMatrix(matrixDouble);
    InitializationOfMatrix(matrixChar);
    
    // Вывод матриц на экран
    ShowMatrix(matrixInt);
    ShowMatrix(matrixDouble);
    ShowMatrix(matrixChar);
    
    // Определение максимального и минимального элемента на главной диагонали
    cout << "В главной диагонали матрицы Int:" << endl;
    MinMaxElement(matrixInt);
    cout << "В главной диагонали матрицы Double:" << endl;
    MinMaxElement(matrixDouble);
    cout << "В главной диагонали матрицы Char:" << endl;
    MinMaxElement(matrixChar);
    cout << endl;
    
    SortRows(matrixInt);
    SortRows(matrixDouble);
    SortRows(matrixChar);
    
    // Инициализация одномерных массивов
    int arrayInt[SIZE] = {0};
    double arrayDouble[SIZE] = {0};
    char arrayChar[SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        arrayInt[i] = rand() % 100;
        arrayDouble[i] = rand() % 100 / 10.;
        arrayChar[i] = rand() % 93 + 33;
    }
    
    // Вывод одномерных массивов
    cout << "Максимальное значение в одномерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(arrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(arrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(arrayChar) << endl;
    
    // Инициализация двумерных массивов
    int doubleArrayInt[SIZE][SIZE] = {0};
    double doubleArrayDouble[SIZE][SIZE] = {0};
    char doubleArrayChar[SIZE][SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            doubleArrayInt[i][j] = rand() % 100;
            doubleArrayDouble[i][j] = rand() % 100 / 10.;
            doubleArrayChar[i][j] = rand() % 93 + 33;
        }
    }
    
    // Вывод двумерных массивов
    cout << "\nМаксимальное значение в двумерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(doubleArrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(doubleArrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(doubleArrayChar) << endl;
    
    // Инициализация трехмерных массивов
    int tripleArrayInt[SIZE][SIZE][SIZE] = {0};
    double tripleArrayDouble[SIZE][SIZE][SIZE] = {0};
    char tripleArrayChar[SIZE][SIZE][SIZE] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                tripleArrayInt[i][j][k] = rand() % 100;
                tripleArrayDouble[i][j][k] = rand() % 100 / 10.;
                tripleArrayChar[i][j][k] = rand() % 93 + 33;
            }
        }
    }
    
    // Вывод трехмерных массивов
    cout << "\nМаксимальное значение в трехмерном массиве:" << endl;
    cout << "из значений Int: " << maxElementInArray(tripleArrayInt) << endl;
    cout << "из значений Double: " << maxElementInArray(tripleArrayDouble) << endl;
    cout << "из значений Char: " << maxElementInArray(tripleArrayChar) << endl;
    
    int firstElement = rand() % 100;
    int secondElement = rand() % 100;
    int thirdElement = rand() % 100;
    
    cout << "\nИз " << firstElement << " и " << secondElement << " больше: " << returnMaxElement(firstElement, secondElement) << endl;
    cout << "Из " << firstElement << ", " << secondElement << " и ";
    cout << thirdElement << " больше: " << returnMaxElement(firstElement, secondElement, thirdElement) << endl;   
    return 0;
}

Тема: Сортировка массивов
Задание 1:
Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырьковой сортировки.
Решение:
#include <iostream>

using namespace std;

int main() {
    
    const int SIZE = 10;
    int numbers[SIZE] = {3, 7, 6, 9, 1, 5, 4, 8, 5, 2};
    
    for (int i = SIZE - 1; i > 0; i--) {
        for (int j = 1; j < SIZE; j++) {
            if (numbers[j] < numbers[j - 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
    }
    
    cout << "Отсортированный список:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

Задание 2:
Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок. 
Решение:
#include <iostream>

using namespace std;

int main() {
    
    const int SIZE = 10;
    int numbers[SIZE] = {3, 7, 6, 9, 1, 5, 4, 8, 5, 2};
    
    cout << "Первоначальный список:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    
    for (int i = 1; i < SIZE; i++) {
        for (int j = i; j > 0 && numbers[j - 1] > numbers [j]; j--) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
        }
    }
    
    cout << "Отсортированный список методом вставки:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

Задание 3:
Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать меню для пользователя:
Вывод оценок (вывод содержимого массива)
Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку)
Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7)
Решение:
#include <iostream>

using namespace std;

void ShowGrades (int arrayOfGrades[]) {
    cout << "\nСписок оценок:\n";
    for (int i = 0; i < 10; i++) {
        cout << arrayOfGrades[i] << ' ';
    }
    cout << endl;
}

void UpdateGrades (int arrayOfGrades[]) {
    int element, newGrade;
    cout << "Введите номер оценки\n";
    cin >> element;
    cout << "Введите новую оценку\n";
    cin >> newGrade;
    arrayOfGrades[element - 1] = newGrade;
}

bool IsGrant (int arrayOfGrades[]) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += arrayOfGrades[i];
    }
    return (sum / 10. > 10.7 ? true : false);
}

int main() {
    
    setlocale(0, ("Ru"));
    
    int grades[10];
    int select = 0;
    
    cout << "Программа \"успеваемость\"\n";
    cout << "Введите 10 оценок студента:\n";
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". ";
        cin >> grades[i];
    }
    
    while (select != 4) {
        cout << "\nПрограмма \"успеваемость\"\n";
        cout << "1. Вывод оценок\n";
        cout << "2. Пересдача экзамена\n";
        cout << "3. Выходит ли стипендия?\n";
        cout << "4. Выход\n";
        cin >> select;
        
        switch (select) {
            case 1:
                ShowGrades(grades);
                break;
            case 2:
                UpdateGrades(grades);
                break;
            case 3:
                IsGrant(grades)?
                cout << "Достоин стипендии\n" :
                cout << "Никакой стипендии\n";
                break;
            case 4:
                return 0;
            default:
                cout << "Неверный ввод, повторите...\n";
                cin >> select;
        }
    }
    return 0;
}

Задание 4:
Необходимо отсортировать первые две трети массива в порядке возрастания, если среднее арифметическое всех элементов больше нуля; иначе - лишь первую треть. Остальную часть массива не сортировать, а расположить в обратном порядке.
Решение:
#include <iostream>

using namespace std;

int main() {
    
    srand((unsigned int)(time(NULL)));
    setlocale(0, ("Ru"));
    
    const int SIZE = 10;
    int numbers[SIZE];
    int sum = 0;
    
    cout << "Первоначальный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100 - 50;
        sum += numbers[i];
        cout << numbers[i] << ' ';
    }
    
    cout << endl;
    
    int newSize = (sum / (double)SIZE > 0) ? SIZE * 2 / 3. : SIZE / 3.;
    
    for (int i = 1; i < newSize; i++) {
        for (int j = i; j > 0 && numbers[j - 1] > numbers [j]; j--) {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
        }
    }
    
    int startOfSecondPart = newSize;
    int endOfArray = SIZE - 1;
    int temp;
    while (startOfSecondPart < endOfArray) {
        temp = numbers[startOfSecondPart];
        numbers[startOfSecondPart] = numbers[endOfArray];
        numbers[endOfArray] = temp;
        startOfSecondPart++;
        endOfArray--;
    }
    
    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
    
    return 0;
}