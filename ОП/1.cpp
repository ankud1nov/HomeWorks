Задание 1: 
Вывести на экран один куплет любимого стихотворения или песни, с указанием автора или исполнителя. Используйте escape-последовательности для форматирования.
Решение:
#include <iostream>
using namespace std;
int main()
{
  cout << "\"Я помню чудное мгновенье:\n"
"Передо мной явилась ты,\n"
"Как мимолетное виденье,\n"
"Как гений чистой красоты.\"\n"
"\tА. С. Пушкин";
}

Задание 2:
Вывести на экран стих «Every hunter wants...» таким образом, чтобы каждый «цвет» начинался с новой строки и соответствующим количеством табуляций.
Решение:
#include <iostream>
 
using namespace std;
 
int main()
{
  cout << "Every\n"
 "\tHunter\n"
"\t\tWants\n"
"\t\t\tTo know\n"
"\t\t\t\t Where\n"
"\t\t\t\t\tDoes Pheasant\n"
"\t\t\t\t\t\t\tSit\n\n";
}

Задание 3:
Напишите объявление о продаже чего-нибудь и выведите его на экран, в том виде как оно должно было бы быть напечатано. 			
Например: 
Продам щенков. 			
Порода: ротвейлер. 			
...... 		
Тел.: 222-22-22 				
222 | 222 | 			
22 |22| 			
22 |22| 				
и т.д.
Решение:
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
cout << "\t\t\tО Б Ъ Я В Л Е Н И Е\n"
"\t\t\tПродам щенков.\n"
"\n"
"\t\t\tПорода: ротвейлер.\n"
"\n"
"\t\t\tТел.: 222-22-22\n"
".................................................................\n"
"|\t\t|\t\t|\t\t|\t\t|\n"
"|\t\bщенки\t|\t\bщенки\t|\t\bщенки\t|\t\bщенки\t|\n"
"|\t\t|\t\t|\t\t|\t\t|\n"
"|\t222\t|\t222\t|\t222\t|\t222\t|\n"
"|\t\t|\t\t|\t\t|\t\t|\n"
"|\t22\t|\t22\t|\t22\t|\t22\t|\n"
"|\t22\t|\t22\t|\t22\t|\t22\t|\n"
"|\t\t|\t\t|\t\t|\t\t|\n";
}

Задание 4:
Заданы три сопротивлении R1, R2, R3 . Вычислить значение сопротивления R0 по формуле: 1/R0 = 1/R1+1/R2+1/R3. 		
Контрольный пример: R1=2, R2=4, R3=8 R0 = 1.142857
Решение:
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
float r0, r1, r2, r3;
cout << "Введите сопротивление R1, R2, R3:\n";
cin >> r1 >> r2 >> r3;
r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);
cout.precision(7);
cout << "R0 = " << r0 << "\n";
}

Задание 5:
По заданной длине окружности найти площадь круга по формуле S = pi*R2, радиус вычислить из формулы длины окружности: L=2*pi *R 		
Примечание pi = 3.14
Решение:
#include <iostream>
using namespace std;
int main()
{
const float pi = 3.14;
float l, r, s;
cout << "Input L\n";
cin >> l;
r = l / 2 * pi;
s = pi * r * r;
cout << "S = " << s;
}

Задание 6:
Вычислить пройденное расстояние при прямолинейном равноускоренном движении по формуле S = v*t + (a*t2) / 2, где v – скорость, t – время, а – ускорение.
Решение:
#include <iostream>
using namespace std;
int main()
{
double v, t, a, s;
cout << "Input v, t, a: ";
cin >> v >> t >> a;
s = v * t + (a * t * t) / 2;
cout << "S = " << s;
}

Задание 7: 					
Пользователь вводит с клавиатуры расстояние до аэропорта и время, за которое нужно доехать. Вычислить скорость, с которой ему нужно ехать. 
Решение:
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int distance, time;
cout << "Введите расстояние до аэропорта в метрах: ";
cin >> distance;
cout << "Введите время, за которое необходимо добраться в минутах: ";
cin >> time;
float speed = (float)distance / (float)time / 1000 * 60;
cout << "Чтобы прибыть вовремя, необходимо ехать со скоростью: " << speed << " км/ч\n";
}

Задание 8: 			
Пользователь вводит с клавиатуры время начала и время завершения телефонного разговора (часы, минуты и секунды). Посчитать стоимость разговора, если стоимость минуты – 30 копеек.
Решение:
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int startHour, startMin, startSec, endHour, endMin, endSec;
cout << "Введите время начала разговора (час, мин, сек):\n";
cin >> startHour >> startMin >> startSec;
cout << "\nВведите время конца разговора (час, мин, сек):\n";
cin >> endHour >> endMin >> endSec;
if (endHour < startHour) {
endHour += 24;
}
int totalStartMinutes = startHour * 3600 + startMin * 60 + startSec;
int totalEndMinutes = endHour * 3600 + endMin * 60 + endSec;
int diffTime = totalEndMinutes - totalStartMinutes;
int callCost = diffTime * 100 / 2 / 100 ;
int callCostRub = callCost / 100;
int callCostKop = callCost % 100;
cout << "Стоимость звонка: " << callCostRub << " руб. " << callCostKop << " коп.";
}

Задание 9: 
Пользователь вводит с клавиатуры расстояние, расход бензина на 100 км и стоимость трех видов бензина. Вывести на экран сравнительную таблицу со стоимостью поездки на разных видах бензина.
Решение:
#include <iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "Russian");
int distance, consumption, cost1, cost2, cost3;
cout << "Введите расстояние (в км): ";
cin >> distance;
cout << "\nВведите расход бензина на 100 км: ";
cin >> consumption;
cout << "\nВведите стоимость первого вида бензина: ";
cin >> cost1;
cout << "\nВведите стоимость второго вида бензина: ";
cin >> cost2;
cout << "\nВведите стоимость третьего вида бензина: ";
cin >> cost3;
const float realConsumption = distance * consumption / 100;
float travelCost1 = realConsumption * cost1;
float travelCost2 = realConsumption * cost2;
float travelCost3 = realConsumption * cost3;
cout << "\n\tСтоимость поездки по видам бензина\n"
"\tпервый\t\tвторой\t\tтретий\n";
cout << "\t" << travelCost1 << "\t\t" << travelCost2 << "\t\t" << travelCost3 << endl;
}