#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    

    public:

        bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
            vector<int> vec1(numCourses,0);
            vector<vector<int>> edges(numCourses);
            for(vector<int> pre: prerequisites){
                vec1[pre[1]] ++;
                edges[pre[0]].push_back(pre[1]);
            }

            queue<int> q;
            for(int i=0; i<numCourses; ++i){
                if(vec1[i] == 0) q.push(i);
            }
            int count = 0;
            while(!q.empty()){
                for(int i=q.size() ; i>0; i-- ){
                    int cur = q.front(); q.pop();
                    count++;
                    for(int edge : edges[cur]){
                        if(--vec1[edge] == 0){
                            q.push(edge);
                        }
                    }
                }
            }

            return count==numCourses;
        }
};

int main(){
    Solution s;

    int numCourses = 4;
    vector<vector<int>> prerequisites{{0,1}, {0,2}, {0,3},{2,1}};

    bool a = s.canFinish(numCourses, prerequisites);
    cout << "final is -->" << a <<endl;
}