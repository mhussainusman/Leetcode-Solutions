// Approach: Two Pointers
// Time: O(n)
// Space: O(1)
using namespace std;
#include<vector>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right= height.size()-1;
        int maxContainer=min(height[left],height[right])*(right-left);
        while(left<right){
            int crntCntynr=min(height[left],height[right])*(right-left);
            if(crntCntynr>maxContainer){maxContainer=crntCntynr;}
            if (height[left]<height[right])left++;
            else right--;
        }
        return maxContainer;
    }
};