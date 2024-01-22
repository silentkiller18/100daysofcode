
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> currCombination;
    
    vector<vector<int>> combinationSum3(int k, int n) {
        makeCombination(k,n,1);
        return ans;
    }
    void makeCombination(int k,int n,int start){
        if(k==0 && n==0)
        {
            ans.push_back(currCombination);
            return;
        }
        for(int i = start;i<10;++i)
        {
            currCombination.push_back(i);
            makeCombination(k-1,n-i,i+1);
            currCombination.pop_back();
        }
    }
};
