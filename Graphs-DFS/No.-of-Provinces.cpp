#include<iostream>
#include<vector>
using namespace std;
// Time: O(n+e)
// Space: O(n)
class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool> & visited){
        visited[i]=true;
        int n=isConnected.size();
        for(int j=0;j<n;j++){
            if(!visited[j]&&isConnected[i][j]==1){
                dfs(j, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};