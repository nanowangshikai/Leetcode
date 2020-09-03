#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:

         int partition(vector<int> &nums, int low, int high){
             int pivot = nums[high];
             int i = low-1;

            for(int j=low; j<high;j++){
                if(nums[j] <= pivot){
                    i++;
                    swap(nums[i],nums[j]);
                }
            }
            swap(nums[high], nums[i+1]);
            return i+1;
        }

        void quickSort(vector<int> &nums, int low, int high){
            if(low < high){
                int pivot = partition(nums, low, high);
                quickSort(nums,low, pivot-1);
                quickSort(nums, pivot+1, high);
            }
        }
};

int main(){
    Solution s;

    vector<int> nums{3,2,10,7,5,3,4,5,1,6};
    int low = 0;
    int high = nums.size()-1;
    s.quickSort(nums, low, high);

    for(int i=0; i<nums.size(); i++){
        cout << " " <<nums[i];
    }

}