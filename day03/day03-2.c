#include <stdio.h>

int Fac(int num_r);

int main() {
    int num_t, result;

    printf("����� ���丮�� �� �Է� : ");
    scanf("%d", &num_t);
    result = Fac(num_t);
    printf("%d! = %d \n", num_t, result);

    return 0;
}

int Fac(int num_r) {
    int fac_num;

    if (num_r == 1 || num_r == 0) {
        return 1;
    }
    else {
        fac_num = num_r * Fac(num_r - 1);
    }

    return fac_num;
}