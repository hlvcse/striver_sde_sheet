#include <bits/stdc++.h> 
long long merge(long long *arr,int left,int mid,int right)
{

    long long inv=0;
    long long temp[right-left+1],ind=0;
    int i=left,j=mid+1;
    while(i<=mid && j<=right)
    {
       if(arr[i]<=arr[j])
       {
           temp[ind++]=arr[i++];
       }
       else
       {
           temp[ind++]=arr[j++];
           inv+=(mid-i+1);
       }     
      }
    while(i<=mid)temp[ind++]=arr[i++];
    while(j<=right)temp[ind++]=arr[j++];
    ind=0;
    for(int i=left;i<=right;i++)
        arr[i]=temp[ind++];
    
    return inv;
    
}
long long merge_sort(long long *arr,int left,int right)
{
    if(left==right) return 0;
    if(left<right){
       long long left_in=merge_sort(arr,left,(left+right)/2);
        long long right_in=merge_sort(arr,(left+right)/2+1,right);
        return left_in+right_in+merge(arr,left,(left+right)/2,right);
    }
    
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    //brute-force..TLE.
    /*
    long long count=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
       {
         if(arr[j]<arr[i])
             count++;
       }
    }
    return count;*/
    //method.2 //merge sort O(nlog n)
    long long count=merge_sort(arr,0,n-1);
  
    return count;
}
