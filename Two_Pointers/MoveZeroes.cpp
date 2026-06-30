// Approach: Two Pointers
// Time: O(n)
// Space: O(1)
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read=0;
        int write=0;
        int n=nums.size();
        int zCnt=0;
        while(read<n){
            int currentNum=nums[read];
            if(currentNum==0){
                read++;
                zCnt++;
                
            }
            else{read++;
            nums[write]=currentNum;
                write++;
             }

        }
        for(int i=n-1;zCnt>0;i--,zCnt--){
            nums[i]=0;
            
        }
    }
};