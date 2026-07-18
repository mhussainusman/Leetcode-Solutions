// Removing Stars From a String
// Approach: use a stack (vector<char> as stack) — push letters, pop on '*'
// Time: O(n)
// Space: O(n)
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        string st; // acts as stack, and directly builds the answer
        for (char c : s) {
            if (c == '*') st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
};