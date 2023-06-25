class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(128,0);
        for (auto& i : t) ++v[i];
        auto count{t.size()};
        auto left{0};
        auto right{0};
        auto ans{INT_MAX};
        auto len{INT_MAX};
        
        while (right < s.size()) {
            if (v[(int) s[right]] > 0) {
                --count;
            }
            --v[(int) s[right]];
            while (count == 0) {
                if (right - left < len) {
                    len = right - left + 1;
                    ans = left;
                }
                ++v[(int) s[left]];
                if (v[(int) s[left]] > 0) ++count;
                ++left;
            }
            ++right;
        }
        
        return ans == INT_MAX ? "" : s.substr(ans, len);
    }
    // string minWindow(string s, string t) {
    //     vector<int> map(128,0);
    //     for(auto c: t) map[c]++;
    //     int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
    //     while(end<s.size()){
    //         if(map[s[end++]]-->0) counter--; //in t
    //         while(counter==0){ //valid
    //             if(end-begin<d)  d=end-(head=begin);
    //             if(map[s[begin++]]++==0) counter++;  //make it invalid
    //         }  
    //     }
    //     return d==INT_MAX? "":s.substr(head, d);
    // }
};