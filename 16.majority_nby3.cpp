class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //method1.bruteforce..count frequency using 2 loop
        
        //method1.sorting

        //methood 3. map(element ,frequency)
       /* vector<int> res;
        unordered_map<int,int> mp;
        for(auto ele:nums)
        {
            mp[ele]++;
         }
        int ans;
        for(auto it:mp)
        {
           if(it.second>nums.size()/3)
           {

               ans=it.first;
               res.push_back(ans);
           }   
         }
        return res;
         */
        //method optimal...moore vote algo

        int num1=-1,num2=-1,count1=0,count2=0;
        for(auto ele:nums)
        {
            if(ele==num1)count1++;
            else if(ele==num2)count2++;
            else if(count1==0)
            {
                num1=ele;
                count1=1;
            }
                
            else if(count2==0)
            {
                num2=ele;
                count2=1;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        //actual count of num1,num2
        count1 = 0;
        count2 = 0;
      for (auto ele:nums)
      {
        if (ele == num1)
            count1++;
        else if (ele == num2)
            count2++;
       }
       vector<int> res;
      if(count1 >nums.size()/3)
         res.push_back(num1); 
      if (count2>nums.size()/3)
         res.push_back(num2);
       return res; 
    }
};
