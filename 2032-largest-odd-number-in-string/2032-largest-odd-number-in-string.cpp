class Solution {
public:
    string largestOddNumber(string num) {
        int maxi = INT_MIN;
        string sub;
        for(int i = num.size() - 1 ; i >= 0 ; i--){

            int number = num[i] - '0';
            if(number %2 != 0){
                sub = num.substr(0,i+1);
                break;
            }

        }

        if(sub.size() == 0) return "";
        else return sub;
    }
};