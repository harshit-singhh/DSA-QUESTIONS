class Solution {
    bool isvalid(string s1 , string s2 ,string s3 , string s4){
        if(s1 == ""|| s2 == "" || s3 == "" || s4 == ""){
            return false;
        }
        
        if(s1.size() > 3 || s2.size() > 3 || s3.size() > 3 || s4.size() > 3) return false;
        
        
         int num1 = stoi(s1), num2 = stoi(s2) , num3 = stoi(s3) , num4 = stoi(s4);
        if(num1 >255 || num2 > 255 || num3 > 255 || num4 > 255) return false;
        
        if(to_string(num1).size() != s1.size() || to_string(num2).size() != s2.size() || 
        to_string(num3).size() != s3.size()|| to_string(num4).size() != s4.size()){
            return false;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        int n = s.size();
        for(int i = 1 ; i< n-2 ; i++){
            for(int j = i+1 ; j< n-1 ; j++){
                for(int k = j+1 ; k< n ; k++){
                    string str1 = s.substr(0 , i);
                    string str2 = s.substr(i , j - i);
                    string str3 = s.substr(j , k-j);
                    string str4 = s.substr(k , n-k);
                        
                    if(isvalid(str1 , str2 , str3 , str4)){
                        string finalstring = str1+"."+str2+"."+str3 +"."+str4;
                        ans.push_back({finalstring});
                    }
                    
                }
            }
        }
        if(ans.size() == 0 ) return {};
        return ans;
    }
};