#include <stdio.h>

int main() {
    int choice;
    int n, i, count;

    do {
        // Вивід меню
        printf("\n========== МЕНЮ ==========\n");
        printf("1. Ввести масив\n");
        printf("0. Вихід\n");
        printf("==========================\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Основна логіка вашого коду
                printf("Введіть кількість елементів: ");
                scanf("%d", &n);

                int a[n];
                count = 0;

                // Введення елементів
                for (i = 0; i < n; i++) {
                    printf("a[%d] = ", i);
                    scanf("%d", &a[i]);
                }

                // Перевірка сусідніх елементів на різні знаки
                for (i = 0; i < n - 1; i++) {
                    if ((a[i] > 0 && a[i+1] < 0) || (a[i] < 0 && a[i+1] > 0)) {
                        count++;
                    }
                }

                printf("\nРезультат: Кількість сусідств з різними знаками: %d\n", count);
                break;
            }

            case 0:
                printf("Завершення роботи...\n");
                break;

            default:
                printf("Помилка: такого пункту не існує. Спробуйте ще раз.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}

