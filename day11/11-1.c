#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c; //이차방정식의 계수
    double discriminant, root1, root2;

    printf("이차방정식의 계수 a, b, c를 입력하세요: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a == 0) {//a가 0인 경우: 일차방정식 bx + c = 0
        if (b != 0) {
            root1 = -c / b;
            printf("일차방정식의 해: %.2f\n", root1);
        } else {
            // a = 0이고 b = 0인 경우
            if (c == 0) {
                printf("모든 실수 x가 해입니다.\n");
            } else {
                printf("해가 존재하지 않습니다.\n");
            }
        }
        return 0;
    }

    //이차방정식의 판별식 계산
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        //두 개의 실근 계산
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("두 실근: %.2f, %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        //중근 계산
        root1 = -b / (2 * a);
        printf("중근: %.2f\n", root1);
    } else {
        //허근인 경우
        printf("허근을 가집니다. 값을 출력하지 않습니다.\n");
    }

    return 0;
}