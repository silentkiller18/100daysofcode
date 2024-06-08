class Solution {
public:
    int singleNumber(vector<int>& v) 
    {
        map<int,int>mp;// In order to be able to store all numbers according Constraints
        for(auto&it:v)
             mp[it]++;

        for(auto&it:mp)
        {
            if(it.second == 1)
            {
                return it.first;
            }
        }
       // This case is impossible to happen, 
       // but should put it for completeness(according to oop concept).
        return 0;

    }
};