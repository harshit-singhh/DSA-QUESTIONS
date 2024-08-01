class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int n = details.size();
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            string ans = details[i].substr(11 , 2);
            cout<<ans<<endl;
            int age = stoi(ans);
            if(age > 60) count++;
        }

        return count;
    }
};