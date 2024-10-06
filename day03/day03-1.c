#include <stdio.h>

int sosu(int receive);

int main() {
    int transmit, result;

    printf("소수인지 아닌지 확인 할 수를 입력하세요 : ");
    scanf("%d", &transmit);
    result = sosu(transmit);

    if (result == 1) {
        printf("해당 수는 소수입니다. \n");
    }
    else if (result == 0) {
        printf("해당 수는 소수가 아닙니다. \n");
    }

    return 0;
}

int sosu(int receive) {
    int cnt;

    for (cnt = 2; cnt < receive; cnt++) {
        if (receive % cnt == 0) {
            return 0;
        }
    }

    return 1;
}