// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
#include <string>
using namespace std;
class Solution {
    
private:
 bool isVowel(char c){
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
        return true;
        else return false;
    }

public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(!isVowel(s[left])){left++;}
             else if(!isVowel(s[right])){right--;}
                else{swap(s[left],s[right]);}


        }
        return s;
    }
 
};