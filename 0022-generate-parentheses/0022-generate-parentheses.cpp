class Solution {
    void solve(int index , int n , int oc , int cc , string temp , vector<string>&ans){
        if(oc == 0 && cc == 0){
            ans.push_back(temp);
            return;
        }

        if(oc != 0){
            temp.push_back('(');
            solve(index+1 , n , oc-1 , cc , temp , ans);
            temp.pop_back();
        }
        if(cc > oc){
            temp.push_back(')');
            solve(index+1 , n , oc , cc-1 , temp , ans);
            // temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;

        int opencount = n;
        int closecount = n;

        solve(0 , n , opencount , closecount , temp , ans);

        return ans;
    }
};