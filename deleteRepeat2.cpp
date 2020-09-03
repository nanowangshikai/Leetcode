#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

int main()
 {
     string instr,outstr;
     unordered_set<char> sc; //用来去重字符串中重复字符
     getline(cin,instr);
     for(auto c:instr)
     {
         if(sc.find(c) == sc.end()) // 如果set中没找到该字符
         {
             sc.insert(c);
             outstr.append(1,c);
         }
         
     }

    // for(auto i: sc){
    //     cout << "-->"<<i<<endl;
    // }

     cout<< outstr <<endl;
     return 0;
 }