#include <iostream>
#include <vector>

using namespace std;

int main(){
    string a;
    string b;
    while(cin >> a >> b){
        int i=0,j=0,count;
        int temp_max=0;

        if(a.size()<b.size()){
                    for(i=b.size(); i>0; i--){
            for(j=a.size(); j>0;j--){
                 if(a[i]==b[j]){
                    count++;
                    i++;
                    j++;
                    }
                }
               temp_max = max(temp_max,count) ;
            }
        }else{
            for(i=a.size(); i>0; i--){
            for(j=b.size(); j>0;j--){
                 if(a[i]==b[j]){
                    count++;
                    i++;
                    j++;
                    }
                }
               temp_max = max(temp_max,count) ;
            }
        }

        cout << temp_max <<endl;
    }
      
             
        
        return 0;
}