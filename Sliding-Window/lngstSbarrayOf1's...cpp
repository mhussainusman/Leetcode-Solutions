// Approach: Sliding Window
// Time: O(n)
// Space: O(1)
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen=0;int left=0;int notOne=0;
        for(int right =0;right<nums.size();right++){
            if(nums[right]!=1){notOne++;}
            
            if(notOne>1){
                if(nums[left]!=1)notOne--;
                left++;
            }
            maxLen=max(maxLen,right-left);
        }
        return maxLen;
    }
};