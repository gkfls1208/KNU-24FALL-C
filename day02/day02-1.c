#include <stdio.h>

int main() {
    int func;
    double num1, num2, result;
    char op;

    printf("사칙연산 프로그램 \n\n");
    printf("원하는 기능을 입력하시오. \n");
    printf("1. 더하기, 2. 뺴기, 3. 곱하기, 4. 나누기 \n");

    printf("기능 : ");
    scanf("%d", &func);

    printf("\n");
    printf("숫자 1을 입력하세요 : ");
    scanf("%lf", &num1);

    printf("숫자 2룰 입력하세요 : ");
    scanf("%lf", &num2);
    printf("\n");

    if (func == 1) {
        result = num1 + num2;
        //printf("%lf + %lf = %lf \n", num1, num2, result);
        op = '+';
    }
    else if (func == 2) {
        result = num1 - num2;
        //printf("%lf - %lf = %lf \n", num1, num2, result);
        op = '-';
    }
    else if (func == 3) {
        result = num1 * num2;
        //printf("%lf * %lf = %lf \n", num1, num2, result);
        op = '*';
    }
    else if (func == 4) {
        result = num1 / num2;
        //printf("%lf / %lf = %lf \n", num1, num2, result);
        op = '/';
    }
    else {
        printf("잘못된 값입니다. 프로그램을 다시 실행해주십시오. \n");
        return 0;
    }

    printf("%lf %c %lf = %lf \n", num1, op, num2, result);
    return 0;

}