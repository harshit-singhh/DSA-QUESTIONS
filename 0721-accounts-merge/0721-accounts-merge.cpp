#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    private:
    vector<int>size, parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,0); // if 1 based indexing is happening// at the start , rank will be 0
        parent.resize(n+1); // if 1 based.. .. same

        for(int i = 0 ; i <= n ; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]); // sabka parent top element ban jaega ye karne se
    }

    void unionBySize(int u, int v){
        int U_topParent = findParent(u);
        int V_topParent = findParent(v);

        if(U_topParent == V_topParent) return; // because dono ka parent same he so both belong to the same 
        // component

        if(size[U_topParent] > size[V_topParent]){
            parent[V_topParent] = U_topParent; 
            size[U_topParent] += size[V_topParent];
        }
        else if(size[U_topParent] < size[V_topParent]){ // we can even skip the else if statement
            parent[U_topParent] = V_topParent;              //because else wale <= me same kaam hi ho rha he. so bas else wale se kaam chal jaega
            size[V_topParent] += size[U_topParent];

        }

        else { 
            parent[U_topParent] = V_topParent;
            size[V_topParent] += size[U_topParent];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
        int n = accounts.size();
        DisjointSet ds(n);

        for(int i = 0 ; i < n ; i++){
            for(int j = 1 ; j < accounts[i].size(); j++){
                
                string mail = accounts[i][j];
                if(m.find(mail) == m.end()){
                    m[mail] = i;
                }
                else{
                    ds.unionBySize(i,m[mail]);
                }
            }
        }

        vector<string>mergeMail[n];
        
        for(auto it: m){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0 ; i < n ; i++){
            if(mergeMail[i].size() == 0) continue;

            sort(mergeMail[i].begin(),mergeMail[i].end());
            string name = accounts[i][0];
            vector<string>temp;
            temp.push_back(name);
            for(auto it : mergeMail[i] ){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;


    }
};