class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        list<int>dll;
        int n = arr.size();
        
        vector<int>ans;
        
        for(int i = 0 ; i< n ; i++){
            
            if(!dll.empty() && dll.front() == i-k) dll.pop_front(); // jo range se bahar he , usko delete kar diya
            
            while(!dll.empty() && arr[dll.back()] < arr[i]) dll.pop_back(); // jo range ke andar he but, new element se
            // chota he, usko bhi delete kar diya, because wo max hoga hi nhi us range me, to uska kya kaam.
            
            dll.push_back(i); // new element ko add kiya
            
            if(i>=k-1) ans.push_back (arr[dll.front()]); // agar i, k-1 ke barabar pahuch gya he, iska matlab hum apne
            // first subarrya pe khade he, and yha se max nikalna padega. and max hmesha dll.front pe hi milega because 
            // humne esa code kiya he
            
        }
        
        return ans;
    }
}; 