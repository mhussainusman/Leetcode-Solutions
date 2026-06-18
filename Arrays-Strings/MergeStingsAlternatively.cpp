// Appraoch: Two Pointers
// TIME: O(n+m) where n and m are the lengths of the two strings
// SPACE: O(n+m) for the result string

#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result="";
        int i =0, j=0;
        while(i<word1.size()|| j<word2.size()){
            if (i<word1.size()){
                result +=word1[i];
                i++;}

               if(j<word2.size()){
                result+=word2[j];
                j++;
               } 
                
            }

            return result;

        }
    
};