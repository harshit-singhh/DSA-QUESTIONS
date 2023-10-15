#define mod 12345

class Solution {

public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<int>prefix(n*m , 1);
        vector<int>suffix(n*m , 1);
        int valpre = 1;
        int valsuf = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                valpre = ((valpre%mod)*(grid[i][j]%mod))%mod;
               
                prefix[m*i + j] = valpre;
            }
        }

        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = m-1 ; j>= 0 ; j--){
                valsuf = ((valsuf%mod)*(grid[i][j]%mod))%mod;

                suffix[m*i+j] = valsuf;
            }
        }


        vector<vector<int>>ans(n , vector<int>(m));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int preval = i*m + j - 1;
                int sufval = i*m + j + 1;

                if(preval >= 0 && sufval < n*m){
                    ans[i][j] = ((prefix[preval]%mod) * (suffix[sufval]%mod))%mod;
                }

                else if(sufval >= n*m){
                    ans[i][j] = prefix[preval];
                }

                else if(preval < 0){
                    ans[i][j] = suffix[sufval];
                }
            }

        }

        return ans;
    }
};