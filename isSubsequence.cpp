#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        bool isSubsequence(string s, string t){
            
            if(s.size()>100 || t.size() >500000){
                return 0;
            }

            int point1, point2;

            while(point1 != t.size())
                if(point2==s.size()){
                    break;
                }else{
                    if(t[point1]==s[point2]){
                        cout << "matched patthern -->" << t[point1] <<endl;
                        cout << "matched sub-->" << s[point2] <<endl;
                        point1++;
                        point2++;
                        
                        

                    }else{
                        point1++;
                    }
                }
            
            if(point2 == s.size()){
                return true;
            }


            return false;
        }

        //dynamic programming
        bool isSubsequence2(string s, string t) {
        int n = s.size(), m = t.size();

        //行分配 m+1 个， 列分配了26个0
        vector<vector<int> > f(m + 1, vector<int>(26, 0));
        for (int i = 0; i < 26; i++) {
            f[m][i] = m;
        }

        // 在行数0-5行，每行26个位置 中查找， 从前往后 如最后一个字母 c == 2 + 97, 这里i是5，j是2
        // 并把这个f[5][2] = i  whiich is f[i][j] = i 说明c在 变量f的第五行，第二个
        // 否则都为6
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                if (t[i] == j + 'a'){

                    f[i][j] = i;

                }else{

                    
                    f[i][j] = f[i + 1][j];
                }
            }
        }

        //  for(int i=0; i<f.size();++i){
        //     for(int j=0; j<f[0].size(); j++){
        //         cout << "now f[i][j] is -->" << f[i][j] <<endl;
        //     }
        // }
        int add = 0;
        for (int i = 0; i < n; i++) {
            if (f[add][s[i] - 'a'] == m) {
                return false;
            }
            add = f[add][s[i] - 'a'] + 1;
        }
        return true;
    }



};

int main(){
    Solution s;

    string pattern = "ahbgdc";
    string sub = "ahc";

    bool a = s.isSubsequence2(sub, pattern);
    cout << "This match is-->" << a <<endl;



}