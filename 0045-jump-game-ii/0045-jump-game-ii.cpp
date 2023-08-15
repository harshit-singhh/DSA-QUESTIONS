class Solution {
public:
    int jump(vector<int>& nums) {
        int furthest = 0;
        int current = 0;
        int jumps = 0;

        for(int i = 0 ; i < nums.size() -1 ; i++){
            furthest = max(furthest , i + nums[i]);

            if(i == current){
                current = furthest;
                jumps++;
            }
        }
        return jumps;
    }
};