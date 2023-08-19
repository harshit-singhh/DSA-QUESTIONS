bool sort_by_sec(const vector<int> &a,const vector<int>&b){
        return a[2]<b[2];
}
class Solution {
public:
    int find_parent(int u,vector<int> &parent){
        if(u==parent[u]) return u;
        return find_parent(parent[u],parent);
    }
    void union1(int u,int v,vector<int>&parent){
        int pu=find_parent(u,parent);
        int pv=find_parent(v,parent);
        if(pu!=pv){
              parent[pu]=pv;
        }
    }
   
    int MST(vector<vector<int>> &edges,int n,vector<int>&include,vector<int>&exclude){
        vector<int>parent(n);
        int calc_edes=0;
        for(int i=0;i<n;i++) parent[i]=i;
            int cost=0;
            if(include.size()!=0){
                int pu=find_parent(include[0],parent);
                int pv=find_parent(include[1],parent);
                union1(pu,pv,parent);
                cost+=include[2];
                calc_edes+=1;
            }
             for(auto it:edges){
                if(include.size()!=0 && it==include) continue;
                if(exclude.size()!=0 && it==exclude) continue;
                 int pu=find_parent(it[0],parent);
                int pv=find_parent(it[1],parent);
                if(pu!=pv){
                union1(pu,pv,parent);
                cost+=it[2];
                calc_edes+=1;
                }
             }
             return calc_edes==n-1 ? cost:INT_MAX;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {   
        
        
        vector<vector<int>> originalEdges;
        for(auto edge : edges) {
            vector<int> originalEdge{edge[0], edge[1], edge[2]};
            originalEdges.push_back(originalEdge);
        }
        sort(edges.begin(),edges.end(),sort_by_sec);
        vector<vector<int>> ans;
        vector<int> temp;
        int mst=MST(edges,n,temp,temp);
        // cout<<mst<<endl;
        // int c=0;
        vector<int> critical;
        vector<int> pseudpcritical;
        for(int edge=0;edge<edges.size();edge++){
            int exclude_cost=MST(edges,n,temp,originalEdges[edge]);
            int include_cost=MST(edges,n,originalEdges[edge],temp);
            if(exclude_cost>mst){
                critical.push_back(edge);
            }
            else if(include_cost==mst){
                pseudpcritical.push_back(edge);
            }
        }
        ans.push_back(critical);
        ans.push_back(pseudpcritical);
        return ans;
        
    }
};