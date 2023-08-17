bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , comp);

        int Units = 0;

        for(int i = 0 ; i < boxTypes.size() ; i++){
            int x = min(boxTypes[i][0] , truckSize);
            
            Units += boxTypes[i][1]*x;
            truckSize = truckSize - x;
            
            if(truckSize == 0) break;
        }

        return Units;
    }
};