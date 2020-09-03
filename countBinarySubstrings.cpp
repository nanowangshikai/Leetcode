#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
        int countBinarySubstrings(string s){
            vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
    
        int count = 0;
        for(int i=1; i<counts.size(); ++i){
            count = count + min(counts[i],counts[i-1]);            
        }
        return count;
        }
};

int main(){
    Solution s;

    string a = "01001";

    s.countBinarySubstrings(a);
    return 0;
}