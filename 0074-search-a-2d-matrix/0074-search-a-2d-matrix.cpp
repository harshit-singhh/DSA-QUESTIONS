class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
	        return 0;
	    }
        int N=matrix.size();
        int M = matrix[0].size();
	    int start = 0; 
	    int end = (N*M) - 1;
	    
	    
	    while(start <= end){
	        int mid =start + (end - start ) / 2;
	        int element = matrix[mid/M][mid%M];
	        if(element == target){
	            return 1;
	        }
	        else if(element < target){
	            start = mid + 1;
	        }
	        else {
	            end = mid - 1;
	        }
	    }
	    
	    return 0;
    }
};