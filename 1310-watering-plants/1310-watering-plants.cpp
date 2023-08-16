class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        
        int steps = 0;

        int cap = capacity;

        int index = 0;
        int n = plants.size();
        while(index < n){
            if(cap - plants[index] >= 0){
                cap -= plants[index];
                steps++; 
                index++;       
            }
            else if(cap - plants[index] < 0){
                steps += (index*2)+1;
                cap = capacity;
                cap -= plants[index];
                index++;
            }

          
        }
        return steps;
    }
};