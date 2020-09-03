#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int total;
    cin >> total;
    if(total>1024) return 0;

    int candyColor, numOfCandy;
    unordered_map<int ,int> list;
    while(cin >>numOfCandy>>candyColor){
        // if(numOfCandy<1 ||numOfCandy>1024) return 0;
        // if(candyColor!=1 || candyColor!=2) return 0;
        list[numOfCandy] = candyColor;
    }


    vector<int> v1;
    vector<int> v2;


        for(auto i : list){
            if( i.second==1){
               v1.push_back(i.first);

            }else if(i.second==2){
                v2.push_back(i.first);
            }
        }

    int index, max=0;
    vector<int > a;
    for( int j=0; j<3; j++){    
        for(int i=0; i<v1.size(); i++){
        if(v1[i]>max){
            max = v1[i];
            index = i;
            }
        }
        v1.at(index) = 0;
        a.push_back(max);
        max = 0;
    }

    for(int i=0; i<a.size(); i++){
        cout << "max1 " << a[i] <<endl;
    }

    int index2, max2=0;
    vector<int > b;
    for( int j=0; j<3; j++){    
        for(int i=0; i<v2.size(); i++){
        if(v2[i]>max2){
            max2 = v2[i];
            index2 = i;
            }
        }
        v2.at(index2) = 0;
        b.push_back(max2);
        max2 = 0;
    }

    for(int i=0; i<b.size(); i++){
        cout << "max2 " << b[i] <<endl;
    }


}