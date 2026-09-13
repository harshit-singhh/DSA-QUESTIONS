class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                swap(nums1[i] , nums1[k]);
                i--;
                k--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
                k--;
            }

        }

        while(i >= 0){
            swap(nums1[i] , nums1[k]);
            i--;
            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};