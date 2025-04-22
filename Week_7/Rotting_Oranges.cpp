#include <vector>
using namespace std;

class Solution {
public:
    bool nish(int currentMinute, vector<vector<int>>& grid, int rowCount, int colCount) {
        const int dRow[4] = {-1, 0, 1, 0};
        const int dCol[4] = {0, 1, 0, -1};

        bool foundNewRot = false;

        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {

                if (grid[row][col] == currentMinute) {
                    for (int dir = 0; dir < 4; ++dir) {
                      
                        int newRow = row + dRow[dir];
                      
                        int newCol = col + dCol[dir];


                        if (newRow >= 0 && newRow < rowCount && newCol >= 0 && newCol < colCount && grid[newRow][newCol] == 1) {
                            grid[newRow][newCol] = currentMinute + 1;
                            foundNewRot = true;
                        }
                    }

                }
            }
        }

        return foundNewRot;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid.empty() ? 0 : grid[0].size();

        int currentMinute = 2;

        while (nish(currentMinute, grid, rowCount, colCount)) {
            ++currentMinute;

        }
        for (const auto& row : grid) {
            for (int cell : row) {
                if (cell == 1) {
                    return -1;
                }
            }

        }
        return currentMinute - 2;
    }



};
