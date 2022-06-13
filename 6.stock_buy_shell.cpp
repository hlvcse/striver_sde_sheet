class Solution {
public:
    int maxProfit(vector<int>& prices) {
   // Write your code here.
    int profit=0,smallest=prices[0];
    int n=prices.size();
    for(int i=1;i<n;i++)
    {
         smallest=min(smallest,prices[i]);
         profit=max(profit,prices[i]-smallest);
    }
    return profit;
    }
};
