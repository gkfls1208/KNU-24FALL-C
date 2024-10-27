#include <stdio.h>

// 상품 정보를 저장할 구조체 정의
typedef struct {
    int id;        // 상품 ID
    char name[50]; // 상품명
    int price;     // 가격
} Product;

// 상품 정보를 출력하는 함수
void printProduct(Product p) {
    printf("상품 ID : %d\n", p.id);
    printf("상품명 : %s\n", p.name);
    printf("가격 : %d\n", p.price);
}

int main() {
    Product products[5]; // 최대 5개의 상품을 저장할 배열
    int count = 0;       // 입력된 상품의 개수
    int id;

    // 상품 정보 입력
    while (count < 5) {
        printf("상품 정보를 입력하세요 (입력 중단은 id에 0 입력)\n");
        printf("상품 ID : ");
        scanf("%d", &id);

        if (id == 0) {
            break; // ID가 0이면 입력 중단
        }

        products[count].id = id; // 상품 ID 저장

        printf("상품명 : ");
        scanf("%s", products[count].name); // 상품명 저장

        printf("가격 : ");
        scanf("%d", &products[count].price); // 가격 저장

        count++; // 상품 개수 증가
    }

    // 입력된 상품 목록 출력
    printf("\n<<입력된 상품 목록>>\n");
    for (int i = 0; i < count; i++) {
        printProduct(products[i]);
        printf("\n");
    }

    return 0;
}
