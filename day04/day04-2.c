#include <stdio.h>

void Swap(int* swap_num, int* swap_num2);

int main() {
    int a = 10, b = 20;
    printf("���� �� a = %d, b = %d \n", a, b);

    Swap(&a, &b);

    printf("���� �� a = %d, b = %d \n", a, b);

    return 0;

}

void Swap(int* swap_num, int* swap_num2) {
    int a;

    a = *(swap_num2);
    *(swap_num2) = *(swap_num);
    *(swap_num) = a;

}