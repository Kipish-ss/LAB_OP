/* Варіант 28
В масиві цілих чисел B(n) знайти число, яке зустрічається найбільш часто. Якщо таких чисел декілька,
то визначити найменше із них. */
#include <iostream>
#include <ctime>
using namespace std;
int* generate_array(int);  // функція для генерації масиву заданої довжини
void display_array(int*, int);  // функція для відображення масиву заданої довжини
int most_frequent_num(int*, int);  /* функція для знаходження числа, яке зустрічається
набільш часто в масиві, або найменшного з них, якщо їх декілька */
int main()
{
    int* array;
    int n, result;
    cout << "Enter the length of the array: ";
    cin >> n;
    array = generate_array(n);
    display_array(array, n);
    result = most_frequent_num(array, n);
    cout << "The most frequent number(the least one among the most frequent ones) is " << result << ".";
    delete []array;
    return 0;
}
int* generate_array(int n)
{
    int num;
    int* array = new int[n];
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        num = rand()% 10;
        array[i] = num;
    }
    return array;
}
void display_array(int *arr, int n) {
    if (n == 1) {
        cout << "[" << arr[n-1] << "]\n";
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (i == 0)
            {
                cout << "[" << arr[i] << ", ";
            } else if (i == n - 1) {
                cout << arr[i] << "]\n";
            } else {
                cout << arr[i] << ", ";
            }
        }
    }
}
int most_frequent_num(int* arr, int n)
{
    int temp_num, temp_count, count;
    temp_num = arr[0];
    temp_count = 1;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (i != j) {
                if (arr[i] == arr[j])
                {
                    count += 1;
                }
            }
        }
        if ((temp_count == count && arr[i] < temp_num) || (temp_count < count))
        {
            temp_num = arr[i];
            temp_count = count;
        }
    }
    return temp_num;
}