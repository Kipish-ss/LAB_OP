# Варіант 28
# Дано k натуральних n-значних чисел.Визначити серед них число, сума цифр якого є найбільшою.
import random


def sum_digits(num: int, count: int):  # Функція для обчислення суми цифр числа з заданою розрядністю
    sum_of_digits = 0
    temp_num = num
    for i in range(count, 0, -1):
        digit = temp_num // (10 ** (i-1))
        sum_of_digits += digit
        temp_num = temp_num % (10 ** (i-1))
    return sum_of_digits


def find_largest_sum(num_range: int, capacity: int):  # Функція для знаходження числа з найбільшою сумою цифр серед
    # заданої кількості чисел цієї ж розрядності
    temp_sum = 0
    temp_num = 0
    for i in range(num_range):
        num = random.randrange(10 ** (n-1), 10 ** n)  # Ініціалізація випадкового цілого числа з заданого проміжка
        print(num)
        sum = sum_digits(num, capacity)
        if temp_sum < sum:
            temp_num = num
            temp_sum = sum
    return temp_num


n = int(input("Enter the digit capacity of numbers: "))  # Введення розрядності числа
k = int(input("Enter the number of numbers of given digit capacity: "))  # Введення кількості чисел цієї розрядності
num = find_largest_sum(k, n)
print(f'Number with the largest sum of digits is {num}')  # Виведення числа з найбільшою сумлю цифр

