/* Варіант 28
Дано k натуральних n-значних чисел.Визначити серед них число, сума цифр якого є найбільшою. */
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int sum_digits(int num, int count) // Функція для обчислення суми цифр числа з заданою розрядністю
{
    int sum_of_digits = 0, temp_num = num, digit;
    for (int i = count - 1; i >= 0; i--)
    {
        digit = temp_num / pow(10, i);
        sum_of_digits += digit;
        temp_num = temp_num % (int)(pow(10, i));
    }
    return sum_of_digits;
}
int find_largest_sum(int range, int capacity) /* Функція для знаходження числа з найбільшою сумою цифр
серед заданої кількості чисел цієї ж розрядності */
{
    int temp_sum = 0, temp_num = 0, num, sum;
    srand (time(NULL));
    for (int i = 0; i < range; i++)
    {
        // Ініціалізація випадкового цілого числа з заданого проміжка
        num = rand() % (9 * (int)(pow(10, capacity - 1))) + int(pow(10, capacity-1));
        cout << num << "\n";
        sum = sum_digits(num, capacity);
        if (temp_sum < sum)
        {
            temp_num = num;
            temp_sum = sum;
        }
    }
    return temp_num;
}
int main() {
    int k, n, num;
    cout << "Enter the digit capacity of numbers: "; // Введення кількості чисел цієї розрядності
    cin >> n;
    cout << "Enter the number of numbers of given digit capacity: "; // Введення розрядності числа
    cin >> k;
    num = find_largest_sum(k, n);
    cout << "Num with the largest sum of digits is " << num <<"."; // Виведення числа з найбільшою сумлю цифр
    return 0;
}
