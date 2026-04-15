#include <stdio.h>

int main() {
    int n, count = 0;
    printf("Введіть кількість елементів: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // Перевірка сусідніх елементів на різні знаки
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] > 0 && a[i+1] < 0) || (a[i] < 0 && a[i+1] > 0)) {
            count++;
        }
    }

    printf("Кількість сусідств з різними знаками: %d\n", count);
    return 0;
}
