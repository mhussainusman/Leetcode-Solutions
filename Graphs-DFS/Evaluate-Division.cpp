#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// Time: O(n+e)
// Space: O(n)
class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> adj;

    bool dfs(string curr, string target, unordered_set<string>& visited, double product, double& result) {
        if (curr == target) {
            result = product;
            return true;
        }

        visited.insert(curr);

        for (int i = 0; i < adj[curr].size(); i++) {
            string nextNode = adj[curr][i].first;
            double weight = adj[curr][i].second;

            if (visited.find(nextNode) == visited.end()) {
                if (dfs(nextNode, target, visited, product * weight, result)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> results;

        for (int i = 0; i < queries.size(); i++) {
            string src = queries[i][0];
            string dst = queries[i][1];

            if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
                results.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;
            double result = -1.0;

            if (dfs(src, dst, visited, 1.0, result)) {
                results.push_back(result);
            } else {
                results.push_back(-1.0);
            }
        }

        return results;
    }
};