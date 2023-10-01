#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLongestSubarray(vector<int>& a, long long k) {
        int n = a.size(); // size of the array.

        int left = 0, right = 0; // 2 pointers
        long long sum = a[0];
        int maxLen = 0;
        while (right < n) {
            // if sum > k, reduce the subarray from left
            // until sum becomes less or equal to k:
            while (left <= right && sum > k) {
                sum -= a[left];
                left++;
            }

            // if sum = k, update the maxLen i.e. answer:
            if (sum == k) {
                maxLen = max(maxLen, right - left + 1);
            }

            // Move forward the right pointer:
            right++;
            if (right < n) sum += a[right];
        }

        return maxLen;
    }
};

int main() {
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;

    Solution solution;//create an instance of the 'Solution' class so that you can access 'getLongestSubarray' function
    int len = solution.getLongestSubarray(a, k);

    cout << len << endl;
    return 0;
}
//output:{3}
