#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main() {
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array);
    movePointer(array);

    return 0;
}

void fillRandom(int array[SIZE][SIZE]) {
    srand(time(0));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            array[i][j] = rand() % 20 + 1;  // 수정된 부분: 대각선이 아닌 모든 요소를 채움
        }
    }
}

void printArray(int array[SIZE][SIZE]) {
    printf("배열 출력:\n");

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", array[i][j]);  // 공백 추가로 가독성 향상
        }
        printf("\n");
    }
    printf("\n");
}

void movePointer(void* array) {
    int x = 0, y = 0;
    int steps;

    while (1) {  // 수정된 부분: 항상 true로 평가되는 무한 루프
        steps = *((int*)array + x * SIZE + y);  // 현재 위치의 배열 값 가져오기
        printf("현재 위치: (%d, %d), 배열의 값: %d\n", x, y, steps);

        int new_x = x, new_y = y + steps;  // y좌표를 배열 값만큼 이동

        // y좌표가 배열의 범위를 초과할 경우 처리
        while (new_y >= SIZE) {
            new_y -= SIZE;  // y좌표를 SIZE만큼 감소
            new_x++;        // x좌표 증가
        }

        // 새로운 x좌표가 배열의 크기를 초과하면 종료
        if (new_x >= SIZE) {
            printf("더 이상 이동할 수 없습니다.\n종료 위치: (%d, %d), 배열의 값: %d\n", x, y, steps);
            break;
        }

        x = new_x;  // x좌표 업데이트
        y = new_y;  // y좌표 업데이트
    }
}