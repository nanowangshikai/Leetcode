#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& price){
            
            int maxx = 0;

            for(int i=0; i<price.size(); ++i){
                for(int j=i+1; j<price.size(); ++j){

                    cout << "now max is " << maxx << "\n" ;
                    if(price.at(j) - price.at(i)>maxx){
                        maxx = max(maxx, price.at(j) - price.at(i));
                        
                        cout << "i is " << price.at(i) << " j is "<< price.at(j) <<endl;

                    }

                }
            }



            return maxx;

        }
};

int main(){

    Solution s;
    vector<int> list;
    
    list.push_back(7);
    list.push_back(6);
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);

    
    int a = s.maxProfit(list);
    
    cout << "\n" << "final max profile is ----->" << a << " ";
    
  
    // return 0; 

}
