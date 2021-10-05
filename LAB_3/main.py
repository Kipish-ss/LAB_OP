a = float(input("Enter value for variable a: "))  # Введення змінної a
if a <= 1:  # Відповідно до значення a присвоїти відповідне значення нульовому члену послідовності
    x_current = min(2*a, 0.95)
elif 1 < a < 25:
    x_current = a / 5
else:
    x_current = a / 25
x_previous = 0  # Ініціалізація попереднього члена послідовності та присвоєння йому
# значення 0 для подальшого використання в циклі
x_next = (0.8 * x_current) + a / (5 * pow(x_current, 4))  # Ініціалізація з присвоєнням наступного члена послідовності
while (1.25 * a * abs(x_next + x_current)) >= pow(10, -6):  # Обчислення наступного члена послідовності
    x_previous = x_current  # та двох членів, мж якими він знаходиться, доки сума в умові виходу не буде меншою за 10^(-6)
    x_current = (0.8 * x_previous) + a / (5 * pow(x_previous, 4))
    x_next = (0.8 * x_current) + a / (5 * pow(x_current, 4))
difference = a - pow(x_current, 5)  # Обчислення різниці числа a та знайденного n-го члена в п'ятому степені
print(f"x_n = {x_current}\na-(x_n)^5 = {difference}")  # Виведення знайденного n-го члена та різиці
