#include <iostream>
#include <vector>

using namespace std;

int lower_bound(const vector<int>& arr, int value) {

    int left = 0, right = arr.size();
    
    while (left < right) {

        int mid = (left + right) / 2;
        if (arr[mid] < value) left = mid + 1;
        else right = mid;
    }
    // left == right
    return right;
}

int main() 
{
    vector<int> arr = {1, 1, 2, 2, 3, 6, 7, 8};
    cout << lower_bound(arr, 3) << endl;
    return 0;
}
