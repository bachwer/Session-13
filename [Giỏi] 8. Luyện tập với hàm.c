#include <stdio.h>
void commonDivied(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("%d", a);
}

int main() {
    int num1, num2;
    printf("Enter your first number: ");
    scanf("%d", &num1);
    printf("Enter your second number: ");
    scanf("%d", &num2);
    commonDivied(num1, num2);
}
