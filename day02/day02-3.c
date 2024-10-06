#include <stdio.h>

int main() {
    int i, cnt = 0;

    for (i = 0; i < 100; i++) {
        if (i % 12 == 0 || i % 7 == 0) {
            printf("%d \t", i);
            cnt++;
        }

        if (cnt == 6) {
            printf("\n");
            cnt = 0;
        }



    }

    return 0;
}