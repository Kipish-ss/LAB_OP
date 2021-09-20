#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
/* Варіант 28
* По заданим координатам трикутника на площі визначити довжини його сторін і величини кутів. 
*/
int main()
{
    int x1, y1, x2, y2, x3, y3; 
    float ab, bc, ac, abc, bac, acb;
    printf("Enter x coordinate for point A: "); //Введення координат вершин трикутника
    scanf_s("%d", &x1);
    printf("Enter y coordinate for point A: ");
    scanf_s("%d", &y1);
    printf("Enter x coordinate for point B: ");
    scanf_s("%d", &x2);
    printf("Enter x coordinate for point B: ");
    scanf_s("%d", &y2);
    printf("Enter x coordinate for point C: ");
    scanf_s("%d", &x3);
    printf("Enter x coordinate for point C: ");
    scanf_s("%d", &y3);
    ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); //Знаходження довжин сторін
    bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    abc = acos((pow(ab, 2) + pow(bc, 2) - pow(ac, 2)) / (ab * bc * 2)); //Знаходження величин кутів
    bac = acos((pow(ab, 2) + pow(ac, 2) - pow(bc, 2)) / (ab * ac * 2));
    acb = acos((pow(ac, 2) + pow(bc, 2) - pow(ab, 2)) / (ac * bc * 2));
    abc = abc * (180.0 / M_PI); // Переведення кутів з радіан у градуси
    bac = bac * (180.0 / M_PI);
    acb = acb * (180.0 / M_PI);
    printf("AB = %f, BC = %f, AC = %f\n<ABC = %f, <BAC = %f, <ACB = %f", ab, bc, ac, abc, bac, acb); //Виведення отриманих довжин сторін та величин кутів 
    return 0;
}



