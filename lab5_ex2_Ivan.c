#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
int main() {
    int choice;
    int n, i;

    // Ініціалізація генератора випадкових чисел
    srand(time(0));

    do {
        printf("\n========== МЕНЮ ОБРОБКИ МАСИВУ ==========\n");
        printf("1. Ввести масив вручну (Спосіб А)\n");
        printf("2. Згенерувати масив випадково (Спосіб Б)\n");
        printf("0. Вихід\n");
        printf("=========================================\n");
        printf("Ваш вибір: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            printf("Введіть розмір масиву n: ");
            scanf("%d", &n);
            
            // Створюємо масив динамічного розміру (VLA)
            int a[n];
            int sum_odd = 0;
            int first = -1, last = -1;
            long long product = 1;
            int found_between = 0;

            switch (choice) {
                case 1: {
                    // Заповнення вручну
                    for (i = 0; i < n; i++) {
                        printf("a[%d] = ", i);
                        scanf("%d", &a[i]);
                    }
                    break;
                }
                case 2: {
                    // Заповнення випадковими числами
                    printf("Згенерований масив:\n");
                    for (i = 0; i < n; i++) {
                        a[i] = rand() % 201 - 100; // Діапазон [-100; 100]
                        printf("%d\t", a[i]);
                    }
                    printf("\n");
                    break;
                }
            }

            // --- ЗАГАЛЬНА ЛОГІКА ОБЧИСЛЕНЬ ---

            // 1. Сума елементів з непарними номерами (1, 3, 5... тобто індекси 0, 2, 4...)
            for (i = 0; i < n; i += 2) {
                sum_odd += a[i];
            }

            // 2. Пошук індексів першого та останнього від'ємних елементів
            for (i = 0; i < n; i++) {
                if (a[i] < 0) {
                    if (first == -1) first = i;
                    last = i;
                }
            }

            // 3. Обчислення добутку між знайденими індексами
            if (first != -1 && last != -1 && last - first > 1) {
                for (i = first + 1; i < last; i++) {
                    product *= a[i];
                    found_between = 1;
                }
            }

            // Вивід результатів
            printf("\n--- Результати ---");
            printf("\nСума елементів з непарними номерами: %d", sum_odd);
            
            if (found_between) 
                printf("\nДобуток елементів між від'ємними: %lld\n", product);
            else 
                printf("\nМіж від'ємними елементами немає значень або від'ємних значень менше двох.\n");
        } 
        else if (choice != 0) {
            printf("Невірний вибір. Спробуйте ще раз.\n");
        }

    } while (choice != 0);

    printf("Програму завершено.\n");
    return 0;
}

