class Solution {
public:
    int ways(int i,int j,int m, int n,vector<vector<int>>& dp) {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else return dp[i][j]=ways(i+1,j,m,n,dp)+ways(i,j+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
      //return fact(m-1+n-1)/(fact(m-1)*fact(n-1))==NCr where N=m+n-2,r=m-1 or n-1; 
        //optimal method
        /*int N=m+n-2,r=m-1;long long res=1;
        for(int i =1;i<=r;i++)
        {
            res = res*(N-r+i)/i;
        }
        
        return res;*/
        //mwthod 2. dp ..better approach(O(m*N))
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return ways(0,0,m,n,dp);
    }
};
