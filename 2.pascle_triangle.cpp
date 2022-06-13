class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> res;
    vector<int> copy;
    for(int i=0;i<n;i++)
    {
        vector<int> rowi;
        for(int j=0;j<=i;j++)
        {
            if(j==0 ||j==i)
                rowi.push_back(1);
            else
                rowi.push_back(copy[j]+copy[j-1]);
        }
        copy=rowi;
        res.push_back(rowi);
    }
    return res;
    }
};
