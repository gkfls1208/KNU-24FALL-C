#include <stdio.h>

int sosu(int receive);

int main() {
    int transmit, result;

    printf("�Ҽ����� �ƴ��� Ȯ�� �� ���� �Է��ϼ��� : ");
    scanf("%d", &transmit);
    result = sosu(transmit);

    if (result == 1) {
        printf("�ش� ���� �Ҽ��Դϴ�. \n");
    }
    else if (result == 0) {
        printf("�ش� ���� �Ҽ��� �ƴմϴ�. \n");
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