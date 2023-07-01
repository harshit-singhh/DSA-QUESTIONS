class LRUCache {
public:
     list<int>dll; 
        map<int, pair<list<int>::iterator , int>>mp; // ye address ko likhne ka method he, jese inteager ko likhne ka int hota he.
                                                    //list<int>::iterator
        int n;
        LRUCache(int capacity){
            n = capacity;
        }
    
        void makeRecentlyUsed(int key){
            dll.erase(mp[key].first);
             
            dll.push_front(key);
            
            mp[key].first = dll.begin(); // this gives the new address of the first element of the list.
        }
    
        int get(int key){
            if(mp.find(key) == mp.end()) return -1;
        
            makeRecentlyUsed(key); // is function se apni key first pe aa jaegi.
        
            return mp[key].second;
        }
    
        void put(int key,int value){
            
            if(mp.find(key) != mp.end()){
                mp[key].second = value;
                makeRecentlyUsed(key);
            }
            
            else{
                dll.push_front(key);
                mp[key] = {dll.begin(),value};
                n--;
            }
            
            if(n<0){ // mtlb ek element extra daal diya
                int key_in_map = dll.back();
                mp.erase(key_in_map);
                //now delete from list also
                dll.pop_back();
                n++;
            }
        }
};

