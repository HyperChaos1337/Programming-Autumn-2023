#include <stdio.h>
#include <conio.h>

void int_to_bin(short int num){
    printf("%d ", (num >> sizeof(short int)*8-1)&1);
    for(int i = sizeof(num)*8-2; i >= 0; --i){
        printf("%d", (num>>i)&1);
    }
}

void double_to_bin(double num){
    long long int temp = *(long long int*)&num;
    printf("%lld ", (temp >> sizeof(double)*8-1)&1);
    for(int i = sizeof(double)*8-2; i >= sizeof(double)*8-12; --i){
        printf("%lld", (temp>>i)&1);
    }
    printf(" ");
    for(int i = sizeof(double)*8-13; i >= 0; --i){
        printf("%lld", (temp>>i)&1);
    }
}

void int_shift(short int num, unsigned count, unsigned direction){
    if(direction == 0) num = (num << count) | (num >> sizeof(num)*8 - count);
    if(direction == 1) num = (num >> count) | (num << sizeof(num)*8 - count);
    printf("%d = ", num); int_to_bin(num);
}

void double_shift(double num, unsigned count, unsigned direction){
    long long temp = *(long long*)&num;
    if(direction == 0) temp = (temp << count) | (temp >> (sizeof(double)*8 - count));
    if(direction == 1) temp = (temp >> count) | (temp << (sizeof(double)*8 - count));
    num = *(double*)&temp;
    printf("%e = ", num); double_to_bin(num);
}

void exec(){

    short int a;
    double b;
    puts("Input short integer and double:"); scanf_s("%hd %lf", &a, &b);
    puts("");
    puts("Result:");
    printf("%d = ", a); int_to_bin(a);
    printf("\n");
    printf("%lf = ", b); double_to_bin(b);
    puts("\n");

    int choice;
    puts("Select data type to shift (1 for short integer, 2 for double)");
    unsigned count, direction;
    scanf_s("%d", &choice);
    if(choice == 1){
        puts("Shift short integer. Enter bytes to move and direction (0 for left, 1 for right)\n");
        scanf_s("%d %d", &count, &direction);
        puts("");
        puts("Result:\n"); int_shift(a, count, direction);
    }
    if(choice == 2){
        puts("Shift double. Enter bytes to move and direction (0 for left, 1 for right)\n");
        scanf_s("%d %d", &count, &direction);
        puts("");
        puts("Result:\n"); double_shift(b, count, direction);
    }
    getch();
}

int main() {
    exec();
}
