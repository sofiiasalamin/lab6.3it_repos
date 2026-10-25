#include <iostream>   
#include <string>     
using namespace std;

// Прототип звичайної функції для масиву int
void Print(int* a, const int size);

// Прототип шаблону функції для масиву будь-якого типу T
template <typename T>
void Print(T* a, const int size);

int main()
{
    const int n = 10;   // кількість елементів у масивах

    // Масив цілих чисел
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "Print(a, n) = ";
    Print(a, n);            // виклик звичайної функції

    cout << "Print<int>(a, n) = ";
    Print<int>(a, n);       // виклик шаблону з явним типом int

    // Масив дійсних чисел
    double b[n] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.0 };
    cout << "Print<double>(b, n) = ";
    Print<double>(b, n);    // виклик шаблону з типом double

    // Масив рядків
    string c[n] = { "1 ", "2 ", "3 ", "4 ", "5 ", "6 ", "7 ", "8 ", "9 ", "10 " };
    cout << "Print<string>(c, n) = ";
    Print<string>(c, n);    // виклик шаблону з типом string

    return 0;   // успішне завершення програми
}

// Реалізація звичайної функції (тільки для int)
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)   // прохід по всіх елементах масиву
        cout << a[i] << " ";         // вивід елемента через пропуск
    cout << endl;                    // перехід на новий рядок після виводу
}

// Реалізація шаблону функції (для будь-якого типу T)
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)   // прохід по всіх елементах масиву
        cout << a[i] << " ";         // вивід елемента через пропуск
    cout << endl;                    // перехід на новий рядок після виводу
}
