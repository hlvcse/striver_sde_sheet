class Solution {
public:
    void nextPermutation(vector<int>& permutation) {
    
    //bad method
    /*
    int n=permutation.size();
    bool next_not_exist=true;
    for(int i=1;i<n;i++)
    {
        if(permutation[i]>permutation[i-1])
        {
            next_not_exist=false;
            break;
        }
    }    
    if(next_not_exist==true)

        sort(permutation.begin(),permutation.end());
    else
        next_permutation(permutation.begin(),permutation.end());
       
      */
    //using STL
    /*
     bool check=next_permutation(permutation.begin(),permutation.end());
     if(check==false)
         sort(permutation.begin(),permutation.end());
       */
        
        //permutation logic.
         int n=permutation.size();
        //step1. find first decreasing from last
        int first_decreasing=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(permutation[i]<permutation[i+1])
            {
               first_decreasing=i;
                break;
            }
        }
        if(first_decreasing>=0)//otherwise already at last permutation
        {
            //step2. just greater than first increasing
        int just_greater;
        for(int i=n-1;i>=first_decreasing;i--)
        {
            if(permutation[i]>permutation[first_decreasing])
            {
               just_greater=i;
                break;
            }
        }
        //step3. swap(first_decreasing,just greater)
        int temp=permutation[first_decreasing];
        permutation[first_decreasing]=permutation[just_greater];
        permutation[just_greater]=temp;
        //step 4. reverse i+1 to n-1
        reverse(&permutation[first_decreasing+1],&permutation[n]);
        }
        else
            sort(permutation.begin(),permutation.end());
        
    }
};
