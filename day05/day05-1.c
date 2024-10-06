#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int* stud_num;
    int* score;
    int sum = 0, avr = 0, max = 0, min = 2147483647;
    char** stud_name;


    printf("몇 명의 점수를 입력 받으시겠습니까? : ");
    scanf("%d", &N);

    stud_num = (int*)malloc(N * sizeof(int));
    score = (int*)malloc(N * sizeof(int));
    stud_name = (char**)malloc(N * sizeof(char*));

    for (int i = 0; i < N; i++) {
        stud_name[i] = (char*)malloc(100 * sizeof(char));
    }

    for (int i = 0; i < N; i++) {
        printf("이름 : ");
        scanf("%s", stud_name[i], 100);

        printf("학번 : ");
        scanf("%d", &stud_num[i]);

        printf("점수 : ");
        scanf("%d", &score[i]);
    }

    for (int i = 0; i < N; i++) {
        sum = score[i] + sum;
        if (max < score[i]) max = score[i];
        if (min > score[i]) min = score[i];
    }
    avr = sum / N;
    printf("평균 : %d \n", avr);
    printf("최대 : %d \n", max);
    printf("최소 : %d \n", min);

    free(score);
    free(stud_num);
    for (int i = 0; i < N; i++) {
        free(stud_name[i]);
    }
    free(stud_name);

    score = NULL;
    stud_num = NULL;
    for (int i = 0; i < N; i++) {
        stud_name[i] = NULL;
    }
    stud_name = NULL;



    return 0;
}