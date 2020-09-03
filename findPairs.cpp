#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
    public:
        int findPairs(vector<int>& nums, int k ){
            
            set<int> saw;
            set<int> diff;

            for(int i=0; i<nums.size(); ++i ){
                if(saw.find(nums[i]-k) != saw.end()  ){
                    diff.insert(nums[i]-k);
                }
                if(saw.find(nums[i] + k ) != saw.end() ){
                    diff.insert(nums[i] );
                }
                saw.insert(nums[i]);
            }

            

            return diff.size();
        }
};

int main(){


    vector<int> one{3,1,4,1,5};
    vector<int> two{1,3,1,5,4};
    int k=0;

    Solution s;
    int a = s.findPairs(two, k);

    cout << "a is" <<a <<endl;

    

}