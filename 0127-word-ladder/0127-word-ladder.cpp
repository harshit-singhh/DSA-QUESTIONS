class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin() , wordList.end());
        queue<pair<string , int>>q; // word , count;
        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int count = q.front().second;
            q.pop();

            if(word == endWord) return count;

            for(int i = 0 ; i < word.size() ; i++){
                char originalChar = word[i];

                for(char ch = 'a'; ch <= 'z' ; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word , count+1});
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }

        return 0;
    }
};