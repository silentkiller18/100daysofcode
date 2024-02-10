class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroid) {
        int n = asteroid.size();
        stack<int> st;
        bool collided = false;

        for(int i=0; i<n; i++){
            if(asteroid[i] > 0){
                st.push(asteroid[i]);
            }
            else{
                collided = false;
                if(st.empty()){
                    st.push(asteroid[i]);
                    continue;
                }
                while(!st.empty() && st.top() > 0){
                    if(st.top() > abs(asteroid[i])){
                        collided = true;
                        break;
                    }
                    else if(st.top() == abs(asteroid[i])){
                        collided = true;
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(collided == false){
                    st.push(asteroid[i]);
                }
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        if(ans.size() == 0){
            return ans;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};