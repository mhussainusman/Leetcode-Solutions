// Approach: Hash map ( row freq wounter with vector keys)
// Time: O(n^2 log n)
// Space: O(n)
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>, int>rowFreq;
        for(int i=0;i<n;i++){
            rowFreq[grid[i]]++;
        }

            int count=0;
       
        for(int i=0;i<n;i++){
                 vector<int>col;
            for(int j=0;j<n;j++){
                col.push_back(grid[j][i]);
            }
            if(rowFreq.count(col)){
                count+= rowFreq[col];
            }
        }
        return count;
        
    }
};