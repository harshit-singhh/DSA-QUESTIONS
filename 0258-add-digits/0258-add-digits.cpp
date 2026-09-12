class Solution {
public:
    int sizeofnum(int num){
        string str = to_string(num);
        return str.size();
    }
    int addDigits(int num) {
        
        int sum = 0;
        int size = 0;
        while(num){
            int to_add = num%10;
            sum+=to_add;
            num = num/10;
            size++;
        }
        if ( sizeofnum(sum) >= 2 ){

            return addDigits(sum); 
        }

        return sum;
        
    }
};