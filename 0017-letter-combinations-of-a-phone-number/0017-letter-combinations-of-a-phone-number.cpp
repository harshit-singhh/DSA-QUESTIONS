class Solution {
public:

    void help(string digits,int size,vector<string>&ans,string temp,map<int,string> hmap, int ind){

        if(size == 0){
            return;
        }
        if(ind >= size){
            ans.push_back(temp);
            return;
        }

        int number = digits[ind] - '0';
        

        for(char ch:hmap[number]){
            temp.push_back(ch);
            help(digits,size,ans,temp,hmap,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        vector<string>ans;
        string temp;
        map<int,string> hmap;
        hmap[0] = "";
        hmap[1] = "";
        hmap[2] = "abc";
        hmap[3] = "def";
        hmap[4] = "ghi";
        hmap[5] = "jkl";
        hmap[6] = "mno";
        hmap[7] = "pqrs";
        hmap[8] = "tuv";
        hmap[9] = "wxyz";

        int size = digits.size();

        help(digits,size,ans,temp,hmap,0);
        return ans;
        
    }
};