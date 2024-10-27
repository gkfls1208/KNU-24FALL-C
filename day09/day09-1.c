#include <stdio.h>

// 3차원 벡터를 정의하는 구조체
typedef struct {
    int x;
    int y;
    int z;
} Vector;

// 벡터의 합을 계산하는 함수
Vector addVectors(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

// 벡터의 차를 계산하는 함수
Vector subtractVectors(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

// 벡터의 내적을 계산하는 함수
int dotProduct(Vector v1, Vector v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// 벡터의 외적을 계산하는 함수
Vector crossProduct(Vector v1, Vector v2) {
    Vector result;
    result.x = v1.y * v2.z - v1.z * v2.y;
    result.y = v1.z * v2.x - v1.x * v2.z;
    result.z = v1.x * v2.y - v1.y * v2.x;
    return result;
}








int main() {
    Vector v1, v2;
    int command;

    // 첫 번째 벡터 입력
    printf("첫 번째 벡터 (x,y,z) : ");
    scanf("%d,%d,%d", &v1.x, &v1.y, &v1.z);

    // 두 번째 벡터 입력
    printf("두 번째 벡터 (x,y,z) : ");
    scanf("%d,%d,%d", &v2.x, &v2.y, &v2.z);

    // 입력된 벡터 확인 출력
    printf("\n입력된 첫 번째 벡터: %d, %d, %d\n", v1.x, v1.y, v1.z);
    printf("입력된 두 번째 벡터: %d, %d, %d\n", v2.x, v2.y, v2.z);

    // 메뉴 출력 및 명령 선택
    do {
        printf("\n————————————\n");
        printf("1. 벡터의 합\n");
        printf("2. 벡터의 차\n");
        printf("3. 벡터의 외적\n");
        printf("4. 벡터의 내적\n");
        printf("5. 종료\n");
        printf("————————————\n");
        printf("명령 입력 : ");
        scanf("%d", &command);

        switch (command) {
            case 1: {
                Vector sum = addVectors(v1, v2);
                printf("벡터의 합은 x:%d y:%d z:%d\n", sum.x, sum.y, sum.z);
                break;
            }
            case 2: {
                Vector diff = subtractVectors(v1, v2);
                printf("벡터의 차는 x:%d y:%d z:%d\n", diff.x, diff.y, diff.z);
                break;
            }
            case 3: {
                Vector cross = crossProduct(v1, v2);
                printf("벡터의 외적은 x:%d y:%d z:%d\n", cross.x, cross.y, cross.z);
                break;
            }
            case 4: {
                int dot = dotProduct(v1, v2);
                printf("벡터의 내적은 vec1*vec2=%d\n", dot);
                break;
            }
            case 5:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 명령입니다. 다시 입력해주세요.\n");
        }
    } while (command != 5);

    return 0;
}
