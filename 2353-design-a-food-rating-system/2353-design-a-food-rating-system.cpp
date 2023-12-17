// https://stackoverflow.com/questions/2620862/using-custom-stdset-comparator
struct comp {
    bool operator() (const pair<int, string>& a, const pair<int, string>& b) const {
        // return lexicographically smallest for same rating
        if (a.first == b.first) return a.second < b.second;
        return a > b; 
    }
};

// https://leetcode.com/problems/design-a-food-rating-system/discuss/2324669/Three-Maps
class FoodRatings {
    unordered_map<string, set<pair<int, string>, comp>> cuisineToFoods;
    unordered_map<string, int> foodToRating;
    unordered_map<string, string> foodToCuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToFoods[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }
    
    // also possible to just soft delete here, remove entries when searching inside highestRated
    void changeRating(string food, int newRating) {
        // remove the old pair in the map, then insert the new pair
        string cuisine = foodToCuisine[food];
        auto itr = cuisineToFoods[cuisine].find(make_pair(foodToRating[food], food));
        cuisineToFoods[cuisine].erase(itr);
        foodToRating[food] = newRating;
        cuisineToFoods[cuisine].emplace(newRating, food);
    }
    
    string highestRated(string cuisine) {
        return cuisineToFoods[cuisine].begin()->second;
    }
};
//[[["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"], 
// ["korean", "japanese", "japanese", "greek", "japanese", "korean"], 
// [9, 12, 8, 15, 14, 7]],
// ["korean"], ["japanese"], ["sushi", 16], ["japanese"], ["ramen", 16], ["japanese"]]

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */