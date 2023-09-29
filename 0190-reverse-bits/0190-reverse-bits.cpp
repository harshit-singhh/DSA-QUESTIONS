class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans = 0;
        for (int i = 0; i <= 31; i++) {
            if ((n >> i) & 1) {
                ans = ans | (1 << (31 - i));
            }
        }
        
        return ans;
    }
};