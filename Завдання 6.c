#include <stdio.h>
#include <math.h>

// Функція для обчислення довжини відрізка за координатами його кінців
double calculateDistance(double x1, double y1, double x2, double y2) {
    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

// Функція для обчислення площі трикутника за заданими розмірами сторін
double calculateTriangleArea(double side1, double side2, double side3) {
    double s = (side1 + side2 + side3) / 2; // Півпериметр
    double area = sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Формула Герона
    return area;
}

// Функція для введення координат вершин трикутника
void inputTriangleCoordinates(double* x1, double* y1, double* x2, double* y2, double* x3, double* y3) {
    printf("Введіть координати вершин трикутника:\n");
    printf("Вершина A (x1, y1): ");
    scanf("%lf %lf", x1, y1);
    printf("Вершина B (x2, y2): ");
    scanf("%lf %lf", x2, y2);
    printf("Вершина C (x3, y3): ");
    scanf("%lf %lf", x3, y3);
}

// Функція для обчислення площі та порівняння площ двох трикутників
void compareTriangleAreas() {
    double x1, y1, x2, y2, x3, y3;
    double area1, area2;

    printf("Введіть координати вершин першого трикутника:\n");
    inputTriangleCoordinates(&x1, &y1, &x2, &y2, &x3, &y3);
    double side1 = calculateDistance(x1, y1, x2, y2);
    double side2 = calculateDistance(x2, y2, x3, y3);
    double side3 = calculateDistance(x3, y3, x1, y1);
    area1 = calculateTriangleArea(side1, side2, side3);

    printf("Введіть координати вершин другого трикутника:\n");
    inputTriangleCoordinates(&x1, &y1, &x2, &y2, &x3, &y3);
    side1 = calculateDistance(x1, y1, x2, y2);
    side2 = calculateDistance(x2, y2, x3, y3);
    side3 = calculateDistance(x3, y3, x1, y1);
    area2 = calculateTriangleArea(side1, side2, side3);

    if (area1 > area2) {
        printf("Перший трикутник має більшу площу.\n");
    } else if (area2 > area1) {
        printf("Другий трикутник має більшу площу.\n");
    } else {
        printf("Обидва трикутники мають однакову площу.\n");
    }
}

int main() {
    compareTriangleAreas();

    return 0;
}
