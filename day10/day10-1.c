#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장할 노드 구조체 정의
typedef struct Student {
    char name[100];
    int score;
    struct Student* next;
} Student;

// 리스트의 첫 번째 노드 포인터
Student* head = NULL;

// 학생 정보를 정렬된 위치에 삽입하는 함수
void insertStudent(char* name, int score) {
    // 새 노드 생성 및 초기화
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->score = score;
    newStudent->next = NULL;
    
    // 리스트가 비어있거나, 새로운 노드가 헤드 앞에 위치할 경우
    if (head == NULL || head->score < score) {
        newStudent->next = head;
        head = newStudent;
    } else {
        // 정렬된 위치를 찾음
        Student* current = head;
        while (current->next != NULL && current->next->score >= score) {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }
}

// 모든 학생 정보를 출력하는 함수
void printStudents() {
    printf("--------------------\n");
    Student* current = head;
    while (current != NULL) {
        printf("%s : %d\n", current->name, current->score);
        current = current->next;
    }
    printf("--------------------\n");
}

// 특정 이름의 학생 정보를 삭제하는 함수
void deleteStudent(char* name) {
    Student* current = head;
    Student* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("해당 학생이 존재하지 않습니다.\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;  // 헤드 노드 삭제
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("%s 학생 정보가 삭제되었습니다.\n", name);
}

int main() {
    int choice;
    char name[100];
    int score;

    // 시작 시 기본 데이터 삽입
    insertStudent("홍길동", 99);

    // 초기 리스트 출력
    printf("현재 성적 리스트:\n");
    printStudents();

    while (1) {
        printf("1. 학생의 성적을 입력\n");
        printf("2. 학생 정보 제거\n");
        printf("3. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("학생 이름 : ");
            scanf("%s", name);
            printf("%s의 성적 : ", name);
            scanf("%d", &score);
            insertStudent(name, score);
            printStudents();
        } else if (choice == 2) {
            printf("삭제할 학생 이름 : ");
            scanf("%s", name);
            deleteStudent(name);
            printStudents();
        } else if (choice == 3) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }

    // 모든 메모리를 해제 (프로그램 종료 전)
    Student* current = head;
    while (current != NULL) {
        Student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
