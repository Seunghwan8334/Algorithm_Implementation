#include <stdio.h>

int lcm(int A, int B) { // Lowest Common Multiple
    int b = A>B?A:B;
    int s = A>B?B:A;
    while(s) {
        int tmp = s;
        s = b%s;
        b = tmp;
    }
    return (A*B)/b;
}

int main() 
{
    int A,B;
    scanf("%d %d",&A,&B);
    printf("%d",lcm(A,B));
}