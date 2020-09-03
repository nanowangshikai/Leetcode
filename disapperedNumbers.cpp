#include <iostream>
#include <cmath>

#include <vector>
using namespace std;

class Solution{
    public:
        vector<int> findDisappearedNumber(vector<int>& nums){
            
            vector<int> missingNumbers;
            for(int i=0; i<nums.size(); ++i){

                nums[abs(nums[i]) -1] = abs(nums[abs(nums[i]) -1]) * -1;

            }

            for(int i=0; i<nums.size(); ++i){
                if(nums[i]>0){
                    missingNumbers.push_back(i+1);
                }
            }


            vector<int>::iterator i;

            // for(i=missingNumbers.begin(); i!=missingNumbers.end(); i++){
            //     cout << *i << endl ;
            // }

            
            return missingNumbers;
        }
};

int main(){
    Solution s;

    vector<int> list;
    vector<int> result;
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(7);
    list.push_back(8);
    list.push_back(2);
    list.push_back(3);
    list.push_back(1);

    result = s.findDisappearedNumber(list);

    

}