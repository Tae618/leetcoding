class Solution {
/*
0 0 00 000   
  1 01 001
    11 011
    10 010
       110
       111
       101
       100
tips: add one bit, double the array
      add '0' to the array
      add '1' to the reversed array 
*/
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0)
            return res;
        
        int pow=1;
        for(int i=0;i<n;i++)
        {
            for(int j=res.size()-1;j>=0;j--)
            {
                res.push_back(res[j]+pow);
            }
            pow*=2;
        }
        return res;
    }
};
