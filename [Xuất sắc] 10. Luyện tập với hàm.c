#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// input
void arrInput(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
//output
void arrOutput(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void arrAdd(int arr[], int pos, int n) {
    for(int i = n; i >= pos; i--){
        arr[i + 1] = arr[i];
    }
    printf("Nhap gia tri muon them: ");
    scanf("%d", &arr[pos]);
    n++;
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);

    }
}

void arrFix(int arr[], int pos, int n) {
    printf("Nhap gia tri muon sua: ");
    scanf("%d", &arr[pos]);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void arrMinus(int arr[], int pos, int n) {
    for(int i = pos; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void arrArrange(int arr[], int n, int check) {
    int a, b;
    for(int i = 0; i < n; i++) {
        int key;
        int j = i - 1;
        if(check == 1) {
            a = arr[i];
            b = arr[j];
            key = a;
        }else {
           b = arr[i];
           a = arr[j];
            key = b;
        }
        while (j >= 0 && a > b) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void arrIinearS(int arr[], int n, int pos) {
    int temp = 0;
    for(int i = 0; i < n; i++) {
        if(pos == arr[i]) {
            printf("phan tu %d tim thay tai vi tri %d", pos, i + 1);
            temp = 1;
        }
    }
    if(!temp) {
        printf("phan tu khong ton tai!!");
    }
}

void arrBinaryS(int arr[], int n, int pos) {
    for(int i = 0; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    int temp = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == pos) {
            printf("phan tu %d tim thay tai vi tri %d", pos, mid + 1);
            temp = 1;
            break;
        }else if(arr[mid] < pos) {
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    if(!temp) {
        printf("phan tu khong ton tai!!");
    }

}
int main() {
    int menu, menu1;;
    int arr[100];
    int n;
    int pos;
    menu:
    do {
        printf("=========================MENU=======================\n");
        printf("1. Nhập số phần tử cần nhập và giá trị các phần tử\n");
        printf("2. In ra giá trị các phần tử đang quản lý\n");
        printf("3. Thêm một phần từ vào vị trí chỉ định\n");
        printf("4. Sửa một phần từ ở vị trí chỉ định\n");
        printf("5. Xóa một phần từ ở vị trí chỉ định\n");
        printf("6. Sắp xếp các phần tử\n");
        printf("7. Tìm kiếm phần tử nhập vào\n");
        printf("8.Thoát\n");
        printf("Enter your number: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Nhap so phan tu can nhap: ");
            scanf("%d", &n);
            arrInput(arr, n);
            goto menu1;
            break;
            case 2:
                arrOutput(arr, n);
            goto menu1;
            break;
            case 3:
                printf("Nhap vi tri muon them: ");
            scanf("%d", &pos);
            arrAdd(arr, pos - 1, n);
            goto menu1;
            break;
            case 4:
                printf("Nhap vi tri muon sua: ");
            scanf("%d", &pos);
            pos--;
            arrFix(arr, pos, n);
            goto menu1;
            break;
            case 5:
                printf("Nhap vi tri muon xoa: ");
            scanf("%d", &pos);
            pos--;
            arrMinus(arr, pos, n);
            goto menu1;
            break;
            case 6:
                do {
                    printf("1.Giảm dần\n");
                    printf("2.Tăng dần\n");
                    scanf("%d", &menu1);
                }while (menu1 != 1 && menu1 != 2);
            if(menu1 == 1) {
                arrArrange(arr, n, 1);
            }else {
                arrArrange(arr, n, 2);
            }
            goto menu1;
            break;
            case 7:
                printf("Nhap phan tu muon tim: ");
            scanf("%d", &pos);
            do {
                printf("1.Linear search\n");
                printf("2.binary search\n");
                scanf("%d", &menu1);
            }while (menu1 != 1 && menu1 != 2);
            if(menu1 == 1) {
                arrIinearS(arr, n, pos);
            }else {
                do {
                    printf("1.Sap xep lai mang va tim\n");
                    printf("2.Back to menu\n");
                    scanf("%d", &menu1);
                }while (menu1 != 1 && menu1 != 2);
                if(menu1 == 1) {
                    printf("\n");
                    arrBinaryS(arr, n, pos);
                }else {
                    goto menu;
                }
            }
                goto menu1;
                break;
            default:
                goto menu;
                menu1:
                printf("\n") ;
                do {
                    printf("1.Back to menu\n");
                    printf("2.Exit\n");
                    scanf("%d", &menu1);
                }while (menu1 != 1 && menu1 != 2);
            if(menu1 == 1) {
                goto menu;
            }else {
                return 0;
            }
                break;
        }
    }while(menu != 8);
}
