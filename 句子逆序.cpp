#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int main(){

    string s;
    getline(cin, s);

    //breaking input into word using string stream
    stringstream ss(s); 
    string res="", tmp;
    while(ss>>tmp){
        if(res==""){res=tmp;}
        else{res=tmp+" "+res;}
    }
    cout << res;

    return 0;
}