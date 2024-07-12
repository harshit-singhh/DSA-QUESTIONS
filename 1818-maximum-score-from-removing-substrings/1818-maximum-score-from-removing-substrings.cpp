class Solution {
public:
    int maximumGain(string s, int x, int y) {
        
        int n = s.size();
        char first , second;
        if(y >= x){
            first = 'b';
            second = 'a';
        }
        else{
            first = 'a';
            second = 'b';
        }
        stack<char>st;
        int score = 0;
        for(int i = 0 ; i < n ; i++){

            int currChar = s[i];

            if(!st.empty() && st.top() == first && currChar == second){
                score+= max(x , y);
                st.pop();
            }

            else st.push(currChar);
        }

        stack<char>st2;
        string s2;
        while(!st.empty()){
            s2.push_back(st.top());
            st.pop();
        }


        n = s2.size();

        for(int i = 0 ; i < n ; i++){

            int currChar = s2[i];

            if(!st2.empty() && st2.top() == first && currChar == second){
                score+= min(x , y);
                st2.pop();
            }

            else st2.push(currChar);
        }

        return score;


    }
};