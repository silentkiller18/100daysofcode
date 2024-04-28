class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int count=0;
        for(char c:s)
        {
            if(c==' ' && count==0)
            {
                continue;
            }
            else if(c==' ' && count>0)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};