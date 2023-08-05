class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int,int>m;

         stack<int>st;

         int index = nums2.size() -1;

         while(index >= 0){
             while(!st.empty() && nums2[index] > st.top()){
                 st.pop();
             }
             if(!st.empty()){
                 m[nums2[index]] = st.top();
                 st.push(nums2[index]);
             }
             else if(st.empty()){
                 m[nums2[index]] = -1;
                 st.push(nums2[index]);
             }
             index--;
         }

         vector<int>ans;

         for(int i = 0 ; i< nums1.size() ; i++){
             ans.push_back(m[nums1[i]]);
         }

         return ans;
    }
};