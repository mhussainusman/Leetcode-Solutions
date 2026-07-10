// Approach: Prefix sum
// Time: O(n) where n is the size of the gain array
// Space: O(1) as we are using only constant space
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {       
        int current=0;
        int highest=0;
        for(int i=0;i<gain.size();i++){
            current+=gain[i];
            highest=max(highest,current);

        }
        return highest;
    }
};