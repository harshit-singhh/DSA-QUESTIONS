class Solution {
    string solve(int n , unordered_map<int , string>&m){
        if(n == 1){
            return "1";
        }

        if(m.find(n) != m.end()){
            return m[n];
        }

        string temp = solve(n - 1,m);
        int index = 0;
        
        string ans = "";
        while(index < temp.size()){
            int count = 0;
            int num = temp[index] - '0';
            while(temp[index] - '0' == num){
                count++;
                index++;
            }
            ans+=to_string(count);
            ans+=to_string(num);

        }
        return m[n] = ans;


    }
public:
    string countAndSay(int n) {
        
        unordered_map<int , string>m;
        string ans = solve(n , m);
        return ans;
        
    }
};