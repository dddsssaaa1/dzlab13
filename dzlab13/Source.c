#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define MAX_SIZE 100

int sum_without_min_max(const int a[], int n) {
    int idx_min = 0;
    int idx_max = -1;
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < a[idx_min]) {
            idx_min = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != idx_min && (idx_max == -1 || a[i] > a[idx_max])) {
            idx_max = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != idx_min && i != idx_max) {
            sum += a[i];
        }
    }

    return sum;
}

int main(void) {
    setlocale(LC_ALL, ".UTF8");

    int a[MAX_SIZE];
    int n;

    printf("Введите количество элементов массива (от 1 до %d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Ошибка: некорректный размер массива.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        if (scanf("%d", &a[i]) != 1) {
            printf("Ошибка ввода элемента массива.\n");
            return 1;
        }
    }

    printf("\nВведенный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n\n");

    printf("Сумма элементов массива за исключением минимального и максимального: %d\n",
        sum_without_min_max(a, n));

    return 0;
}