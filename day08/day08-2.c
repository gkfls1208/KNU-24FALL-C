#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void fillRandom(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);
void movePointer(void* array);

int main(){
    int array[SIZE][SIZE];

    fillRandom(array);
    printArray(array);
    movePointer(array);

    return 0;
}

void fillRandom(int array[SIZE][SIZE]){
    srand(time(0));

    for (int i = 0; i<SIZE; i++){
        for (int j = 0; j<SIZE; j++){
            array[i][i] = rand()%20+1;
        }
    }
}

void printArray(int array[SIZE][SIZE]){

    printf("배열 출력 :");

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%2d",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void movePointer(void* array){
    int x=0, y=0;
    int steps;
    //int* ptr = (int*)array;

    while(0){
        steps = *((int*)array + x * SIZE +y);
        printf("현재 위치 : (%d, %d), 배열의 값 : %d\n",x,y,steps);

        int new_x = x, new_y = y + steps;

        while(new_y >= SIZE){
            new_y -= SIZE;
            new_x++;
        }

        if(new_x>=SIZE){
            printf("더 이상 이동할 수 없습니다. \n종료 위치 : (%d, %d), 배열의 값 : %d\n", x, y, steps);
            break;
        }

        x=new_x;
        y=new_y;
    }
}