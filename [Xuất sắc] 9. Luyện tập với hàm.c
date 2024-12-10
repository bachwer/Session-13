#include <stdio.h>
#include <math.h>
//1
void arrInput(int arr[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("arr[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
}
//2
void arrPrint(int arr[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
//3
void arrPrint1(int arr[100][100], int n) {
    int k = n - 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 && j == 0 || i == k && j == k || i == 0 && j == k || j == 0 && i == k){
                printf("%d\t", arr[i][j]);
            }else {
                    printf("\t");
            }
        }
        printf("\n");
    }
}

void arrPrint2(int arr[100][100], int n) {
    int k = n - 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0 || i == k || j == k){
                printf("%d\t", arr[i][j]);
            }else {
                printf("\t");
            }
        }
        printf("\n");
    }
}
//5
void arrPrint3(int arr[100][100], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                printf("%d\t", arr[i][j]);
            }else {
                printf("\t");
            }
        }
        printf("\n");
    }
    printf("\n");
//6
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(j == n - i - 1) {
                printf("%d\t", arr[i][j]);
            }else {
                printf("\t");
            }
        }
        printf("\n");
    }
}
//7
void arrPrime(int arr[100][100], int n) {
    int Prime;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            Prime = 1;
            if(arr[i][j] <= 1) {
                Prime = 0;
            }else{
                for(int k = 2; k <= sqrt(arr[i][j]); k++) {
                    if(arr[i][j] % k == 0) {
                        Prime = 0;
                        break;
                    }
                }
            }
            if (Prime == 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

int main() {
    int arr[100][100];
    int menu;
    int n = 0;
    do {
        printf("1.Nhập giá trị các phần tử của mảng\n");
        printf("2.In giá trị các phần tử của mảng theo ma trận\n");
        printf("3.In ra các phần tử ở góc theo ma trận\n");
        printf("4.In ra các phần tử nằm trên đường biên theo ma trận\n");
        printf("5.In ra các phần tử nằm trên đường chéo chính và chéo phụ theo ma trận\n");
        printf("6.In ra các phần tử là số nguyên tố theo ma trận\n");
        printf("7.Thoát\n");
        printf("Enter your number: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Nhap so cot va hang: ");
                scanf("%d", &n);
                arrInput(arr, n);
                break;
            case 2:
                if(n == 0) {
                    printf("Chua nhap mang: \n");
                }
                arrPrint(arr, n);
                break;
            case 3:
                if(n == 0) {
                    printf("Chua nhap mang: \n");
                }
                arrPrint1(arr, n);
                break;
            case 4:
                if(n == 0) {
                    printf("Chua nhap mang: \n");
                }
                arrPrint2(arr, n);
                break;
            case 5:
                if(n == 0) {
                    printf("Chua nhap mang: \n");
                }
                arrPrint3(arr, n);
                break;
            case 6:
                if(n == 0) {
                    printf("Chua nhap mang: \n");
                }
                arrPrime(arr, n);
                break;
        }
    }while (menu != 7);
}
