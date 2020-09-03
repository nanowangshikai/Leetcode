#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int minPathSum(vector<vector<int> >& grid ){

            vector<vector<int> > dynamic=grid;

            int row = grid.size();
            int column = grid[0].size();
            
            for(int i=0; i<row; i++){
                for(int j=0; j<column; j++){
                    
                    if(i==0 && j==0) continue;
                    if(i==0){
                        dynamic[0][j] += dynamic[0][j-1];
                    }else if(j==0){
                        dynamic[i][0] += dynamic[i-1][0];
                    }else{
                        dynamic[i][j] += min(dynamic[i-1][j], dynamic[i][j-1]);
                    }
                    


                }
                
            }

            // for(int i=0; i<dynamic.size(); i++){
            //     for(int j=0; j<dynamic[i].size(); j++){
            //         cout << dynamic[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            return dynamic[row-1][column-1];
        }
};

int main(){
    Solution s;

    vector<vector<int> > twoD{ {1,3,1},{1,5,1},{4,2,1}};

    // for(int i=0; i<twoD.size(); i++){
    //     for(int j=0; j<twoD[i].size(); j++){
    //         cout << twoD[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int result = s.minPathSum(twoD);
    cout << result << " ";
}