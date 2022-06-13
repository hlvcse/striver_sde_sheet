class Solution {
public:
    void nextPermutation(vector<int>& permutation) {
        /*bool next_not_exist=true;
    for(int i=1;i<n;i++)
    {
        if(permutation[i]>permutation[i-1])
        {
            next_not_exist=false;
            break;
        }
    }    
    if(next_not_exist==true)
    {
        sort(permutation.begin(),permutation.end());
        return permutation;
    }
    else{
            next_permutation(permutation.begin(),permutation.end());
        return permutation;
      }*/
    //method1.
        /*
        bool check_exist=next_permutation(permutation.begin(),permutation.end());
    if(check_exist==true)
       {
           for(auto it: permutation)
            cout<<it<<" ";
       }
    else{
        sort(permutation.begin(),permutation.end());
        for(auto it: permutation)
            cout<<it<<" ";
    }
    */
        int n=permutation.size();
        //step1. finding first decresaing element 
        int i=n-2;
        while(i>=0)
        {
            if(permutation[i]<permutation[i+1])
            {
                break;
            }
            i--;
        }
        if(i>=0){//not last permutation
            
            //step2. first element just bigger than permutation[i]
        int j=n-1;//come in reverse direction to find just begger than arr[i]
        while(j>i)
        {
            if(permutation[j]>permutation[i])
            {
                break;
            }
            j--;
        }
        //j--;//come back to just greater element of i
        //step3. swap(permutation[i],permutation[j])
        int temp=permutation[i];
        permutation[i]=permutation[j];
        permutation[j]=temp;
        //step4. reverse element i+1 to n
        //reverse(&permutation[i+1],&permutation[n-1]);//...won't work in vector..must be iterator in argument
        int start=i+1, last=n-1;
        while (start<last) {
            int temp=permutation[start];
        permutation[start]=permutation[last];
        permutation[last]=temp;;
            start++;
            last--;
        }
        
      }
    else{//last permutation
            sort(permutation.begin(),permutation.end());
        }
        
    }
};
