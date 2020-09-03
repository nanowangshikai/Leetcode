#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target){
        int *twovalue;
        //initial memory allcoation
        twovalue = (int*)malloc(2*sizeof(twovalue));    
    
        for(int i=0; i<numsSize-1 ; i++){
            for(int j=1; j<numsSize; j++){
                if((nums[i] + nums[j]) == target){
                    twovalue[0] = i;
                    twovalue[1] = j;

                }
                
            }
        }

       
    return twovalue;

}

int main(int argc, char** argv){
    int nums[4] = {11,15,2,7};
    int target = 9;
    int *final;
    final = twoSum(nums, 4, 9);

    for(int i=0; i<2; i++){
        printf("the final array is %d \n", final[i]);
    }
    

}