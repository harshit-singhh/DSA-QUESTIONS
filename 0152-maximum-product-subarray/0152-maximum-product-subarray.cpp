class Solution {
public:
    int maxProduct(vector<int>& arr) {
			int n = arr.size();
      long long prefix = 1;
	    long long suffix = 1;
	    long long ans = INT_MIN;
	   
	    for(int i = 0 ; i< n ; i++){
	       if(prefix == 0) prefix = 1;
	       if(suffix == 0) suffix = 1;
	       
	       prefix = prefix*arr[i];
	       suffix = suffix*arr[n-i-1];
	       
	       ans = max(ans,max(prefix,suffix));
	    }
	   
	   return ans;
    }
};