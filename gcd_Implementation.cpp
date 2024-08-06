#include <stdio.h>

int gcd(int A, int B) { // Greatest Common Divisor
    int b = A>B?A:B;
    int s = A>B?B:A;
    while(s) {
        int tmp = s;
        s = b%s;
        b = tmp;
    }
    return b;
}

int main() 
{
    int A,B;
    scanf("%d %d",&A,&B);
    printf("%d",gcd(A,B));
}