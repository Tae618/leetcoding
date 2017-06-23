class Solution {
private:
    vector<string> SplitString(const std::string& s, const std::string& c)
    {
        vector<string> v;
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            string temp = s.substr(pos1, pos2-pos1);
            if(temp=="..")
            {
                if(!v.empty())
                    v.pop_back();
            }
            else if(temp!="." && temp.size()>0)
                v.push_back(temp);
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.size())
        {
            string temp = s.substr(pos1);
            if(temp=="..")
            {
                if(!v.empty())
                    v.pop_back();
            }
            else if(temp!="." && temp.size()>0)
                v.push_back(temp); 
        }
        return v;
    }
public:
    string simplifyPath(string path) {
        string res = "";
        vector<string> paths=SplitString(path, "/");
        
        for(int i=0;i<paths.size();i++)
        {   
           // cout<<paths[i]<<endl;
            res += "/"+paths[i];
        }
        //if(path[path.size()]=='\0')  //this test for ending of string at current compiler
            //cout<<"yes"<<endl;
        if(res.size()<1)
            return "/";
        return res;
    }
};
