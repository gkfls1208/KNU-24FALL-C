#include <stdio.h>
#include <math.h>

//함수 정의
double f(double x) {
    return -log10(1 / x) + sin(x);
}

//구분구적법
double integrate(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n; // 구간 너비
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h; //시작점
        sum += func(x) * h;   //직사각형 넓이 합
    }
    return sum;
}

int main() {
    double a, b; //적분 구간
    int n, max_iter;

    printf("적분할 시작 값을 입력하세요 (a): ");
    scanf("%lf", &a);
    printf("적분할 끝 값을 입력하세요 (b): ");
    scanf("%lf", &b);
    printf("시행할 최대 구간 수 (2^n 형태로 입력): ");
    scanf("%d", &max_iter);

    printf("\n구간\t적분 결과\n");
    for (int i = 1; i <= pow(2,max_iter); i *= 2) {
        double result = integrate(f, a, b, i);
        printf("%d\t%.6f\n", i, result);
    }

    return 0;
}
