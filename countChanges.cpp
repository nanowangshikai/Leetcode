#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution{
    public:
        int countChanges(vector<string> dic, int n, string s, string t){
           vector<string>::iterator ite = find(dic.begin(), dic.end(), s);
           int result = BFS(s,t,dic);
           if(ite != dic.end()){--result;}
           return result; 
        }

    private:
        int BFS(string start, string end, vector<string> &dic){
            if(start==end) return 0;
            queue<pair<string,int> > q;
            q.push(make_pair(start, 1));

            vector<string> visited;
            visited.push_back(start);
            while(!q.empty()){
                pair<string,int> cur = q.front();
                q.pop();
                string word = cur.first;
                int size = word.size();

                for(int i=0; i<size; ++i){
                    string newWord(word);
                    for(int j=0; j<26; ++j){
                        newWord[i] = 'a' + j;
                        if(newWord == end ) return cur.second + 1;
                    }

                    vector<string>::iterator ite = find(dic.begin(),dic.end(), newWord);
                    vector<string>::iterator ite2 = find(visited.begin(),visited.end(), newWord);
                    
                    if(ite2 == visited.end() && ite != dic.end()){
                        visited.push_back(newWord);
                        q.push(make_pair(newWord,cur.second+1));
                    }
                }

            }
            return -1;
        }
};


int main(){
    Solution s;

    vector<string> dic{"abc", "adc", "bdc", "aaa"};
    int n=4;
    string ss = "abc";
    string t = "bdc";

    int a = s.countChanges(dic, n, ss, t);

    cout << "final is " << a <<endl;
}