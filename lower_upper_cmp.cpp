#include <iostream>
#include <algorithm>
#include <vector>

struct s {
    int a;
    int b;
};

std::vector<s>v;

bool ubcmp(const s& p, const int& element) {
    return p.a < element;
}
bool upcmp(const int& element, const s& p) {
    return element < p.a;
}


int main() 
{

    v.push_back({1,0});
    v.push_back({2,0});
    v.push_back({2,0});
    v.push_back({3,0});
    v.push_back({4,0});
    v.push_back({6,0});

    int num = 2; // 찾을 수
    int lbi = std::lower_bound(v.begin(),v.end(),num,ubcmp)-v.begin();
    int ubi = std::upper_bound(v.begin(),v.end(),num,upcmp)-v.begin();
    std::cout << lbi << " " << ubi;
}