#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;

        visited[entrance[0]][entrance[1]] = true; // forming a grid 
        q.push({entrance[0], entrance[1]});

        int steps = 0;
        int dr[] = {-1, 1, 0, 0}; // up down right left
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int levelSize = q.size();
            steps++;   

            for (int i = 0; i < levelSize; i++) {
                pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (int dir = 0; dir < 4; dir++) {
                    int nr = r + dr[dir]; // next row
                    int nc = c + dc[dir]; // next col

                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                        maze[nr][nc] != '+' && !visited[nr][nc]) {

                        
                        if (nr == 0 || nr == rows - 1 || nc == 0 || nc == cols - 1) {
                            return steps;
                        }

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return -1;   
    }
};