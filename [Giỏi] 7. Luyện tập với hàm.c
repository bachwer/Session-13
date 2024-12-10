#include <stdio.h>
// funcstion to input each number into arr
void arrInput(int arr[100][100], int cols, int row) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < row; j++) {
            printf("arr[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}
// funcstion to output
void arrPrint(int arr[100][100], int cols, int row) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int cols,row;
    int arr[100][100];
    do {
        printf("Enter cols number: ");
        scanf("%d", &cols);
        printf("Enter row number: ");
        scanf("%d", &row);
        if(cols < 1 || row < 1 || cols > 100 || row > 100) {
            printf("Invalid!!!\n");
        }
    }while(cols < 1 || row < 1 || cols > 100 || row > 100);
    arrInput(arr ,cols, row);
    arrPrint(arr ,cols, row);
}
