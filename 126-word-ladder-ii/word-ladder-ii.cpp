class Solution {
public:
    // TC -- Can not be determined it depends on example to example.
    // Below is the striver explanation.
    void dfs(string word , vector<string> &sq , vector<vector<string>> &ans , string beginWord , int n , unordered_map<string , int> &mp){
        // Base case
        if(word == beginWord){
            reverse(sq.begin() , sq.end());
            ans.push_back(sq);
            reverse(sq.begin() , sq.end());
            return;
        }

        int steps = mp[word];

        for(int i = 0; i < n; i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                // If this transfomed word is present in the map also it should be in the different level then only we will add it in the sequence.
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps){
                    sq.push_back(word);
                    dfs(word , sq , ans , beginWord , n , mp);
                    sq.pop_back();
                }
            }
            word[i] = original;
        }
        
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        int n = beginWord.size();
        unordered_set<string> st(wordList.begin() , wordList.end());
        unordered_map<string , int> mp;
        mp[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front();
            int steps = mp[word];
            q.pop();

            // Means our map is ready jo begin word se end work tak ke transformations strings ko hold karke betha hai with their sequence length , Now its time to backtrack.
            if(word == endWord){
                break;
            }

            for(int i = 0; i < n; i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // Means yeh transfomed word hamare wordlist mai present hai .
                    if(st.find(word) != st.end()){
                        q.push(word);
                        mp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        // Agar end word part hai map ka it means begin se end jaana possible hai to we will backtrack otherwise hum null return kardenge.
        if(mp.find(endWord) != mp.end()){
            vector<string> sq;
            sq.push_back(endWord);
            dfs(endWord , sq , ans , beginWord , n , mp);
        }

        return ans;
    }
};