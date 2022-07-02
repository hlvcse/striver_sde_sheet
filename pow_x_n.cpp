class Solution {
public:
    double myPow(double x, int n) {
        //method 1.
       //return pow(x,n);
        //method2. O(logn)..iterative

        double ans=1;
        long nn=n;
        if(nn<0)nn=-1*nn;
        while(nn>=1)
        {
            if(nn%2==1){
                ans=ans*x;
                nn=nn-1;
            }
            else{
            x=x*x;
            nn=nn/2;
            }
        }
        if(n<0)return 1.0/ans;
        return ans;
        
        }
};
