# Варіант 28
# Дослідити область визначення і обчислити значення функції
import math
a = float(input("Enter number a: "))  # Введення значень змінних a та b
b = float(input("Enter number b: "))
if a ** 2 == b ** 2:  # Перевірка чи належать введені значення області визначення функції
    print("|b^2-a^2| cannot be equal to 0 since it is impossible to divide bu zero.")
else:
    c = float(input("Enter number c: "))  # Введення значення змінної c
    if math.sin(c) == 0:  # Перевірка чи належить введене значення області визначення функції
        print("sin(c) cannot be equal to zero since it is impossible to divide by zero.")
    else:
        d = float(input("Enter number d: "))  # Введення значення змінної c
        if d <= 0:  # Перевірка чи належить введене значення області визначення функції
            print("Logarithm of non-positive number does not exist.")
        else:
            y = math.log(d, math.e) / (abs(b ** 2 - a ** 2) * math.sin(c))  # Якщо усі введені значення належать
            # області визначення, то обчислюємо значення функції
            print(f"Function y(x) = {y}")  # Виведення значення функції
