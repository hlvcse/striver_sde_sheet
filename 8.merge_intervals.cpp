class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {      
        sort(intervals.begin(),intervals.end());//sort all vectors(intervals) per first element
        vector<vector<int>> result;
        pair<int,int> temp={intervals[0][0],intervals[0][1]};
        
        int n=intervals.size();
        if(n<=1)return intervals;
    
        for(int i=1;i<n;i++)//scan to check merge or not ...for merging(compare with temp)
        {
            if(intervals[i][0]<=temp.second)//merged..update temp second
                temp.second=max(intervals[i][1],temp.second);
            else{//not merged..push temp in res + new temp
              result.push_back({temp.first,temp.second});
              temp={intervals[i][0],intervals[i][1]};
            }
         }
        result.push_back({temp.first,temp.second});//at last push temp in result
        return result;
    }
};
