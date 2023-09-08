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

    int findNumberOfComponents(){
        int count = 0;
        int n = parent.size();
        for(int i = 0 ; i < n ; i++){
            if(parent[i] == i && size[i] > 1) count++;
        }
        return count;
    }

};

class Solution {
  public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        int maxrow = 0 , maxcol = 0;
        
        for(auto it : stones){
            maxrow = max(maxrow , it[0]);
            maxcol = max(maxcol , it[1]);
            
        }
        
        DisjointSet ds(maxrow + maxcol + 2);// for 1 based indexing , just for safety measures
        
        unordered_map<int,int>stoneNodes;
        
        for(auto it : stones){
            int row = it[0];
            // important
            int col = it[1] + maxrow + 1;
            ds.unionBySize(row, col);
            stoneNodes[row] = 1;
            stoneNodes[col] = 1;
        }
        
        // number of componenets
        // int count = 0;
        // for(auto it : stoneNodes){
        //     if(ds.findParent(it.first) == it.first){
        //         count++;
        //     }
        // }

        // or to find components we can do this 

        int count = ds.findNumberOfComponents();
        
        
        //see the small derivation from striver channel
        return n - count ;
        
        
        
    }
};