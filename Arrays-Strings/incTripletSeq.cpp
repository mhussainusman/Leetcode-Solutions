
/*
Approach: We can use two variables to keep track 
of the smallest and second smallest numbers we have 
seen so far. As we iterate through the array, 
we update these variables accordingly. 
If we find a number that is greater than both,
 we return true, indicating that an increasing triplet subsequence exists.
 */
// Time: 0(n)
// Space: 0(1)
#include<climits>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        
        int smallest=INT_MAX; 
        int secSmall=INT_MAX;
        for(int i=0;i<n;i++){
           if(nums[i]<=smallest){smallest=nums[i];}
            else if (nums[i]<=secSmall){secSmall=nums[i];}
            else{return true;}
                
        }
        return false;
    }
};