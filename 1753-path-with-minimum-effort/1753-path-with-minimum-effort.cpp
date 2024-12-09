class Solution {
public:

    bool ispossible(int newrow , int newcol , int row ,int col){
        if(newrow >= 0 && newrow < row && newcol >= 0 && newcol < col){
            return true;

        }

        return false;
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();

        vector<vector<int>>distance(row , vector<int>(col , INT_MAX));
        priority_queue<pair<int, pair<int,int>> , vector<pair<int, pair<int,int>>> , greater<pair<int,pair<int,int>>>>q;
        q.push({0 , {0 , 0}});

        int dx[] = {-1 , 0 , 1 , 0};
        int dy[] = {0 , -1 , 0 , 1};
        while(!q.empty()){
            auto it =  q.top();
            q.pop();

            int effort = it.first;
            int x = it.second.first;
            int y = it.second.second;

            if(x == row-1 && y == col-1) return effort;

            for(int i = 0 ; i < 4 ; i++){
                int newrow = x + dx[i];
                int newcol = y + dy[i];

                if(ispossible(newrow , newcol , row , col)){
                    int neweffort = max(effort , abs(arr[newrow][newcol] - arr[x][y]));
                    if(neweffort < distance[newrow][newcol]){
                        distance[newrow][newcol] = neweffort;
                        q.push({neweffort, {newrow , newcol}});
                    }
                }
            }
            


        }

        return -1;
    }
};