#include <iostream>

#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;


int main(){

    vector<int> nums1 = {1,4};
    vector<int> nums2 = {2,3,6};

    vector<int> nums3(0);

    // cout << nums3.size() ;
    while( !nums1.empty() && !nums2.empty() ){
        
        if(nums1[0]<nums2[0]){
            nums3.push_back(nums1[0]);
            nums1.erase(nums1.begin());
        }else{
            nums3.push_back(nums2[0]);
            nums2.erase(nums2.begin());
        }

        cout << "num 1 size is -->" <<nums1.size() << "\n";

        cout << "num 2 size is -->" <<nums2.size() << "\n";

    }

    while(!nums2.empty()){
        nums3.push_back(nums2[0]);
        nums2.erase(nums2.begin());
    }

    while(!nums1.empty()){
        nums3.push_back(nums1[0]);
        nums1.erase(nums1.begin());
    }

    // cout << "num3 size -->" << nums3.size() <<"\n";

    for(int i=0; i<nums3.size(); ++i ){
        cout << nums3[i] << "\n";
    }

    double a;
    double b;
    if( (nums3.size() % 2) == 0 ){ //even number
        a = nums3[nums3.size() / 2];
        b = nums3[nums3.size() / 2 -1];
        a = (a + b) / 2 ;
    }else{
        a = nums3[nums3.size() / 2]; // odd
    }
 
    // cout << "nums even --> " << nums3[nums3.size() / 2 -1] <<endl;

    // cout << "nums even --> " << nums3[nums3.size() / 2] <<endl;
    
    // cout << "final answer-->" << a <<endl;

    // cout << "(3+2)/2 = " << setiosflags(ios::fixed)<<setprecision(1)<< a << endl;





    return 0;
}
