#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main(){
    
    int n;
    cin >> n;

    while(n--){
        int state = 0;
        char cur; // current character
        string str; // target word

        cin >> str;
        char last = str[0];

        string ans = "";
        ans +=str[0];

        for(int i=1; i<str.size(); i++){
            cur = str[i];
            cout << "current state : " << state << endl;
            cout << "current cur : " << cur << endl;
            switch(state){
                case 0:
                {
                    if(cur==last){state=1;} // AA
                    else state = 0; //AB
                    break;
                }
                case 1:
                {
                    if(cur==last){
                        continue; // AAA
                    }else{
                        state=2; //AAB
                    }
                    break;
                }
                case 2:
                {
                    if(cur==last){continue;} //AABB
                    else state=0; //AABC , 
                    break;
                }
                default:
                    break;
            }
            ans = ans + cur;
            cout << "current ans " << ans <<endl;
            last = cur;

        }
        cout << ans <<endl;

    }

    return 0;
}