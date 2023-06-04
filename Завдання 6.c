#include <stdio.h>
#include <math.h>

// Функція для обчислення довжини відрізка за координатами його кінців
double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Функція для обчислення площі трикутника за відомими розмірами сторін
double calculateTriangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2;  // Півпериметр трикутника
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Функція для перевірки на існування трикутника за допомогою умови тріїнкової нерівності
int isTriangleValid(double a, double b, double c) {
    return (a + b > c) && (b + c > a) && (c + a > b);
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

// Функція для виведення координат вершин трикутника
void printTriangleCoordinates(double x1, double y1, double x2, double y2, double x3, double y3) {
    printf("Координати вершин трикутника:\n");
    printf("A(%.2lf, %.2lf);\n", x1, y1);
    printf("B(%.2lf, %.2lf);\n", x2, y2);
    printf("C(%.2lf, %.2lf);\n", x3, y3);
}

int main() {
    double x1, y1, x2, y2, x3, y3;

    inputTriangleCoordinates(&x1, &y1, &x2, &y2, &x3, &y3);
    printTriangleCoordinates(x1, y1, x2, y2, x3, y3);

    // Обчислення довжин відрізків AB, BC, CA
    double AB = calculateDistance(x1, y1, x2, y2);
    double BC = calculateDistance(x2, y2, x3, y3);
    double CA = calculateDistance(x3, y3, x1, y1);

    // Перевірка на існування трикутника
    if (!isTriangleValid(AB, BC, CA)) {
        printf("Трикутник не існує.\n");
        return 0;
    }

    // Обчислення площі трикутника ABC
    double areaABC = calculateTriangleArea(AB, BC, CA);

    printf("Площа трикутника ABC: %.2lf\n", areaABC);

    return 0;
}
