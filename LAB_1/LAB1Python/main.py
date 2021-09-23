import math
x1 = int(input("Enter x coordinate for point A: "))  # Введення координат користувачем
y1 = int(input("Enter y coordinate for point A: "))
x2 = int(input("Enter x coordinate for point B: "))
y2 = int(input("Enter y coordinate for point B: "))
x3 = int(input("Enter x coordinate for point C: "))
y3 = int(input("Enter y coordinate for point C: "))
ab = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)  # Обчичслення довжин сторін трикутника
bc = math.sqrt((x3 - x2) ** 2 + (y3 - y2) ** 2)
ac = math.sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2)
abc = math.acos((ab ** 2 + bc ** 2 - ac ** 2) / (2 * ab * bc))  # Обчислення кутів трикутника
acb = math.acos((ac ** 2 + bc ** 2 - ab ** 2) / (2 * ac * bc))
bac = math.acos((ab ** 2 + ac ** 2 - bc ** 2) / (2 * ab * ac))
abc = (180 * abc / math.pi)  # Переведення кутів з радіан у градуси
acb = (180 * acb / math.pi)
bac = (180 * bac / math.pi)
# Виведення отриманих сторін та кутів
print(f"AB = {ab}, BC = {bc}, AC = {ac}\n<ABC = {abc}, <ACB = {acb}, <BAC = {bac} ")
