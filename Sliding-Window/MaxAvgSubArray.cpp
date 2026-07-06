// Approach: Sliding Window
// Time: O(n)
// Space: O(1)
using namespace std;
#include<vector>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double current=0;
        int n= nums.size();
        for(int i=0;i<k;i++){
            current+=nums[i];
        }
        double max=current;
        for(int j=1;j<=n-k;j++){
            current=current-nums[j-1]+nums[j+k-1];
            if (current>max){max=current;}

        }
        return max/k;
    }
};