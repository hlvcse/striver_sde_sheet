class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
    int largest=arr[0],max_i=arr[0];
    for(int i=1;i<n;i++)
    {
        max_i=max(arr[i],max_i+arr[i]);
        largest=max(max_i,largest);
    }
    return largest;
    }
};
