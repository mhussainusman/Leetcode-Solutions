//Approach: Hash and Sets
// Time: O(n) size of string
// Space: O(k) number of distinct characters

#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // same length
        if(word1.size()!=word2.size()){return false;}
       // map created for value and count
        unordered_map<char,int>freq1,freq2;
        for(char c:word1){freq1[c]++;}
        for(char c:word2){freq2[c]++;}

         // same distinct characters
        unordered_set<char>s1,s2;
        for(pair<char,int>p:freq1){s1.insert(p.first);}
        for(pair<char,int>p:freq2){s2.insert(p.first);}
        if(s1!=s2){return false;}// values of map checked, sets don't need to be sorted out

        // same collection of counts once sorted
        vector<int>v1,v2; // vectors are used instead of sets cause it also take duplicates
        for(pair<char,int>p:freq1){v1.push_back(p.second);} // map.second stores the count/freq of every value
        for(pair<char,int>p:freq2){v2.push_back(p.second);}
        sort(v1.begin(),v1.end());// sorting is done to check equality
        sort(v2.begin(),v2.end());
        if(v1!=v2){return false;}
        return true;
    }
};