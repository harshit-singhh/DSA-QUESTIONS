class Solution {
public:
    string removeKdigits(string num, int k) {

        if(k > num.size()) return "-1";
        if(k == num.size()) return "0";

        stack<int>st;
        int n = num.size();
        for(int i = 0 ; i <n ;i++ ){
            int number = num[i] - '0';

            while(!st.empty() && number < st.top() && k!=0){
                st.pop();
                k--;
            }
            st.push(number);
        }

        while(k){
            st.pop();
            k--;
        }

        string ans ="";

        while(!st.empty()){

            string str = to_string(st.top());
            ans+= str;
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        int i = 0;
        bool allzero = true;
        for(i  ; i < ans.size() ; i++){
            if(ans[i] != '0'){
                allzero = false;
                break;
            }
        }
        if(allzero) return "0";

        string finalans = ans.substr(i , ans.size() - i);

        return finalans;




    }
};