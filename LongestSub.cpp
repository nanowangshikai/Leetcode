//Teach C++ 
//https://www.w3cschool.cn/cpp/cpp-data-types.html

//g++ -std=c++11 test.cpp

#include <iostream>

#include <unordered_set>

using namespace std; //告诉编译器是使用std命名空间

int main(){

    string sa = "abcabcbb";
    string s = "pwwkew";
    unordered_set<char> window;

    int left = 0;
    int len = s.size();
    int maxCount = 0;

    for(int i=0; i<len; ++i ){

        while(window.find(s[i]) != window.end() ){

            window.erase(s[left]);
            left++;

        }

        maxCount = max(maxCount, i-left+1);
        window.insert(s[i]);



    }

    cout << "maxCount is --> " << maxCount <<endl;

    return 0;
}