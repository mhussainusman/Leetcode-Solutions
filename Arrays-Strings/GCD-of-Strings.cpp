// Approach: GCD + String Concatenation
// TIME: O(n+m) where n and m are the lengths of the two strings
// SPACE: O(1) 1 because we are using only one result string
#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
       if (str1+str2!=str2+str1)return "";
       string result=str1.substr(0,gcd(str1.size(),str2.size()));
       return result;
    }

private:
    int gcd(int num1,int num2){
        int gcd=0,maxGcd=0;
        for (int i=1;i<=min(num1,num2);i++){
            if(num1%i==0&&num2%i==0){
                gcd=i;
                if (gcd>maxGcd){maxGcd=gcd;}
            }
        }
        return maxGcd;
    }
};