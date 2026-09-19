class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        stack<char>st;

        st.push(num[0]);

        for(int i = 1; i < n ; i ++){

            while(!st.empty() && num[i] < st.top() && k){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k){
            st.pop();
            k--;
        }

        string ans = "";

        while(!st.empty()){
            char ch = st.top();
            st.pop();
            ans.push_back(ch);
        }

        reverse(ans.begin(), ans.end());

        int first_non_zero_index = -1;

        for(int i = 0 ; i < ans.size() ;i ++){
            if(ans[i] != '0'){
                first_non_zero_index = i;
                break;
            }
        }

        if(first_non_zero_index == -1) return "0";
        int remaining_num = ans.size() - first_non_zero_index;
        ans = ans.substr(first_non_zero_index, remaining_num );
        if(ans.size() == 0 ) return "0";
        return ans;
    }
};