// Approach: Hash and sets
// Time: O(n)
// Space: O(n)
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int x: arr)freq[x]++;
        unordered_set<int>s1;
        for(pair<int,int>p:freq){
            if(s1.count(p.second))return false;
            s1.insert(p.second);
        }
        return true;
    }
    
};