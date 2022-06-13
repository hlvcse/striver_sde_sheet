#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    //method 1. store pair of i,j with zero
    vector<pair<int,int>> zeros;
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
                zeros.push_back({i,j});
        }
    }
    for(int i=0;i<zeros.size();i++)
    {
        int x=zeros[i].first;
        int y=zeros[i].second;
        for(int k=0;k<n;k++)
            matrix[k][y]=0;
        for(int k=0;k<m;k++)
            matrix[x][k]=0;
    }
   
}
