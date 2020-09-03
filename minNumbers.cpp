#include <iostream>
#include <string>


using namespace std;

int main(){
    
    string str, temp;
    int i, m, min;
    int a[26];
    while(cin >> str){
        for(i=0; i<26; ++i){
            a[i] = 0;
        }

        m = str.size();
        for(i=0; i<m; i++){
            a[str[i]-'a']++;
        }
        min = a[str[0]-'a'];

        for(i=0; i<m; i++){
            if(a[str[i]-'a'] <= min ){
                min = a[str[i] - 'a'];
                cout << "min is --> " << min << endl;
            }
        }

        for(i=0; i<m; i++){
            if(a[str[i] - 'a' ] > min ){
                
                cout << "this is bigger" << a[str[i]-'a'] << endl;

                cout << str[i];
            }
        }
        cout << endl;

    }
    
}