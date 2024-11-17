#include <iostream>

int tree[18][140000];

int treeSum(int aiml, int aimr, int l, int r, int lcnt, int ll) {
    if (r < aiml || aimr < l) return 0;
    if (aiml <= l && r <= aimr) return tree[lcnt][ll];
    int mid = (l+r)/2;
    return treeSum(aiml, aimr, l, mid, lcnt+1, ll*2)+treeSum(aiml, aimr, mid+1, r, lcnt+1, ll*2+1);
}

void treeUpdate(int lcnt, int ll) {
    tree[lcnt][ll] = tree[lcnt+1][ll*2]+tree[lcnt+1][ll*2+1];
    if (lcnt > 0) treeUpdate(lcnt-1,ll/2);
}

int main() 
{
    for (int i=0; i<100000; i++) tree[17][i] = 1;
    for (int i=16; i>=0; i--) {
        for (int j=0; j<(1<<i); j++) {
            tree[i][j] = tree[i+1][j*2]+tree[i+1][j*2+1];
        }
    }

    tree[17][4] = 0;
    treeUpdate(16,4/2);

    std::cout<<treeSum(0,123,0,(1<<17)-1,0,0);
}