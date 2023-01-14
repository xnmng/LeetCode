class Solution {
private:
    char uf(vector<char>& parent, char c) {
        // cout << c << "\n";
        if (parent[c - 'a'] == ' ') {
            parent[c - 'a'] = c;
            return c;
        }
        if (parent[c - 'a'] == c) return c;
        return uf(parent, parent[c - 'a']);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> parent(26, ' ');
        for (auto i : equations) {
            if (i[1] == '=') {
                parent[uf(parent, i[0]) - 'a'] = uf(parent, i[3]);
                // cout << uf(parent, i[0]) << "\n";
            }
        }
        for (auto i : equations) {
            if (i[1] == '!' && uf(parent, i[0]) == uf(parent, i[3])) {
                return false;
            }
        }
        return true;
    }
};

