class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //brute force1. 2loop. for each element search if present in remaining array.=O(n2)
        //method 2.
        //sorting..array got modified/we have to take extra space.=O(nlogn+n)time
        /*
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                return nums[i];
        }*/
        //method 3. extraspace for frequency array.=O(n) time + O(n+1) space
        
        //optimal method. linked list cycle when repeat of element=O(n) time O(1) space
        //assume number are in cycle as duplicate present..don't create linkedlist
        //moving in linked list..find collision
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow != fast);
        //now we are at collision...In cicle created by elements.duplicates must create cycle.
        fast=nums[0];
        while(slow != fast)
        {
            //both are moving one step to stop at duplicates.
            slow=nums[slow];
            fast=nums[fast];
        }
        
        
        return slow;//return fast...both are at duplicate
    }
};
