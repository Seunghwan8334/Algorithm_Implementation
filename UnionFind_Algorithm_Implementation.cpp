#include <iostream>
#include <map>

using namespace std;

map <string, int> m;

int num = 0;
string name[200003];
int parent[200003];
int ans[200003];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    ans[b] += ans[a]; // 집합의 개수를 합함
    parent[a] = b;
}

int main() 
{
    int n;
    cin >> n;

    while(n--) {
        string a,b;
        cin >> a >> b;

        if (m.find(a) == m.end()) { // 처음보는 이름이 들어오면 리스트에 추가
            parent[num] = num; // 처음에는 자기자신을 자신의 부모로 설정
            name[num] = a; // 배열에 이름을 번호로 저장
            ans[num] = 1; // 초기 자기자신만이 존재하는 집합의 크기는 1 
            m.insert({a,num++}); // map에 번호를 이름으로 저장
        }
        if (m.find(b) == m.end()) {
            parent[num] = num;
            name[num] = b;
            ans[num] = 1;
            m.insert({b,num++});
        }
        
        parent[m[a]] = Find(m[a]);
        parent[m[b]] = Find(m[b]);

        if (parent[m[a]] != parent[m[b]]) Union(parent[m[a]],parent[m[b]]); 
        // 두 이름이 서로 다른 집합에 있다면 병합
    }
    
    // 지금까지 입력된 모든 이름,그 이름이 속한 집합번호와 그 이름이 속한 집합의 크기를 출력한다.  
    for (int i=0; i<num; i++) {
        cout << name[i] << " " << Find(i) << " " << ans[Find(i)]<< "\n";
    }
}