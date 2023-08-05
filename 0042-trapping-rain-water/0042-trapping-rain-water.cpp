class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> premax(n),suffixmax(n);
        // Computing prefixmax for each element in height array
        premax[0]=height[0];
        for(int i=1;i<height.size();i++)
            premax[i] = max(height[i],premax[i-1]);
        // Computing suffixmax for each element in height array
        suffixmax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
           suffixmax[i] = max(height[i],suffixmax[i+1]);
        // computing the water trapped using the below formula
        int water = 0;
        for(int i=0;i<n;i++)
        {
            water += (min(premax[i],suffixmax[i])-height[i]);
        }
        return water;
    }
};