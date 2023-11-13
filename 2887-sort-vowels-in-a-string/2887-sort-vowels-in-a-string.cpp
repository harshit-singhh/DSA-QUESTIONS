class Solution {
public:
    string sortVowels(string s) {
        
        priority_queue<pair<int,char>,vector<pair<int ,char>>,greater<pair<int,char>>>p;
        
        unordered_set<char>st;
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        
        for(int i = 0 ; i < s.size() ; i++){
            if(st.find(s[i]) != st.end()){
                char ch = s[i];
                int ascii = int(ch);
                p.push({ascii,ch});
            }
        }
        
        for(int i = 0 ; i< s.size() ; i++){
            if(st.find(s[i]) != st.end()){
                s[i] = p.top().second;
                p.pop();
            }
        }
        
        return s;
        
        
        
    }
};