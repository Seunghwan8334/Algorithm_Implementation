#include <iostream>
#include <vector>

using namespace std;

int upper_bound(const vector<int>& arr, int value) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= value) left = mid + 1;
        else right = mid;
    }
    // left == right
    return right;
}

int main() 
{
    vector<int> arr = {1, 1, 2, 2, 3, 6, 7, 8};
    cout << upper_bound(arr, 3) << endl;
    return 0;
}
