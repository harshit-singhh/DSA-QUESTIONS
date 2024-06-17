class Solution {
public:
    bool judgeSquareSum(int c) {
        
        int left = 0;
        long long right = sqrt(c);

        while(left <= right){
            int leftsq = left*left;
            long long rightsq = right*right;

            if(leftsq + rightsq == c) return true;
            else if(leftsq + rightsq > c) right--;
            else left++;
        }

        return false;
    }
};