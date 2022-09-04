class FindSumPairs {
    vector<int> n2;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : n2(nums2) {
        for (auto i : nums1) {
            ++mp1[i];
        }
        for (auto i : nums2) {
            ++mp2[i];
        }
    }
    
    void add(int index, int val) {
        --mp2[n2[index]];
        n2[index] += val;
        ++mp2[n2[index]];
    }
    
    int count(int tot) {
        auto ans{0};
        for(auto i : mp1) {
            if (i.first > tot) continue;
            ans += i.second * mp2[tot - i.first];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

// ["FindSumPairs","add","add","add","add","add","add","add","add","add","count","add","count","add","add","add","add","count","add","add","add","add","add","add","add","add","count","add","count","add","add","add","add","add","add","add","count","add","count","count","add","add","add","add","add","add","count","add","count","add","add","add","add","add","add","add","add","add","add","count","add","count","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","add","count","count","add","add","add","add","add","add","add","add","add","add","add","count","add","add","add","add","count","count","add","add","count","add","add","add","count","add","add","add","count","add","add","add","count","add","add","add","add","count","add","add","count","add","add","add","add","add","add","add","add","add","count","add","add","count","add","add","add","add","add","add","add","add","add","count","add","count","count","add","add","add","count","add","add","add","add","add","add","add","add","add","add","add","add","add","add","count","add","add","add","add","add","count","add","add","add","add","add","add","add","count","count","count","add","add","add","add","add","add","add","add","count","add","add","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count","count"]
// [[[31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31],[86,92,86,57,93,50,58,92,47,76,60,92]],[3,29],[6,18],[10,26],[5,36],[8,29],[8,17],[11,1],[5,6],[10,6],[117],[10,1],[124],[5,1],[3,7],[6,10],[6,6],[107],[9,10],[9,6],[9,1],[2,6],[9,6135],[2,1],[6,1],[0,6],[124],[0,1],[6259],[7,1],[7,6135],[1,1],[1,6135],[0,6135],[6,6135],[6,8282],[124],[6,5377],[19918],[19918],[2,6135],[3,6135],[5,6135],[6,9574],[6,1485],[10,6135],[124],[6,863],[6259],[6,6982],[11,6135],[8,6135],[4,6135],[6,5219],[6,416],[6,1416],[6,842],[6,5713],[6,3512],[55940],[6,5090],[6259],[6,2484],[6,9890],[6,3966],[6,4316],[6,8845],[6,2287],[6,6345],[6,4327],[6,7004],[6,377],[6,3172],[6,6816],[6,3936],[6,2741],[6,5624],[6,6088],[6259],[6259],[6,2128],[6,6480],[6,214],[6,3759],[6,3853],[6,8275],[6,4513],[6,3156],[6,89],[6,867],[6,5563],[6259],[6,4563],[6,1461],[6,4386],[6,2953],[191508],[191508],[6,6252],[6,4819],[202579],[6,1262],[6,8619],[6,6046],[6259],[6,3082],[6,9321],[6,8788],[239697],[6,2451],[6,908],[6,5273],[248329],[6,6050],[6,4131],[6,5915],[6,9994],[274419],[6,2655],[6,7766],[284840],[6,3868],[6,5888],[6,6620],[6,492],[6,4569],[6,193],[6,2834],[6,8480],[6,9786],[6259],[6,1009],[6,9456],[338035],[6,1554],[6,6985],[6,9570],[6,672],[6,3774],[6,913],[6,3746],[6,7927],[6,4721],[6259],[6,6608],[6259],[6259],[6,349],[6,6009],[6,3711],[394574],[6,7821],[6,4897],[6,7814],[6,2334],[6,5597],[6,5965],[6,8232],[6,2350],[6,6110],[6,6930],[6,3076],[6,2682],[6,6367],[6,9713],[6259],[6,5562],[6,3749],[6,6890],[6,4083],[6,8753],[503499],[6,8094],[6,9585],[6,5932],[6,2233],[6,6747],[6,7658],[6,7518],[551266],[6259],[551266],[6,3933],[6,5155],[6,5902],[6,8543],[6,7128],[6,9462],[6,951],[6,5889],[6259],[6,1020],[6,9152],[608401],[608401],[6259],[608401],[608401],[608401],[608401],[608401],[608401],[608401],[608401],[608401],[608401],[6259],[6259],[6259],[6259],[6259],[6259],[608401],[6259],[6259],[6259],[6259],[608401],[608401],[608401],[6259],[608401],[6259],[608401],[6259],[6259],[6259],[6259],[608401],[6259],[6259],[6259],[6259],[6259],[608401],[6259],[6259],[6259],[608401],[6259],[608401],[608401],[6259],[608401],[6259],[6259],[6259],[6259],[608401]]