class OrderedStream {
    int cur;
    int maximum;
    vector<string> v;
public:
    OrderedStream(int n) : cur(1), maximum(n+1), v(n+1, "") {
        
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey] = value;
        vector<string> ans;
        while (cur < maximum && !v[cur].empty()) {
            ans.push_back(v[cur]);
            ++cur;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */