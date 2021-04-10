Тема Массивы
//Домашняя работа №3 Тема: Циклы

// Задание 1 Вывести на экран фигуры заполненные звездочками. Диалог при помощи меню


#include <iostream>    // Это начало для всех программа ниже
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");




   int N ;// N - размерностьтаблицы
   int menu_1;
   restart:
   cout << " Введите размер таблицы NхN \n ";
   cin >> N;
   cout << endl;

   cout << "МЕНЮ ДЛЯ ВЫБОРА ФИГУРЫ";
   cout << endl;
   cout << "0- Область над главной диагональю\n";
   cout << "1- Область  под главной диагональю\n";
   cout << "2- Четверть сверху \n";
   cout << "3- Четверть снизу \n";
   cout << "4- Четверть сверху и снизу \n";
   cout << "5- Четверть слева и справа \n";
   cout << "6- Четверть слева  \n";
   cout << "7- Четверть справа \n";
   cout << "8- Область над побочной диагональю\n";
   cout << "9- Область  под побочной диагональю\n";
   cout << endl;

   cout << " Введите цифру от 0 до 9 для выбора фигуры \n ";
   cin >> menu_1;
   cout << endl;
   switch (menu_1)
   {
       
    
   case(0):
    
        cout << " Над главной диагональю i < j \n ";
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //главная диагональ
                if (i < j)
                    cout << " * ";
                else
                    cout << " = ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(1):
    
        cout << "  Под главной диагональю i > j \n ";
        cout << endl;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                //главная диагональ
                if (i > j)
                    cout << " * ";
                else
                    cout << " = ";
            }
            cout << endl;
        }
        cout << endl;
        break;

    cout << " Побочная диагональ(i + j == N - 1) \n ";
    cout << endl;
    // N - размерность таблицы
    for (int i = 0;i < N; i++)

    {
        for (int j = 0; j < N; j++)

        {
            //побочная диагональ
            if (i + j == N - 1)
                cout << " + ";
            else
                cout << " = ";
        }
        cout << endl;
    }
    cout << endl;

   case(8):
    
        cout << "Над побочная диагональ(i + j < N - 1) \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ
                if ((i + j < N - 1) || (i + j == N - 1))
                    cout << " * ";
                else
                    cout << " = ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(9):
    
        cout << "Под побочная диагональ(i + j > N - 1) \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ
                if ((i + j > N - 1) || (i + j == N - 1))
                    cout << " * ";
                else
                    cout << " = ";
            }
            cout << endl;
        }
        cout << endl;
        break;


   case(7):
    
        cout << " Четверть справа \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ (i + j == N - 1) главная диагональ (i == j)
                if ((i + j < N - 1) || (i > j))
                    cout << " - ";
                else
                    cout << " * ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(6):
    
        cout << " Четверть слева \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ (i + j == N - 1) главная диагональ (i == j)
                if ((i + j > N - 1) || (i < j))
                    cout << " - ";
                else
                    cout << " * ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(2):
    
        cout << " Четверть сверху \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ (i + j == N - 1) главная диагональ (i == j)
                //(i + j > N - 1) || (i < j) || (i + j > N - 1) || (i > j)
                if ((i > j) || (i + j > N - 1))
                    cout << " - ";
                else
                    cout << " * ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(3):
    
        cout << " Четверть снизу \n ";
        cout << endl;
        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {
                //побочная диагональ (i + j == N - 1) главная диагональ (i == j)
                //(i + j > N - 1) || (i < j) || (i + j > N - 1) || (i > j)
                if ((i < j) || (i + j < N - 1))
                    cout << " - ";
                else
                    cout << " * ";
            }
            cout << endl;
        }
        cout << endl;
        break;

   case(4):
    
        cout << " верхняя и нижняя четверть \n ";
        cout << endl;

        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {

                if (i < N / 2)
                {
                    if ((i > j) || (i + j > N - 1))
                        cout << " - ";
                    else
                        cout << " * ";
                }

                else
                {
                    if ((i < j) || (i + j < N - 1))
                        cout << " - ";
                    else
                        cout << " * ";
                }

            }
            cout << endl;
        }
        cout << endl;

        break;

   case(5):
    
        cout << " левая и правая четверть \n ";
        cout << endl;

        // N - размерность таблицы
        for (int i = 0; i < N; i++)

        {
            for (int j = 0; j < N; j++)

            {

                if (j < N / 2)
                {
                    if ((i + j > N - 1) || (i < j))
                        cout << " - ";
                    else
                        cout << " * ";
                }

                else
                {
                    if ((i + j < N - 1) || (i > j))
                        cout << " - ";
                    else
                        cout << " * ";
                }

            }
            cout << endl;
        }
        cout << endl;
        break;

    
   }
   goto restart;
    return 0;
}






//Задание 2: Определить количество целых чисел в диапазоне от 100 до 999 у которых есть две одинаковые цифры


    setlocale(LC_ALL, "Russian");
    int number3, number2, number1, number1_2; //  переменные для хранения чисел
    /*
    number3 = number % 10; // 3я цифра
    number1_2 = number / 10;    // введенное число без 3го значения
    number2 = number1_2 % 10; // 2я цифра
    number1 = number1_2 / 10; // 1я цифра
    */
    int number; // переменная от 100 до 999

//restart:
    int REZ = 0;// переменная для определения количества целых чисел у которых есть две одинаковые цифры
    for (number = 100; number <= 999; number++)
    {
        number3 = number % 10; // 3я цифра
        number1_2 = number / 10;    // введенное число без 3го значения
        number2 = number1_2 % 10; // 2я цифра
        number1 = number1_2 / 10; // 1я цифра

       // cout << " первая цифра равна   " << number1 << "\n ";
       // cout << " вторая цифра равна   " << number2 << "\n ";
      //  cout << " третья цифра равна   " << number3 << "\n ";
        if ((number1 == number2) && (number1 == number3))
        {
            continue;
        }
        else
            if (number1 == number2)
            {
                cout << number1 << number2 << number3 << "\n ";
                REZ += 1;
            }
            else
                if (number1 == number3)
                {
                    cout << number1 << number2 << number3 << "\n ";
                    REZ += 1;
                }
                else
                    if (number2 == number3)
                    {
                        cout << number1 << number2 << number3 << "\n ";
                        REZ += 1;
                    }
    }
    cout << " количества целых чисел у которых есть две одинаковые цифры   " << REZ << "\n ";
   // goto restart;
    return 0;
}







//Задание 3: Определить количество целых чисел в диапазоне от 100 до 999 у которых все цифры разные
setlocale(LC_ALL, "Russian");
int number3, number2, number1, number1_2; //  переменные для хранения чисел
/*
number3 = number % 10; // 3я цифра
number1_2 = number / 10;    // введенное число без 3го значения
number2 = number1_2 % 10; // 2я цифра
number1 = number1_2 / 10; // 1я цифра
*/
int number; // переменная от 100 до 999

//restart:
    int REZ = 0;// переменная для определения количества целых чисел у которых все цифры разные
    for (number = 100; number <= 999; number++)
    {
        number3 = number % 10; // 3я цифра
        number1_2 = number / 10;    // введенное число без 3го значения
        number2 = number1_2 % 10; // 2я цифра
        number1 = number1_2 / 10; // 1я цифра

       // cout << " первая цифра равна   " << number1 << "\n ";
       // cout << " вторая цифра равна   " << number2 << "\n ";
      //  cout << " третья цифра равна   " << number3 << "\n ";
        if ((number1 != number2) && (number1 != number3) && (number2 != number3))
        {
            cout << number1 << number2 << number3 << "|";
            REZ += 1;
        }
        
    }
    cout << "\n количества целых чисел у которых все цифры разные равно   " << REZ << "\n ";
   // goto restart;
    return 0;
}


// Задание 4: Пользователь вводит любое целое число.
     //Необходимо из этого числа удалить все цифры 3 и 6 и вывести обратно

     int a; // вводимое значение
     int i=1; // переменная для хранения разряда числа
     int a_razryd;// переменная для хранения измененного числа а
     int znak=1;// переменная для хранения знака числа а
     int cifra_a; // цифра в числе a

     restart:
     cout << "\n";
     cout << "Введите любое целое число \n";
     cin >> a;
     // проверим число отрицательное ?
     (a < 0) ? znak = -1 : znak = 1;
     a *= znak;

     // определим введенное число меньше 10?

     if (a / i < 10)
     {
         if ((a == 6) || (a == 3))

             cout << "Если убрать из числа  " << a * znak << " цифру 3 или 6, то ничего не останется :) \n";
         else
             cout << "Цифры  3 или 6 в числе  " << a * znak << " отстутствуют \n";
     }

     if (a >= 10)// если введенное число больше 10 определяем разряд числа.
     {
         while (a / i != 0)// делим на 10 пока не получим 0
         {
             i *= 10;
         }
         i /= 10;

         // нашли разряд введенного числа, равен i/10
         // теперь разделим введенное число на цифры и уберем цифры 3 и 6

         a_razryd = a;// будем в переменной хранить число -а- без первой цифры

         // при выводе числа учтем знак введенного числа -а-
         (znak == -1) ? cout << "Если убрать из числа  " << a * znak << " цифру 3 или 6, то станет число -" :
             cout << "Если убрать из числа  " << a * znak << " цифру 3 или 6, то станет число ";

         for (i; i != 1; i /= 10)// делим число -а- пока не дойдем до последней цифры введенного числа ( при i=0)
         {
             cifra_a = a_razryd / i;
             if ((cifra_a == 3)|| (cifra_a == 6))
             {
                 a_razryd = a_razryd % i;

                 continue;
             }

                 else

                     cout << cifra_a; // выводим цифры введенного чмсла без 3и6

             a_razryd = a_razryd % i;
         }
         cifra_a = a_razryd / i; // проверим чему равна последняя цифра и выведем на экран
         if ((cifra_a == 3) || (cifra_a == 6))
             cout <<"\n";

        else
             cout << cifra_a;
         cout << "\n";
     }
     goto restart;
     return 0;
     }

// Задание 5: Пользователь вводит любое целое число А. 
     //Необходимо вывести все целые числа В для которых А делится без остатка В*B и не делится на В*В*В

    int A, B2,B3; // А - вводимое число
    // B2,B3 для хранения значений В*В и В*В*B
    B2 = 1;
    B3 = 1;
restart:
    cout << endl;
    cout << "  Введите любое число  \n ";
      cin >> A ;
      cout << endl;
      for (int i = 1; i <= A; i++)
      {
          B2 = i * i;
          B3 = B2 * i;
          if ((A % B2 == 0) && (A % B3 != 0))
              cout << "  Искомое число " << i << " \n " << " Число " << A 
              << " делится без остатка на  " << B2 << " и не делится без остатка на  " << B3 << " \n ";
      }
     if (B2==B3)
         cout << "  Число B для которого "  << A
         << " делится без остатка на  B*B   и не делится без остатка на B*B*B не найдено  \n ";
     cout << endl;
     goto restart;
    return 0;
}



// Задание 6: Пользователь вводит любое целое число.
     //Необходимо определить, что куб суммы цифр этого числа равен А*А

int a; // вводимое значение
int i = 1; // переменная для хранения разряда числа
int a_razryd;// переменная для хранения измененного числа а
int znak = 1;// переменная для хранения знака числа а
int cifra_a; // цифра в числе a
int summa_cifr; // для хранения суммы цифр

restart:
summa_cifr = 0;
cout << "\n";
cout << "Введите любое целое число \n";
cin >> a;
// проверим число отрицательное ?
(a < 0) ? znak = -1 : znak = 1;
a *= znak;

// определим введенное число меньше 10?

if (a / i < 10)
{

    cout << "сумма цифр равна " << a * znak << " \n";

}

if (a >= 10)// если введенное число больше 10 определяем разряд числа.
{
    while (a / i != 0)// делим на 10 пока не получим 0
    {
        i *= 10;
    }
    i /= 10;

    // нашли разряд введенного числа, равен i/10
    // теперь разделим введенное число на цифры и уберем цифры 3 и 6

    a_razryd = a;// будем в переменной хранить число -а- без первой цифры

    
    for (i; i != 1; i /= 10)// делим число -а- пока не дойдем до последней цифры введенного числа ( при i=0)
    {
        cifra_a = a_razryd / i;
        summa_cifr += cifra_a;
        a_razryd = a_razryd % i;
    }
    cifra_a = a_razryd / i; // проверим чему равна последняя цифра и выведем на экран
    
    summa_cifr += cifra_a;
    cout << " Сумма цифр равна " << summa_cifr  <<" \n";
}
(summa_cifr * summa_cifr * summa_cifr == a * a) ? cout << " Верно \n" 
<< " Куб суммы цифр равен квадрату введенного числа  " 
<< summa_cifr * summa_cifr * summa_cifr << "равно "<< a * a : cout << "Не верно \n " 
<< " Куб суммы цифр не равен квадрату введенного числа  "
<< summa_cifr * summa_cifr * summa_cifr << " не равно " << a * a;
cout << "\n";
goto restart;
return 0;
     }


//  Задание 7: Пользователь вводит любое целое число А. 
 //             Необходимо вывести все целые числа на  которые А делится без остатка

int A; // А - вводимое число
   
restart:
    cout << endl;
    cout << "  Введите любое число  \n ";
      cin >> A ;
      cout << endl;
      for (int i = 1; i <= A; i++)
      {
         
          if (A % i == 0) 
              cout << "  Искомое число " << i << " \n " << " Число " << A 
              << " делится без остатка на  " <<i  << " \n ";
      }
    
     cout << endl;
     goto restart;
    return 0;
}



//  Задание 8: Пользователь вводит два целых числа. 
// //            Необходимо вывести все целые числа на  которые оба введенных числа делятся без остатка

int chislo_1, chislo_2; // переменные для ввода чисел
int chislo_max; // определим максимальное число из введенных чисел. Это будет ограничение для цикла.
// вводим числа
restart:
cout << " ВВЕДИТЕ ДВА ЧИСЛА \n";

cin>> chislo_1;
cin>> chislo_2;
cout << endl;

// определим максимальное число из введенных чисел
(chislo_1 > chislo_2) ? chislo_max = chislo_1 : chislo_max = chislo_2;

// Зададим цикл, последовательно делим каждое число с шагом 1
// проверяем заданное условие

for (int i=1;i<= chislo_max;i++)
    {
    if ((chislo_1 % i == 0) && (chislo_2 % i == 0))
        cout << "Оба введенных числа делятся без остатка на число    " << i << "\n";
        
    }
cout << endl;
goto restart;
return 0;
}






// Задание 9: Пользователь вводит число.
//            Определить количество цифр в этом числе, посчитать их сумму и среднее арифметическое.
//              Определить количество нулей в этом числе.
//                  Общение с пользователем организовать в виде меню
restart:
int chislo; // введенное число
int kol_cifr = 0; // количество цифр в числе
int summa_cifr=0; // сумма цифр
float sred_ar=0.; // среднее арифметическое
bool konec_cikla = 0;
int rez_del_10, posl_cifra=0;
int menu_1;
int nul = 0;
// вводим число 

cout << " ВВЕДИТЕ ЧИСЛ0 \n";
cin>> chislo;
cout << endl;
// определим количество цифр будем делить число на 10, пока результат деления не станет равным 0
// переменную kol_cifr увеличиваем на 1 при каждом делении
rez_del_10 = chislo;
if ((chislo / 10) != 0)
{
    do
    {
        posl_cifra = rez_del_10 % 10;// последняя цифра числа
        summa_cifr += posl_cifra;
        
        if (rez_del_10 == 0) konec_cikla = 1;
        else
        {
            rez_del_10 /= 10;
          
            kol_cifr += 1;

            if (posl_cifra == 0) nul += 1;
        }


        
    } while (konec_cikla == 0);

}
else
{
    kol_cifr = 1;
    summa_cifr = chislo;
     if (chislo = 0) nul += 1;
}

sred_ar = float (summa_cifr) / float(kol_cifr);
restart_2:



cout << " Выберете необходимый результат , нажмите цифру согласно МЕНЮ  \n ";
cout << " 1  -  Количество цифр в числе  \n ";
cout << " 2  -  Сумма цифр в числе  \n ";
cout << " 3  -  Среднее арифметическое суммы цифр  \n ";
cout << " 4  -  Количество нулей в числе  \n ";
cout << " 0  -  Ввести следующее число   \n ";

cin >> menu_1;
cout << endl;

switch (menu_1)
{
case(0):
    goto restart;
    break;
case(1):
    cout << "  Количество цифр в числе = " << kol_cifr << "\n ";
    cout << endl;
  
    break;
case(2):
    cout << "  Сумма цифр в числе = " << summa_cifr << "\n ";
    cout << endl;
   
    break;
case(3):
    cout << "  Среднее арифметическое суммы цифр = " << sred_ar << "\n ";
    cout << endl;
   
    break;
case(4):
    cout << "  Количество нулей в числе = " <<nul  << "\n ";
    cout << endl;
   
    break;
default:
        goto restart_2;
    break;
}
//cout << kol_cifr <<"\n" << summa_cifr << "\n" << sred_ar;
cout << endl;
goto restart;
return 0;
}






// Задание 10 Написать программу, которая выводит на экран шахматную доску
//
restart:
   int N ;// N - размерностьтаблицы (строка)
   int N_N=0;// размерностьтаблицы (стобец)
   int K;// K - размерность клеток

   N = 9; // стандартная шахматная доска
     
   cout << " Выведем шахматную доску 9х9 клеток \n ";
   cout << " Введите размер клетки для шахматной доски \n ";
    cin >> K;
    cout << endl;

   do
   {
       if (N_N % 2 == 0)
       {
           for (int i = 0; i < K; i++)
           {

               for (int j = 0; j < N; j++)

               {

                   for (int m = 0; m < K; m++)
                   {
                       if (j % 2 == 0)  //&& (i%2==0)  ) 

                           cout << "*";
                       else

                           cout << "_";
                   }


               }


               cout << endl;
           }
       }
       else
       { 
       for (int i = 0; i < K; i++)
       {

           for (int j = 0; j < N; j++)

           {

               for (int m = 0; m < K; m++)
               {
                   if (j % 2 != 0)  //&& (i%2==0)  

                       cout << "*";
                   else

                       cout << "_";
               }


           }


           cout << endl;
       }
       }
       N_N += 1;
   } 
   while (N_N < 9);
   
   
   goto restart;
    return 0;
}




//Массивы одномерные

// Задание 1 В одномерном массиве, заполненном случайными числами, определить максимальный и минимальный элемент.

const int size = 10;// создание массива

int ar[size] ;
int max ; 
int min ; 

cout << "Введите значения массива \n";
for (int i = 0; i < size; i++)

    cin >> ar[i];

max = ar[0];// пусть 0 элемент максимальный
min = ar[0];// пусть 0 элемент минимальный

for (int i = 1; i < size; i++)
{

    // если текущий элемент меньше, чем минимум
    if (min > ar[i])
        // перезаписать значение минимума
        min = ar[i];

    // если текущий элемент больше, чем максимум

    if (max < ar[i])
        // перезаписать значение максимума
        max = ar[i];
}


 //вывод результата на экран
cout << "Max = " << max << "\n\n";
cout << "Min = " << min << "\n\n";
return 0;
}

Задание 2 пользователь вводит прибыль фирмы за год. Затем вводит диапазон
// необходимо определить месяц с максимальной прибылью и минимальной в этом диапазоне

// Создаем массив

restart:
const int size = 12;// создание массива

int ar[size] ;
int max ; 
int min ; 
int nach_dipazon, kon_dipazon;
int mesyc_1=0, mesyc_2=0;
cout << "Введите полученную прибыль за каждый месяц \n";
for (int i = 0; i < size; i++)
{
    cout << " За "<< i + 1 << " месяц равно  ";
    cin >> ar[i];
    cout << endl;
}
// введем начальный и минимальный месяц для задания диапазона

while ((mesyc_1== mesyc_2)|| (mesyc_1>12) || (mesyc_2 > 12) || (mesyc_1 <= 0) || (mesyc_2 <= 0))
{
    cout << "Введите месяц- начало диапазона (цифры от 1-12)";
cin >> mesyc_1;
cout << "Введите месяц- конец диапазона (цифры от 1-12)";
cin >> mesyc_2;
}

if (mesyc_1< mesyc_2)
{ 
    nach_dipazon = mesyc_1;
    kon_dipazon = mesyc_2;
}
else
{
    nach_dipazon = mesyc_2-1;
    kon_dipazon = mesyc_1-1;
}

max = ar[nach_dipazon]; 
min = ar[nach_dipazon];


for (int i = nach_dipazon; i < kon_dipazon; i++)
    {
    
      //  если текущий элемент меньше, чем минимум
        if (min > ar[i])
       //      перезаписать значение минимума
            min = ar[i];
    
     //    если текущий элемент больше, чем максимум
    
        if (max < ar[i])
      //       перезаписать значение максимума
            max = ar[i];
    }
    
    
    // вывод результата на экран
    cout << "Max прибыль = " << max << "\n\n";
    cout << "Min прибыль = " << min << "\n\n";

    goto restart;
return 0;
}

________________________________________________________________________________


// Задание 3 В одномерном массиве из size вещественных чисел вычислить:
// сумму отрицательных элементов
//Произведение элементов между максимальным и минимальным элементом
// Произведениеэлементов с четными номерами
// Сумму элементов между первым и последним отрицательным элементом

// Создаем массив

restart:
const int size = 6;

int ar[size] ;
int max ; 
int min ; 
int summ_otr_chisel;
int min_el=0, max_el=0;
int nach_dipazon, kon_dipazon;
int proizvedenie=1;
int proizvedenie_chetnoe = 1;
int nomer_otr_nach=0 , nomer_otr_kon=0;
int summ_otr_diap = 0;

cout << "Введите 6 значений массива \n";
cout << endl;
for (int i = 0; i < size; i++)
{
    cout << " Элемент "<< i << " равен  ";
    cin >> ar[i];
    cout << endl;
}
// Определим сумму отрицательных элементов if (ar[i] < 0)
// Определим максимальный и минимальный элемент

 max= ar[0];
 min = ar[0];
summ_otr_chisel = 0;

for (int i = 0; i < size; i++)
    {
    if (ar[i] < 0) summ_otr_chisel += ar[i];
    if (i%2 == 0)  proizvedenie_chetnoe *= ar[i];

      //  если текущий элемент меньше, чем минимум
        if (min > ar[i])
        { 
       //      перезаписать значение минимума
            min = ar[i]; 
            min_el = i;
        }
     //    если текущий элемент больше, чем максимум
    
        if (max < ar[i])
        { 
      //       перезаписать значение максимума
            max = ar[i]; 
            max_el = i;
        }
    }

//Произведение элементов между максимальным и минимальным значением 

// сначало определим начало и конец диапазона
if (min_el < max_el)
    { 
        nach_dipazon = min_el;
        kon_dipazon = max_el;
    }
else
{
    nach_dipazon = max_el;
    kon_dipazon = min_el;
}
        for (int i = nach_dipazon; i <= kon_dipazon; i++)
            proizvedenie *= ar[i];
    
        // Сумму элементов между первым и последним отрицательным элементом
        // определим первый отриц.элемент и последний отриц.элемент в списке
        for (int i = 0; i < size; i++)
        {
            if (ar[i] < 0)
            {
                nomer_otr_nach = i;
                break;
            }
        }
        // последний отриц.элемент в списке
        for (int i = 0; i < size; i++)
        {
            if (ar[i] < 0) nomer_otr_kon = i;
            
      
        }
        if ((nomer_otr_kon==nomer_otr_nach) && ar[nomer_otr_nach]<0)
            summ_otr_diap = ar[nomer_otr_nach];
        else
        for (int i = nomer_otr_nach+1; i < nomer_otr_kon; i++)
            summ_otr_diap += ar[i];


    // вывод результата на экран
    cout << "сумму отрицательных элементов = " << summ_otr_chisel << "\n\n";
    cout << endl;
    cout << "Произведение элементов между максимальным и минимальным значением элемента = " << proizvedenie << "\n\n";
    cout << endl;
    cout << "Произведение элементов с четными номерами = " << proizvedenie_chetnoe << "\n\n";
    cout << endl;
    cout << "Сумму элементов между первым и последним отрицательным элементом = " << summ_otr_diap << "\n\n";
    cout << endl;
    goto restart;
