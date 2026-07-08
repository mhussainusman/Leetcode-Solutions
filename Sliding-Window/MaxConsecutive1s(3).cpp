// Approach: sliding window
// Time: O(n)
// Space: O(1)

#include <vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen=0;int left=0;int zCnt=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0)zCnt++;

            while(zCnt>k){
             if(nums[left]==0)zCnt--;
                left++; // moves on every loop until zCnt is under k
            }
          maxLen=max(maxLen,(right-left)+1);
        }
              return maxLen;
       
    }
};