class Solution {
//it is a Fabonacci sequence.
public:
    int numDecodings(string s) {
        
        if(s.size()==0)
            return 0;
        if(s[0]=='0')
            return 0;
        int number[s.size()+1];
        number[0]=1;
        number[1]=1;
        //int temp=0;
        for(int i=2;i<=s.size();i++)
        {
            number[i]=0;
            if(s[i-1]!='0')
                number[i] = number[i-1];
            if(s[i-2]!='0')
            {
                int temp=(s[i-2]-'0')*10+(s[i-1]-'0');
                if(temp>0 && temp<=26)
                    number[i]+=number[i-2];
            }
        }
        return number[s.size()];
    }
};
