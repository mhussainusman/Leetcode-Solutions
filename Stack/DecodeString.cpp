using namespace std;
#include<string>
#include<stack>
class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string curStr = "";
        int curNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                curNum = curNum * 10 + (c - '0'); // handles multi-digit numbers
            } else if (c == '[') {
                countStack.push(curNum);
                strStack.push(curStr);
                curNum = 0;
                curStr = "";
            } else if (c == ']') {
                int repeatTimes = countStack.top();
                countStack.pop();
                string prevStr = strStack.top();
                strStack.pop();

                string temp = "";
                for (int i = 0; i < repeatTimes; i++) temp += curStr;
                curStr = prevStr + temp;
            } else {
                curStr += c; // regular letter
            }
        }
        return curStr;
    }
};