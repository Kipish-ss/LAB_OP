/* Варіант 28
В масиві цілих чисел B(n) знайти число, яке зустрічається найбільш часто. Якщо таких чисел декілька,
то визначити найменше із них. */
#include <iostream>
using namespace std;
#include <time.h>
void fill_array(int* arr, int n)  // функція для заповнення масиву заданої розрядності
{
    int num;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        num = rand()% 10;  // Генерація випадкового числа з проміжку від 0 до 10 невключно
        arr[i] = num;  // Присвоєння i-му елементу масиву значення цього випадкового числа
        if (i == 0)  // Виведення елементів масиву
        {
            cout << "[" << arr[i] << ", ";
        }
        else if (i == n - 1)
        {
            cout << arr[i] << "]\n";
        }
        else
        {
            cout << arr[i] << ", ";
        }
    }
}
int most_frequent_num(int* arr, int n) /* Функція для знаходження числа у заданому масиві, яке зустрічається
набільш часто. Якщо таких чисел декілька, то функція повертає найменше з них. */
{
    int temp_num, temp_count, count;
    temp_num = arr[0];
    temp_count = 1;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; j++) {
            if (i != j) {
                if (arr[i] == arr[j])
                {
                    count += 1;
                }
            }
        }
        if ((temp_count == count && temp_num > arr[i]) || (temp_count < count))
        {
            temp_num = arr[i];
            temp_count = count;
        }
    }
    return temp_num;
}
int main()
{
    int n, num;
    cout << "Enter the length of the array: ";
    cin >> n; // Введення довжини масиву
    int arr[n];
    fill_array(arr, n); // Заповнення даного масиву
    num = most_frequent_num(arr, n);  // Знаходження шуканого числа
    cout << "The most frequent number(the least one among the most frequent ones) is " << num << "."; /* Виведення
    шуканого числа */
    return 0;
}
