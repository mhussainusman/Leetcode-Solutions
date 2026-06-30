// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {

        int n=chars.size();
        int read=0; int write=0;
        while(read<n){
            char currentChar=chars[read];
            int count=0;

        while(read<n && chars[read]==currentChar){
            read++;
            count++;
        }
        chars[write]=currentChar;
        write++;

        string countStr=to_string(count);
        for (int i=0;i<countStr.size();i++){
            chars[write]=countStr[i];
            write++;
        }

    
        }
        
      
        return write;
    }
};