class Cashier {
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) 
        : count(1), n(n), discount(discount) {
        for (int i = 0; i < prices.size(); ++i) {
            productToPrice[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0;
        for (int i = 0; i < amount.size(); ++i) {
            ans += productToPrice[product[i]] * amount[i];
        }
        if (count == n) {
            count = 1;
            return ans * ((double) (100 - discount) / 100);
        } else {
            ++count;
            return ans;
        }
    }
private:
    int count;
    int n;
    int discount;
    unordered_map<int,int> productToPrice;
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */