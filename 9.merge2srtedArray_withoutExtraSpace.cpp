class Solution {
public:
    void swap(int& a,int& b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        //brute-force.
        //using extra space.merging procedure
        //method 1.put smaller element into first and max into second.
        //keep comparing with first element of arr2..all arr1 must be <= arr2 finally
        /*
        //main logic
        for(int i=0;i<m;i++)
        {    
            if(nums1[i]>nums2[0])
            {
                swap(nums1[i],nums2[0]);
                //sort(nums2 arr)   ...more time taking
                //or
                //put new num2[0] in correct place of num2
                int first=nums2[0],ind=1;
                while(ind<n && nums2[ind]<first)
                {
                    nums2[ind-1]=nums2[ind];
                    ind++;
                }
                    nums2[ind-1]=first;            
                
              }
           }
        //copy second array to last of arr1 where 0 is written.
        int ind=0;
        for(int i=m;i<m+n;i++)
            nums1[i]=nums2[ind++];
            */
        
        //method 2.(assuming both arra1 & arr2 elements are in arr1) 
        //gap method..initially gap=ceil((m+n)/2.0)..put two pointer at 0 and gap
        //when ith element< jth element increment both i,j till m+n otherwise swap both ele.
        //keep going till gap>=1.  everytime gapgap/2.
        //step1. copy nums2 in nums1.
        int ind=0;
        for(int i=m;i<m+n;i++)
            nums1[i]=nums2[ind++];
        //main logic
        int gap=ceil((m+n)/2.0);
        while(gap>=1)
        {
            int i=0;
            int j=gap;
            while(j<m+n)
            {
                if(nums1[i]>nums1[j])
                     swap(nums1[i],nums1[j]);
                i++;j++;
             }
            if(gap==1)gap=0;
            else gap=ceil(gap/2.0);
        }
    }
};
