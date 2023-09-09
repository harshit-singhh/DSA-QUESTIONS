class Solution {
    private:
    double solve(int N , int k , int currRow , int currCol, map<pair<int , pair<int,int>> , double>&mp){
        if(currRow < 0 || currRow >= N || currCol < 0 || currCol >= N) return 0;
        if(k == 0) return 1;

        if(mp.find({k , {currRow , currCol}}) != mp.end()) return mp[{k , {currRow , currCol}}]; 
        double result = 0;
        int drow[] = {-2 , -2 , -1 , 1 , 2 , 2 , 1 , -1};
        int dcol[] = {1 , -1 , -2 , -2 , -1 , 1 , 2 , 2};

        for(int i = 0 ; i< 8 ; i++){
            result += solve(N , k-1 , currRow + drow[i] , currCol + dcol[i], mp);
        }

        return mp[{k , {currRow , currCol}}] = result/8.0;
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        
        map<pair<int , pair<int,int>> , double>mp;
        return solve(n , k , row , column , mp);
    }
};