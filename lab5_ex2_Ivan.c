#include <stdio.h>

int main() {
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // 1. Сума елементів з непарними номерами (1-й, 3-й... тобто індекси 0, 2, 4)
    int sum_odd = 0;
    for (int i = 0; i < n; i += 2) {
        sum_odd += a[i];
    }

    // 2. Добуток між першим і останнім від'ємними
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            if (first == -1) first = i;
            last = i;
        }
    }

    long long product = 1;
    int found_between = 0;
    if (first != -1 && last != -1 && first != last) {
        for (int i = first + 1; i < last; i++) {
            product *= a[i];
            found_between = 1;
        }
    }

    printf("\nСума елементів з непарними номерами: %d", sum_odd);
    if (found_between) 
        printf("\nДобуток між від'ємними: %lld\n", product);
    else 
        printf("\nМіж від'ємними елементами немає значень.\n");

    return 0;
}
