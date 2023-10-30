
int setBitsfind(int num){

    int count = 0;

    for(int i = 0 ; i < 32 ; i++){
        if((num & (1 << i)) != 0) count++;
    }
    return count;
}

bool comp(int a , int b){
    int setInA = setBitsfind(a);
    int setInB = setBitsfind(b);
    if (setInA < setInB) {
        return true;
    } else if (setInA == setInB) {
        return a < b; // If set counts are equal, compare the values directly
    } else {
        return false;
    }
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin() , arr.end() , comp);
        return arr;
    }
};