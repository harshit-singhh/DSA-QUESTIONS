class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>p;
        int row = heights.size();
        int col = heights[0].size();
        
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        
        dist[0][0] = 0;
        p.push({0,{0,0}});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};
        
        
        while(!p.empty()){
            int currEffort = p.top().first;
            int currRow = p.top().second.first;
            int currCol = p.top().second.second;
            p.pop();
            
            if(currRow == row-1 && currCol == col-1) return currEffort;
            for(int i = 0; i< 4 ; i++){
                int newrow = currRow + drow[i];
                int newcol = currCol + dcol[i];
                
                if(newrow >= 0 && newrow < row && newcol >= 0 && newcol < col){
                    int newEffort = max(abs(heights[newrow][newcol] - heights[currRow][currCol]), currEffort);
                    if(newEffort < dist[newrow][newcol]){
                        dist[newrow][newcol] = newEffort;
                        p.push({newEffort,{newrow,newcol}});
                    }
                    
                }
            }
           
        }
        return 0; // not rechable
    }
};