#include <stdio.h>
int main() 
{
    int left,right,num;
    scanf("%d %d %d",&left, &right, &num);

    while(left < right) {
        printf("left = %d right = %d\n",left,right);
        int mid = (left+right)/2;
        if (mid <= num) left = mid+1;
        else right = mid;
    }
    // right 값이 upperbound가 된다
    printf("%d",right);
}