#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <typeinfo>


using namespace std;

class Solution{
    public:
        string addStrings(string num1, string num2){

            //两指针， 从后向前
            int i = num1.length()-1, j = num2.length()-1;
            //补位
            int add=0;
            int curAdd = 0;  //不保存考虑进位
            string ads = "";

            while(i>=0 || j>=0 || add!=0){
                int x = i>=0 ? (num1[i]-'0') : 0;
                int y = j>=0 ? (num2[j]-'0') : 0;
                curAdd = x+y;

                ads.push_back('0' + (curAdd+add)%10 );
                add = (curAdd+add) / 10;

                i--;
                j--;
            }
            reverse(ads.begin(), ads.end());
            return ads;
        }
};

int main(){
    Solution s;

    string n1 ="811";
    string n2 = "344";

    string a =s.addStrings(n1, n2);

    

    cout << a;
}