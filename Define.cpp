//С помощью директивы #define написать следующие макросы: 
//■ Нахождение меньшего из двух чисел;
//■ Нахождение большего из двух чисел; 
//■ Возведение числа в квадрат;
//■ Возведение числа в степень; 
//■ Проверка числа на четность; 
//■ Проверка числа на нечетность.

#include <iostream>
#include <cmath>
using namespace std;
#define min(a, b) (a < b ? cout << a << endl : cout << b << endl);
#define max(a, b) (a > b ? cout << a << endl : cout << b << endl);
#define sqr(a) (cout << a * a << endl);
#define exp(a, b) (cout << pow(a, b) << endl);
#define even(a) (a % 2 == 0 ? cout << a << " is even " << endl : cout << a << " is not even " << endl);
#define odd(a) (a % 2 == 1 ? cout << a << " is odd " << endl : cout << a << " is not odd " << endl);


int main() {
    int a = 4, b = 5, n = 2;
    min(a, b);
    max(a, b);
    sqr(a);
    exp(a, n);
    even(a);
    odd(b);
    return 0;
}