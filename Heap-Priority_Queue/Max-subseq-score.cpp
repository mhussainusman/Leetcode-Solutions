#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> values;

        for (int i = 0; i < nums1.size(); i++) {
            values.push_back({nums2[i], nums1[i]});
        }

        sort(values.begin(), values.end(), greater<pair<int, int>>());

        priority_queue<int, vector<int>, greater<int>> smallestFirst;

        long long sumOfNums1 = 0;
        long long bestScore = 0;

        for (int i = 0; i < values.size(); i++) {
            int currentNums2 = values[i].first;
            int currentNums1 = values[i].second;

            smallestFirst.push(currentNums1);
            sumOfNums1 += currentNums1;

            if (smallestFirst.size() > k) {
                sumOfNums1 -= smallestFirst.top();
                smallestFirst.pop();
            }

            if (smallestFirst.size() == k) {
                long long score = sumOfNums1 * currentNums2;
                if (score > bestScore) {
                    bestScore = score;
                }
            }
        }

        return bestScore;
    }
};