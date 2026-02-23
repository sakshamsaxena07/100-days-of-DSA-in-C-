void moveZeroes(int* nums, int n) {
    int k=0;

    for(int i=0;i<n;i++){
        if(nums[i]!=0)
            nums[k++]=nums[i];
    }

    while(k<n)
        nums[k++]=0;
}
