#include <stdio.h>

int prime(int x) { 
    if (x == 1) return 0;
    for (int i=2; i*i <= x; i++) { // 에라토스테네스의 체 이용
        if (x%i == 0) return 0;
    }
    return 1;
}

int main() 
{
    int n;
    scanf("%d",&n);
    printf("%d",prime(n)); // 소수이면 1 반환
}