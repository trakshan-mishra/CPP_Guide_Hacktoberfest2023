#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
// and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    // Brute Force Solution
    //  Time Complexity => O(N^3 x log(number of triplets)) 
    // Space Complexity => O(number of triplets)
    vector<vector<int>> bruteThreeSum(vector<int> &nums){
        int n = nums.size();

        set<vector<int>> s; // For removing the duplicate triplets

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end()); // sort the triplets if they ask triplets in ascending order
                        s.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

    // Better Solution
    //  Time Complexity => O(N^2 x log(size of hashSet)) 
    // Space Complexity => O(number of triplets) + O(N)
    vector<vector<int>> betterThreeSum(vector<int> &nums){
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n-2;i++){
            set<int> hashSet;
            for(int j=i+1;j<n-1;j++){
                int third = -(nums[i]+nums[j]);
                if(hashSet.find(third)!=hashSet.end()){
                    vector<int> temp = {nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

    // Optimal Solution
    //  Time Complexity => O(NlogN) + O(N^2) 
    // Space Complexity => O(number of triplets)
    vector<vector<int>> optimalThreeSum(vector<int> &nums){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++; // To skip the duplicates
                    while(j<k && nums[k]==nums[k+1]) k--; // To skip the duplicates
                }
                else if(sum<0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};

int main() {

    // Array Initialization.
    vector<int> nums = {-1,0,1,2,-1,-4};

    Solution solution;//create an instance of the 'Solution' class so that you can access functions

    // Brute Force
    vector<vector<int>> bruteSolution = solution.bruteThreeSum(nums);
    for(auto vec:bruteSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

    // Better approach
    vector<vector<int>> betterSolution = solution.betterThreeSum(nums);
    for(auto vec:betterSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

    // Optimal approach
    vector<vector<int>> optimalSolution = solution.optimalThreeSum(nums);
    for(auto vec:optimalSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

}

// Output is :
// [ [-1,-1,2] , [-1,0,1] ]