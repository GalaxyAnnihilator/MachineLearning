#include <stdio.h>
#include <math.h>
/*
nhap hai so a , b
swap gia tri a , b
khong dung bien thu 3

VD: a = 5, b = 10
sau khi swap: a = 10, b = 5
*/

int main(){
    int a,b;
    a = 5;
    b = 10;
    printf("Before swapping: a = %d, b = %d\n",a,b);

    a = a*b; // a = 50, b = 10
    b = a/b; // a = 50, b = 5
    a = a/b; // a = 10, b = 5

    printf("After swapping: a = %d , b = %d\n",a,b);
    return 0;
}