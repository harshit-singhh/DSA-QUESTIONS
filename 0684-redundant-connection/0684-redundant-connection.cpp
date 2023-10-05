
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
        int parentt = findParent(parent[node]); 
        return parentt; // sabka parent top element ban jaega ye karne se
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        DisjointSet ds(n+1);


        vector<int>ans;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];

            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionBySize(u , v);
            }
            else if(ds.findParent(u) == ds.findParent(v)){
                ans = {u,v};
                ds.unionBySize(u , v);
            }
        }
        return ans;
    }
};