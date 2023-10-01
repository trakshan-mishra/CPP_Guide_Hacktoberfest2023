#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printLeaders(int arr[], int n) {
        vector<int> ans;
        
        // Last element of an array is always a leader,
        // push into ans array.
        int max = arr[n - 1];
        ans.push_back(arr[n-1]);

        // Start checking from the end whether a number is greater
        // than max no. from right, hence leader.
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > max) {
                ans.push_back(arr[i]);
                max = arr[i];
            }
        }
        
        return ans;
    }
};

int main() {
    // Array Initialization.
    int n = 6;
    int arr[n] = {10, 22, 12, 3, 0, 6};

    Solution solution;//create an instance of the 'Solution' class so that you can access 'PrintLeaders' function
    vector<int> ans = solution.printLeaders(arr, n);
    
    for(int i = ans.size()-1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    
    cout << endl;
    return 0;
}

//output is {22,12,6}
