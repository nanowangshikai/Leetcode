#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
    public:

        void dfs(string s, string cur, vector<string> &result, int count){

            

            if(count==4 && s.size() == 0){
                cur.pop_back(); //把最后一个 “.” 给pop掉
                result.push_back(cur);
                cout << "now need to push --> " << cur << endl;
                return ; 
            }

            // 如果这个s不为空但深度又达到了4 则回溯
            if(count==4 && s.size()){
                // cout << "The result is not possible --> " << cur << endl;
                return;
            }

            int len = s.size();
            for(int i=1; i<=3 && i<=len; ++i){
                string ss = s.substr(0,i);
                int num = stoi(ss);
                if(to_string(num).size()!=ss.size() ) {
                    return ;
                }
                if(num<=255 && num >=0){
                    string temp = cur;
                    cur = cur+(ss+'.');
                    dfs(s.substr(i), cur, result, count+1);
                    cur = temp;
                }
            }


        }


        vector<string> restoreIpAddresses(string s){
            vector<string> result;
            dfs(s , "", result, 0);
            return result;
        }
};

int main(){
    Solution s;
    string num = "25525511135";
    s.restoreIpAddresses(num);
    return 0;
}