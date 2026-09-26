#include<iostream>
#include<vector>
using namespace std;

// Time: O(n + e) -> n rooms, e keys in each room
// Space: O(n) -> visited array + recursion stack

class Solution {
public:
    void dfs(int room, vector<vector<int>>& rooms, vector<bool>& visited,int& count) 
    {
    visited[room] = true;
    count++;

        for (int key : rooms[room]) {
            if (!visited[key]) {
                dfs(key, rooms, visited, count);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        int count = 0;

        dfs(0, rooms, visited, count);

        return count == rooms.size();
    }
};