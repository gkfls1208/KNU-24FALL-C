#include <stdio.h>

int main() {
    int func;
    double num1, num2, result;
    char op;

    printf("��Ģ���� ���α׷� \n\n");
    printf("���ϴ� ����� �Է��Ͻÿ�. \n");
    printf("1. ���ϱ�, 2. ����, 3. ���ϱ�, 4. ������ \n");

    printf("��� : ");
    scanf("%d", &func);

    printf("\n");
    printf("���� 1�� �Է��ϼ��� : ");
    scanf("%lf", &num1);

    printf("���� 2�� �Է��ϼ��� : ");
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
        printf("�߸��� ���Դϴ�. ���α׷��� �ٽ� �������ֽʽÿ�. \n");
        return 0;
    }

    printf("%lf %c %lf = %lf \n", num1, op, num2, result);
    return 0;

}