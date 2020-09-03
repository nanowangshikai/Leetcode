#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> longestPathMatrix;
public:
    int longestPath(vector<vector<int>>& matrix, int row, int col, int pathLength){
        if (longestPathMatrix[row][col] != 0){
            return longestPathMatrix[row][col] + pathLength - 1;
        }
        int pre = pathLength - 1;

        int left = pathLength;
        if (col > 0 && matrix[row][col - 1] > matrix[row][col]){
            left = longestPath(matrix, row, col - 1, pathLength + 1);
        }

        int right = pathLength;
        if (col < matrix[0].size() - 1 && matrix[row][col + 1] > matrix[row][col]){
            right = longestPath(matrix, row, col + 1, pathLength + 1);
        }

        int up = pathLength;
        if (row > 0 && matrix[row - 1][col] > matrix[row][col]){
            up = longestPath(matrix, row - 1, col, pathLength + 1);
        }

        int down = pathLength;
        if (row < matrix.size() - 1 && matrix[row + 1][col] > matrix[row][col]){
            down = longestPath(matrix, row + 1, col, pathLength + 1);
        }

        int maxPath = max(left, max(right, max(up, down)));
        longestPathMatrix[row][col] = maxPath - pre;
        return maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()){
            return 0;
        }

        longestPathMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        int path = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                int current = longestPath(matrix, i, j, 1);
                if (current > path){
                    path = current;
                }
            }
        }
        return path;
    }
};


int main(){
    Solution s;

    vector<vector<int> > vect{ {9,9,4},{6,6,8},{2,1,1} };

    int a = s.longestIncreasingPath(vect);


    

    cout << "a ->" << a <<endl;
}