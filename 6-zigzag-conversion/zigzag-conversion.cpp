class Solution {
public:
    string convert(string s, int nr) {
        
     if (nr==1)
         return s;
        
        int n=s.size();
        vector<string>rows(nr+1,"");
        bool flag =true;
        int index=0;
        for (int i=0;i<n;i++)
        {
            rows[index].push_back(s[i]);
            if (flag)
                index++;
            else
                index--;
            
            if (index==0)
                flag=true;
            else if (index==nr-1)
                flag=false;
        }
        
        string ans="";
        for (auto v:rows){
            // cout<<v<<endl;
            ans+=v;
        }
            
        
        return ans;
        
        
    }
};