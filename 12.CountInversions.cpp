long long merge(long long nums[],int low,int mid,int high)
    {
        long long inv=0,j=mid+1,i=low;
        //count inversions.
        for(;i<=mid;i++){
            while(j<=high && nums[i] >  nums[j]){
                j++;
            }
            inv+=j-(mid+1);
        }
            
        //merging..
        i=low,j=mid+1;
        int t[high-low+1],ind=0;//temporary array
        while(i<=mid && j<= high){
            if(nums[i]<=nums[j]){
                t[ind++]=nums[i++];
            }
            else{
                t[ind++]=nums[j++];
            }
        }
        while(i<=mid){
                t[ind++]=nums[i++];
            }
        while(j<=high){
                t[ind++]=nums[j++];
            }
        ind=0;
        for(int i=low;i<=high;i++)
            nums[i]=t[ind++];
        return inv;

    }
long long mergeSort(long long nums[],int low,int high)
 {
        if(low==high)return 0;
        int mid=(low+high)/2;
        long long left=mergeSort(nums,low,mid);
        long long right=mergeSort(nums,mid+1,high);
        return left + right + merge(nums,low,mid,high);
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}
