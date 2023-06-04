#include <stdio.h>
#include <math.h>

// Функція для обчислення показника d
double calculateSum(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i]);
    }
    return sum;
}

// Функція для введення елементів масиву
void inputArray(double arr[], int n) {
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &arr[i]);
    }
}

// Функція для виведення елементів масиву
void printArray(double arr[], int n) {
    printf("Елементи масиву:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %.2lf; ", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);

    double arr[n];
    inputArray(arr, n);
    printArray(arr, n);

    double d = calculateSum(arr, n);
    printf("Результат: d = %.2lf\n", d);

    return 0;
}
