#include <stdio.h>
#include <math.h>
/* Варіант 28
Дослідити область визначення і знайти значення функції.
*/
int main() {
	float a, b, c, d, y;
	printf("Enter value for a: ");// Введення значень змінних a та b
	scanf_s("%f", &a);
	printf("Enter value for b: ");
	scanf_s("%f", &b);
	if (pow(a, 2) == pow(b, 2)) {  // Перевірка чи належать введені значення області визначення функції
		printf("|b^2-a^2| cannot be equal to 0 since it is impossible to divide by zero.");
	}
	else {
		printf("Enter value for c: ");  // Введення значення змінної c
		scanf_s("%f", &c);
		if (sin(c) == 0) { // Перевірка чи належить введене значення області визначення функції
			printf("sin(c) cannot be equal to 0 since it is impossible to divide by zero.");
		}
		else {
			printf("Enter value for d: "); // Введення значення змінної d
			scanf_s("%f", &d);
			if (d <= 0) { // Перевірка чи належить введене значення області визначення функції
				printf("Logarithm of non-positive number does not exist.");
			}
			else {
				y = log(d) / (abs(pow(b, 2) - pow(a, 2)) * sin(c)); /* Якщо усі введені значення належать
																	області визначення, то обчислюємо значення функції */
				printf("Function y(x) = %f", y); // Виведення значення функції
			}
		}
	}
	return 0;

}