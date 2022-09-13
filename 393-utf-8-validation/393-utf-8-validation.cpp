class Solution {
public:
    // read the question CAREFULLY! 1 to 4 bytes long!
    bool validUtf8(vector<int>& data) {
        auto index{0};
        while (index < data.size()) {
            if (data[index] >= 128 && data[index] < 192) return false;
            else if (data[index] >= 128) {
                auto count{getCount(data[index])};
                if (count >= 4) return false;
                // cout << data[index] << " " << count << "\n";
                for (auto i = 0; i < count; ++i) {
                    if (index+i+1 >= data.size() 
                        || data[index+i+1] < 128 
                        || data[index+i+1] >= 192) return false;
                }
                index += count;
            }
            ++index;
        }
        return true;
    }
private:
    int getCount(int num) {
        auto cur{128};
        auto ans{0};
        while (cur > 0 && num / cur == 1) {
            ++ans;
            num -= cur;
            cur /= 2;
        }
        return ans-1;
    }
};

// [255]
// [145]
// [250,145,145,145,145]