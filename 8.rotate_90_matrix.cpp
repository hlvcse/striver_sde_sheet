class Solution {
public:
    void swap(int &a,int &b)
    {
        /*
        int temp=a;
        a=b;
        b=temp;
        */
        a=a+b;
        b=a-b;
        a=a-b;
    }
    void rotate(vector<vector<int>>& matrix) {
        //transpose of matrix then reverse each row of transposed matrix
        //transpose
        int n=matrix[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        //reverse
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
};
