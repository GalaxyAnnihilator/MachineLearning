#include <stdio.h>

/*
Input: Ba canh a,b,c cua mot tam giac
Output: Loai tam giac: vuong, can, deu, thuong
*/

int main(){
    float a,b,c;
    printf("Enter the edges of the triangle: ");
    scanf("%f %f %f",&a, &b, &c);
    if (a+b>c && b+c>a && a+c>b){
        if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a ){
            printf("Tam giac vuong");
        }
        else if (a==b && b==c){
            printf("Tam giac deu");
        }
        else if (a==b || b==c || a==c){
            printf("Tam giac can");
        }
        else{
            printf("Tam giac thuong");
        }
    }
    else{
        printf("Khong phai tam giac");
    }
    printf("\n");
    return 0;
}