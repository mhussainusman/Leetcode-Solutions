// Approach : Two Pointers
// Time : O(n)
// Space : O(1)
using namespace std;
#include<string>
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool result=true;
        int i=0, j=0;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j])i++;
            j++;
        }
        
        return i==s.size();
    }
};