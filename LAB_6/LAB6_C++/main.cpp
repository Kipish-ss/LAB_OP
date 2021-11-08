/* Варіант 28
Дано k натуральних n-значних чисел.Визначити серед них число, сума цифр якого є найбільшою. */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int k, n, result;
void init(); // Функція для введення розрядності чисел та їх кількості
int sum_digits(int, int); // Функція для обчислення суми цифр числа з заданою розрядністю
int find_largest_sum(int, int); /* Функція для знаходження числа з найбільшою сумою цифр
серед заданої кількості чисел цієї ж розрядності */
int main() {
    init();
    result = find_largest_sum(k, n);
    cout << "Num with the largest sum of digits is " << result <<"."; // Виведення числа з найбільшою сумою цифр
    return 0;
}
void init() {
    cout << "Enter the digit capacity of numbers: ";
    cin >> n;
    cout << "Enter the number of numbers of given digit capacity: ";
    cin >> k;
}
int sum_digits(int num, int count)
{
    int sum_of_digits = 0, digit;
    for (int i = count - 1; i >= 0; i--)
    {
        digit = num/ pow(10, i);
        sum_of_digits += digit;
        num = num % (int)(pow(10, i));
    }
    return sum_of_digits;
}
int find_largest_sum(int range, int capacity)
{
    int temp_sum = 0, temp_num = 0, sum, num;
    srand(time(NULL));
    for (int i = 0; i < range; i++)
    {
        // Генерація випадкового цілого числа з заданого проміжка
        num = rand() % (9 * int(pow(10, capacity - 1))) + int(pow(10, capacity-1));
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
