class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++){
            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]){
                    st.pop();
                }

                if(!st.empty() && st.top() == -asteroids[i]){
                    st.pop();
                } else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> ans(st.size(), 0);
        for(int i = ans.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
