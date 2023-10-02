class Solution {
public:
    bool winnerOfGame(string colors) {
        int a_count = 0 , b_count = 0;

        int n = colors.size();

        int a_make = 0;
        int b_make = 0;
        for(int i = 0 ; i < n ; i++){
            if(colors[i] == 'A'){

                a_count++;
                b_count = 0;
            } 
            else if(colors[i] == 'B'){

                b_count++;
                a_count = 0;
            } 

            if(a_count >= 3){
                a_make++;
            }
            else if(b_count >= 3){
                b_make++;
            }
        }

        if(a_make >= b_make+1) return true;
        return false;
    }
};