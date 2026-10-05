
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for(int left=0;left<numsSize-1;left++) 
    {
        int right=numsSize-1; 
        while(left<right) 
        {
            int current_sum=nums[left]+nums[right];
            if(current_sum==target)
            {
                int* result=(int*)malloc(2*sizeof(int));
                result[0]=left; 
                result[1]=right; 
                *returnSize=2; 
                return result;
            }
            right--; 
        }
    } 
    *returnSize=0;
    return NULL;
}