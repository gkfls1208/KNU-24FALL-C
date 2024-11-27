#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    // 최대 토핑 종류 수 정의
    const int MAX_TOPPING = 10000;

    // 왼쪽과 오른쪽 토핑 개수 배열 선언
    int leftCount[MAX_TOPPING + 1] = {0};
    int rightCount[MAX_TOPPING + 1] = {0};

    // 오른쪽 토핑 종류 카운트 초기화
    int rightKinds = 0;
    for (size_t i = 0; i < topping_len; i++) {
        if (rightCount[topping[i]] == 0) {
            rightKinds++;
        }
        rightCount[topping[i]]++;
    }

    int leftKinds = 0;
    int result = 0;

    // 토핑 배열 순회
    for (size_t i = 0; i < topping_len; i++) {
        // 현재 토핑을 왼쪽으로 이동
        if (leftCount[topping[i]] == 0) {
            leftKinds++;
        }
        leftCount[topping[i]]++;

        // 현재 토핑을 오른쪽에서 제거
        rightCount[topping[i]]--;
        if (rightCount[topping[i]] == 0) {
            rightKinds--;
        }

        // 왼쪽과 오른쪽 토핑 종류 비교
        if (leftKinds == rightKinds) {
            result++;
        }
    }

    return result;
}

// 테스트 코드
int main() {
    int topping1[] = {1, 2, 1, 3, 1, 4, 1, 2};
    size_t toppingSize1 = sizeof(topping1) / sizeof(topping1[0]);
    printf("Result: %d\n", solution(topping1, toppingSize1)); // 출력: 2

    int topping2[] = {1, 2, 3, 1, 4};
    size_t toppingSize2 = sizeof(topping2) / sizeof(topping2[0]);
    printf("Result: %d\n", solution(topping2, toppingSize2)); // 출력: 0

    return 0;
}
