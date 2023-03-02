class Solution {
private:
    void write(vector<char>& chars, int& index, char c, int count) {
        chars[index] = c;
        ++index;
        if (count == 1) return;
        string s{to_string(count)};
        for (auto i : s) {
            chars[index] = i;
            ++index;
        }
    }
public:
    int compress(vector<char>& chars) {
        auto ans{0};
        char c{chars[0]};
        int count{1};
        int index{0};
        for (auto i = 1; i < chars.size(); ++i) {
            if (chars[i] == c) ++count;
            else {
                write(chars, index, c, count);
                ++ans;
                if (count > 1) ans += to_string(count).size();
                count = 1;
                c = chars[i];
            }
        }
        write(chars, index, c, count);
        if (count == 1) return ans + 1;
        else return ans + 1 + to_string(count).size();
    }
};