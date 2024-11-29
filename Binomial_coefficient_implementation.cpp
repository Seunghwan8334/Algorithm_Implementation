#include <iostream>
#define MOD 1000000007

long long int power(int a, int k)
{
    if (k==1) return a;
    long long int tmp = power(a, k/2);
    if (k%2) return (((tmp*tmp)%MOD)*a)%MOD;
    else return (tmp*tmp)%MOD;
}

long long int f[4000003];

int main()
{
    int n,k; 
    std::cin>>n>>k;
    f[1] = 1;
    for (int i=2; i<=n; i++) f[i] = (f[i-1]*i)%MOD;
    if (k == 0 || n == k) std::cout<<1;
    else std::cout << (f[n]*power((f[k]*f[n-k])%MOD, MOD-2))%MOD;
}