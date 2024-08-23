#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string base_converter(int a, int b, string n) {
    // 1. a진수인 n을 10진수로 변환
    long long int tmp = 0;
    for (int i=n.length()-1; i>=0; i--) {
        if ('0' <= n[i] && n[i] <= '9') tmp += (n[i]-'0')*pow(a,n.length()-1-i); 
        else tmp += (10+n[i]-'A')*pow(a,n.length()-1-i);
    }
    // 2. 10진수로 변환된 n을 b진수로 변환
    if (tmp == 0) return "0"; // n이 0이라면 0 반환
    string ans = "";
    while (tmp > 0) {
        if (0 <= tmp%b && tmp%b <= 9) ans = char('0'+tmp%b)+ans;
        else ans = char('A'+ tmp%b-10)+ans;
        tmp /= b;
    }
    return ans;
}

int main() 
{
    int a,b; // 2 <= a,b <= 36 , 10이상부터는 알파벳으로 표현
    string n;

    cin >> a >> b; 
    cin >> n;

    cout << base_converter(a,b,n);
}