class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        int curr = 0;

        for(int i = 0 ; i <  n; i++){
            string str = logs[i];
            int size = str.size();
            if(size >= 2){
                if(size == 3 && str[0] == '.'){
                    if(curr > 0) curr --;
                }
                else if(str[0] != '.' ) curr++;
            } 
        }

        return abs(curr);
    }
};