return 0;
}







// Задание 4 - Программа копирует последовательно элементы одного массива размером 10 элементов
// в 2 массива размером 5 элементов
#include <iostream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

restart:

        const int size_1 = 10; //размер массива №1
        const int size_2 = 5; //размер массива №2
        const int size_3 = 5; //размер массива №3
        int N1[size_1] ; // создание массива №1
        int N2[size_2]; // создание массива №2
        int N3[size_3]; // создание массива №3

 // ввод значений в массив №1

    cout << "Введите значения массива размером 10 элементов \n";

    for (int i = 0; i < size_1; i++)
    { 
    cin >> N1[i];
    }
        cout << endl;

// Запишем значения маасива 1 в значения массивов 2 и 3

    for (int i = 0; i < size_1; i++)
    { 
        if (i < 5) N2[i] = N1[i]; // при i=0,1,2,3,4 значения перенесем в массив 2
        if (i >= 5) N3[i- size_3] = N1[i];// при i=5,6,7,8,9 значения перенесем в массив 3
    }   

    

    // Вывод маасивов на экран
    cout << " Разделим Массив 1 на два массива 2 и 3  ";

    cout << endl;
    cout << endl;

    cout << " Массив 1 = ";

    for (int i = 0; i < size_1; i++)
    {
        cout << N1[i] << " | ";
    }
   
    cout << endl;
    cout << endl;

    cout << " Массив 2 = ";

    for (int i = 0; i < size_2; i++)
    {
        cout  << N2[i] << " | ";
    }
    cout << endl;
    cout << endl;

    cout << "Массив 3 =                      ";

    for (int i = 0; i < size_2; i++)
    {
        cout << N3[i] << " | ";
    }
    cout << endl;
    cout << endl;

    goto restart;
         return 0;
}



// Задание 5 - Программа выполняет поэлементную сумму двух массивов и результат заносит в третий

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");

restart:

    const int size_1 = 5; //размер массива №1
    const int size_2 = 5; //размер массива №2
    const int size_3 = 5; //размер массива №3
    int N1[size_1]; // создание массива №1
    int N2[size_2]; // создание массива №2
    int N3[size_3]; // создание массива №3

// ввод значений в массив №1

    cout << "Введите значения массива 1 размером 5 элементов \n";

    for (int i = 0; i < size_1; i++)
    {
        cin >> N1[i];
    }
    cout << endl;

    cout << "Введите значения массива 2 размером 5 элементов \n";

    for (int i = 0; i < size_2; i++)
    {
        cin >> N2[i];
    }
    cout << endl;

    // Суммируем элементы массива 1 и 2 и запишем в 3

    for (int i = 0; i < size_1; i++)
    {
        N3[i]= N1[i]+ N2[i];
    }
    cout << endl;

    cout << " Суммируем значения Массива 1 и Массива 2 в Массив  3  ";
    //
    //    cout << endl;
    //    cout << endl;


    // Выведем получившиеся массивы на экран


    cout << endl;
    cout << endl;

    cout << " Массив 1 = ";

    for (int i = 0; i < size_1; i++)
    {
        cout << N1[i] << " | ";
    }

    cout << endl;
    cout << endl;

    cout << " Массив 2 = ";

    for (int i = 0; i < size_2; i++)
    {
        cout << N2[i] << " | ";
    }
    cout << endl;
    cout << endl;

    cout << " Массив 3 = ";

    for (int i = 0; i < size_3; i++)
    {
        cout << N3[i] << " | ";
    }
    cout << endl;
    cout << endl;

    goto restart;
    return 0;
}