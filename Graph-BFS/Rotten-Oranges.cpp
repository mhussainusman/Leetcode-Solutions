#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int,int>> q;
    int freshCount = 0;

    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                q.push({r, c});
            } else if (grid[r][c] == 1) {
                freshCount++;
            }
        }
    }

    if (freshCount == 0) return 0; 

    int minutes = 0;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    // BFS level by level
    while (!q.empty()) {
        int size = q.size();
        bool rottedAny = false;

        for (int i = 0; i < size; i++) {
            pair<int,int> curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for (int d = 0; d < 4; d++) {
                int newRow = row + dr[d];
                int newCol = col + dc[d];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols
                    && grid[newRow][newCol] == 1) {
                    grid[newRow][newCol] = 2; // rot it
                    freshCount--;
                    q.push({newRow, newCol});
                    rottedAny = true;
                }
            }
        }

        if (rottedAny) minutes++; 
    }

    
    return freshCount == 0 ? minutes : -1;
}
};