class Solution {
private:
    void searchCNK(vector<int> nums, vector<int> cur, int k,int depth, vector<vector<int>> &res)
    {
        if(cur.size()==depth)
        {   
            res.push_back(cur);
            return;
        }
        if(k==nums.size())
            return;
        for(int i=k;i<nums.size();i++)
        {
           
            cur.push_back(nums[i]);
            searchCNK(nums, cur, i+1, depth, res);
            cur.pop_back();
            while(i+1<nums.size() && nums[i]==nums[i+1])
                i++;
        }
        //return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;
       
        res.push_back(temp);
        
        for(int i=1;i<=nums.size();i++)
        {
            searchCNK(nums, temp, 0,i,res);
        }
        return res;
    }
};
