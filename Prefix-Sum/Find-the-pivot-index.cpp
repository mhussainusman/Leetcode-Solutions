// Approach: Prefix sum
// Time: O(n) where n is the size of the nums array
// Space: O(n) for the p array to store prefix sums
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>p(nums.size());
        p[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            p[i]=p[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            int leftSum=0;int rightSum=0;
            if(i!=0&&i!=nums.size()-1){ leftSum=p[i-1];rightSum=p[nums.size()-1]-p[i];}
            else if(i==0){
                rightSum=p[nums.size()-1]-p[i];
            }
            else if(i==nums.size()-1){leftSum=p[i-1];}
            if(leftSum==rightSum){return i;}
        }
        return -1;
        
    }
};