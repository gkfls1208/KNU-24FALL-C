#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { PLATINUM = 1, GOLD, SILVER, BRONZE } Rank;

typedef struct Customer {
    char customerName[100];
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
} Customer;

Customer* head = NULL;

// 고객을 우선 순위에 따라 삽입하는 함수
void insertCustomer(char* name, Rank rank, int order_amount, int point) {
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->customerName, name);
    newCustomer->rank = rank;
    newCustomer->order_amount = order_amount;
    newCustomer->point = point;
    newCustomer->prev = newCustomer->next = NULL;

    if (head == NULL) {
        head = newCustomer;
        return;
    }

    Customer* current = head;
    while (current != NULL) {
        int currentPriority = (current->rank * 1000000) - (current->order_amount * 1000) - current->point;
        int newPriority = (newCustomer->rank * 1000000) - (newCustomer->order_amount * 1000) - newCustomer->point;

        if (newPriority < currentPriority) {
            newCustomer->next = current;
            newCustomer->prev = current->prev;
            if (current->prev != NULL) current->prev->next = newCustomer;
            current->prev = newCustomer;
            if (current == head) head = newCustomer;
            return;
        }
        current = current->next;
    }

    current = head;
    while (current->next != NULL) current = current->next;
    current->next = newCustomer;
    newCustomer->prev = current;
}

// 고객 정보를 출력하는 함수
void printCustomers() {
    Customer* current = head;
    printf("--------------------\n");
    while (current != NULL) {
        printf("고객 이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n", 
            current->customerName, current->rank, current->order_amount, current->point);
        current = current->next;
    }
    printf("--------------------\n");
}

// 고객 이름으로 삭제하는 함수
void deleteCustomer(char* name) {
    Customer* current = head;
    while (current != NULL && strcmp(current->customerName, name) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("해당 고객이 존재하지 않습니다.\n");
        return;
    }

    if (current->prev != NULL) current->prev->next = current->next;
    if (current->next != NULL) current->next->prev = current->prev;
    if (current == head) head = current->next;
    
    free(current);
    printf("%s 고객 정보가 삭제되었습니다.\n", name);
}

// 고객 정보 수정 기능
void updateCustomer(char* name, Rank rank, int order_amount, int point) {
    deleteCustomer(name);
    insertCustomer(name, rank, order_amount, point);
}

int main() {
    int choice;
    char name[100];
    int rank, order_amount, point;

    while (1) {
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 고객 출력\n");
        printf("5. 프로그램 종료\n");
        printf("input : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("고객 이름 : ");
            scanf("%s", name);
            printf("고객 등급 (1: PLATINUM, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf("%d", &rank);
            printf("주문량 : ");
            scanf("%d", &order_amount);
            printf("포인트 : ");
            scanf("%d", &point);
            insertCustomer(name, (Rank)rank, order_amount, point);
            printCustomers();
        } else if (choice == 2) {
            printf("삭제할 고객 이름 : ");
            scanf("%s", name);
            deleteCustomer(name);
            printCustomers();
        } else if (choice == 3) {
            printf("수정할 고객 이름 : ");
            scanf("%s", name);
            printf("새 고객 등급 (1: PLATINUM, 2: GOLD, 3: SILVER, 4: BRONZE): ");
            scanf("%d", &rank);
            printf("새 주문량 : ");
            scanf("%d", &order_amount);
            printf("새 포인트 : ");
            scanf("%d", &point);
            updateCustomer(name, (Rank)rank, order_amount, point);
            printCustomers();
        } else if (choice == 4) {
            printCustomers();
        } else if (choice == 5) {
            printf("프로그램을 종료합니다.\n");
            break;
        } else {
            printf("잘못된 입력입니다. 다시 입력해주세요.\n");
        }
    }

    Customer* current = head;
    while (current != NULL) {
        Customer* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
