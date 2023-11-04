class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        

        int rightmini = INT_MAX;

        for(int i = 0 ; i < right.size() ; i++){
            rightmini = min(rightmini , right[i]);
        }

        int leftmaxi = INT_MIN;

        for(int i = 0 ; i < left.size() ; i++){
            leftmaxi = max(leftmaxi , left[i]);
        }

        

        int rightdist = n - rightmini;
        int leftdist = leftmaxi;

        if(rightdist > leftdist) return rightdist;
        else if(leftdist > rightdist) return leftdist;
        return leftdist;
    }
};