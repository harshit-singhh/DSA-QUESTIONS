class LRUCache {
public:
     int n;
        list <pair<int,int>> l;
        unordered_map <int,list<pair<int,int>>::iterator> m;
        LRUCache(int capacity){
            n = capacity;
        }
        int get(int key){
            auto f = m.find(key);
            if(f == m.end()) return -1;
            l.splice(l.begin(),l,f->second);
            return f->second->second;
        }
        void put(int key, int value){
            auto f = m.find(key);
            if(f != m.end()){
            l.splice(l.begin(),l,f->second);
                f->second->second = value;
                return;
            }
            if(m.size() == n){
                m.erase(l.back().first);
                l.pop_back();
            }
            l.emplace_front(key,value);
            m[key] = l.begin();
        }

};