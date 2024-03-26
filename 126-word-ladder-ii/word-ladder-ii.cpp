class Solution {
    unordered_map<string, int>map;
    vector<vector<string>> ans;
    string b;
    
    void dfs(string word, vector<string> &seq)
    {
        if(word==b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        
        int steps=map[word];
        int size=word.size();
        for(int i=0; i<size; i++)
            {
                char original=word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(map.find(word)!=map.end() && map[word]+1==steps)
                    {
                        seq.push_back(word);
                        dfs(word, seq);
                        seq.pop_back();
                    }
                }
                word[i]=original;
            }
        
    }
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b=beginWord;
        unordered_set<string>set(wordList.begin(), wordList.end());
        queue<string>q;
        q.push({beginWord});
        map[beginWord]=1;
        int size=beginWord.size();
        set.erase(beginWord);
        
        while(!q.empty())
        {
            string word=q.front();
            int steps=map[word];
            q.pop();
            if(word==endWord) break;
            for(int i=0; i<size; i++)
            {
                char original=word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i]=c;
                    if(set.count(word))
                    {
                        q.push({word});
                        set.erase(word);
                        map[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }
        if(map.find(endWord)!=map.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};