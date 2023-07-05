class Solution {
public:
    int majorityElement(vector<int>& a) {
        // better
        
        // int threshhold = size/2 +1;
        // unordered_map<int,int>m;
        
        // for(int i = 0 ; i < size ; i++){
        //     m[a[i]]++;
        // }
        // for(int i = 0 ; i < size ; i++){
        //     if(m[a[i]] >= threshhold){
        //         return a[i];
        //     }
        // }
        // return -1;

        int size = a.size();
        
        int count = 0;
        int element;
        
        for(int i = 0 ; i < size; i++){
            if(count == 0){
                count =1;
                element = a[i];
            }
            else if(a[i] == element){
                count ++;
                
            }
            else{
                count--;
            }
        }
        
        int elecnt=0;
        for(int i = 0 ; i < size ; i++){
            if(a[i] == element){
                elecnt++;
            }
            
        }
        if(elecnt > size/2 ){
            return element;
        }
        return -1;

    }
};