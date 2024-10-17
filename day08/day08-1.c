#include <stdio.h>
#include <ctype.h>
#include <string.h>

void reverseString(char *str) {
    int len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        // 앞쪽 포인터가 영어 문자가 아닐 경우 이동
        while (start < end && !isalpha((unsigned char)*start)) {
            start++;
        }
        // 뒤쪽 포인터가 영어 문자가 아닐 경우 이동
        while (start < end && !isalpha((unsigned char)*end)) {
            end--;
        }
        // 영어 문자끼리 교환
        if (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
}

int main() {
    char str[100];

    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    // 문자열의 줄바꿈 제거
    str[strcspn(str, "\n")] = 0;

    reverseString(str);
    printf("반전된 문자열: %s\n", str);

    return 0;
}
