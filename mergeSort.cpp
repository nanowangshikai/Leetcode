#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:

        void merge(vector<int> &nums, int low, int medium,  int high){
            int n1=medium-low+1, n2=high-medium;
            vector<int> Left, right;
            for(int i=0; i<n1; i++){
                Left[i] = nums[low+i];
            }
            for(int j=0; j<n2; j++){
                right[j] = nums[medium+1+j];
            }

            int i=0, j=0, k=low;
            while(i<n1 && j<n2){
                if(Left[i] <=right[j]) {nums[k] = Left[i]; i++;
            }else{
                nums[k] = right[j]; j++;
            }
            k++;
            }
            while(i<n1){
                nums[k] = Left[i];
                i++; 
                k++;
            }
            while(j<n2){
                nums[k] = right[j];
                j++; 
                k++;
            }
        }

        void mergeSort(vector<int> &nums, int low, int high){
            if(low < high){
                int q = (low+high) / 2;
                mergeSort(nums, low, q);
                mergeSort(nums, q+1, high);

                merge(nums, low, q, high);
            }
        }
};

int main(){
    Solution s;

    vector<int> nums{3,2,10,7,5,3,4,5,1,6};
    int low = 0;
    int high = nums.size();
    s.mergeSort(nums, low, high);

    for(int i=0; i<nums.size(); i++){
        cout << " " <<nums[i];
    }

}