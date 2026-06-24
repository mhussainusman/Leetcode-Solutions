// Approach: Manual parsing + Reverse Iteration
// Time: O(n)
// Space: O(n)
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        string word="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                word+=s[i];
            }
            else {
                if ( word!=""){
                    words.push_back(word);
                    word="";
                }

            }
        }
        if(word!=""){words.push_back(word);
        }
        string result;
        for(int i=words.size()-1;i>=0;i--){
            result+=words[i];
            if(i!=0)result+=" ";

        }
        return result;
    }
};
