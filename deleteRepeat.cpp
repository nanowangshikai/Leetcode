#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s;

    while(getline(cin, s)){
        vector<char> a;
        vector<char> result;
        for(int i=0; i<s.size(); i++){
            a.push_back(s[i]);
        }
        result.push_back(a[0]);
        bool find=false;
        for(int i=1;i<a.size();i++){
            for(int j=0;j<result.size();j++){
                if(result[j]==a[i]){
                    find = true;
                    break;
                }
            }
            if(!find){
                    result.push_back(a[i]);
                    find=false;
            }
        }
        
        string fin;
        for(int i=0; i<result.size(); i++){
            // fin +=result[i];
            cout << result[i];
        }
        // cout << fin <<endl;
    }
    
}