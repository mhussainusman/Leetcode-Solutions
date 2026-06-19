// Approach: fist find maccandykid then compare with other kids with extra candies
// Time:O(n) 2 loops of n-input size of candies vector
// Space:O(n) for the result vector
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandyKid= candies[0];
        for(int i=1;i<candies.size();i++){
            if (candies[i]>maxCandyKid){maxCandyKid=candies[i];}
        }
        vector<bool> result(candies.size());
        for(int i=0;i<candies.size();i++){
            if (candies[i]+extraCandies>=maxCandyKid){
                result[i]=true;
            }
            else result[i]=false;

        }
        return result;
    }
};