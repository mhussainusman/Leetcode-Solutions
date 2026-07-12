// Approach: HashMap
// Time: O(n+m)
// Size: O(n+m) 

#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1(nums1.begin(),nums1.end());
        unordered_set<int>s2(nums2.begin(), nums2.end());
        vector<int>ans0,ans1;
        for(int x: s1){if(s2.count(x)==0)ans0.push_back(x);}
        for(int x: s2){if(s1.count(x)==0)ans1.push_back(x);}
        return {ans0,ans1};
    }
};