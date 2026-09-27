#include<iostream>
#include<vector>
using namespace std;
// Time: O(n+e)
// Space: O(n)

class Solution {
public:
    void dfs(int city, vector<vector<pair<int,int>>>& list, vector<bool>&visited, int &count){ 
            visited[city]=true;
            for(int n=0;n<list[city].size();n++){
                int nextCity=list[city][n].first;
                int cost=list[city][n].second;

                if(!visited[nextCity]){
                    count+=cost;
                    dfs(nextCity,list,visited,count);
                }
            }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        int count=0;
        vector<bool>visited(n,false);
        vector<vector<pair<int,int>>> list(n);

        int s=connections.size();
        for (int i=0;i<s;i++){
            int a = connections[i][0];
            int b = connections[i][1];
            list[a].push_back({b, 1});
            list[b].push_back({a, 0});
        }
        
        
            dfs(0, list,visited,count);
        return count;
    }
};