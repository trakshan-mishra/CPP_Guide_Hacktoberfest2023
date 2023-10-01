#include<bits/stdc++.h>
using namespace std;

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target

class Solution {
public:
    // Brute Force Solution
    //  Time Complexity => O(N^4 x log(number of triplets)) 
    // Space Complexity => O(number of triplets)
    vector<vector<int>> bruteFourSum(vector<int> &nums, int target){
        int n = nums.size();

        set<vector<int>> s; // For removing the duplicate quadruplet

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());  // sort the quadruplets if they ask quadruplet in ascending order
                            s.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

    // Better Solution
    //  Time Complexity => O(N^3 x log(size of hashSet)) 
    // Space Complexity => O(number of triplets) + O(N)
    vector<vector<int>> betterFourSum(vector<int> &nums, int target){
        int n = nums.size();
        set<vector<int>> s;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                set<int> hashSet;
                for(int k=j+1;k<n;k++){
                    int fourth = target-(nums[i]+nums[j]+nums[k]);
                    if(hashSet.find(fourth)!=hashSet.end()){
                        vector<int> temp = {nums[i],nums[j],nums[k],fourth};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }

    // Optimal Solution
    //  Time Complexity => O(NlogN) + O(N^3) 
    // Space Complexity => O(number of triplets)
    vector<vector<int>> optimalFourSum(vector<int> &nums, int target){
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        return ans;
    }
};

int main() {

    // Array Initialization.
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution solution;//create an instance of the 'Solution' class so that you can access functions

    // Brute Force
    vector<vector<int>> bruteSolution = solution.bruteFourSum(nums,target);
    for(auto vec:bruteSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

    // Better approach
    vector<vector<int>> betterSolution = solution.betterFourSum(nums,target);
    for(auto vec:betterSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

    // Optimal approach
    vector<vector<int>> optimalSolution = solution.optimalFourSum(nums,target);
    for(auto vec:optimalSolution){
        for(auto elem:vec){
            cout << elem << " ";
        }
        cout<<endl;
    }

}

// Output is :
// [ [-2,-1,1,2] , [-2,0,0,2], [-1,0,0,1] ]