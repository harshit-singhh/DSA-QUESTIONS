struct comp{
    bool operator()(const pair<string,int> &a,const pair<string,int> &b)const{
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
};

class FoodRatings {
    unordered_map <string,set<pair<string,int>,comp>> highestR;
    unordered_map <string,pair<string,int>> foodTocuisineRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            highestR[cuisines[i]].insert({foods[i],ratings[i]});
            foodTocuisineRating[foods[i]] = {cuisines[i],ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto tmp = foodTocuisineRating[food]; 
        highestR[tmp.first].erase({food,tmp.second});
        highestR[tmp.first].insert({food,newRating});
        foodTocuisineRating[food] = {tmp.first,newRating};
    }
    
    string highestRated(string cuisine) {
        return highestR[cuisine].begin()->first;
    }
};
/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */