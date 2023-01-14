class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<int> set;
        auto wordLen{words[0].size()};
        
        unordered_map<string, int> wordsFreq;
        for (auto w : words) ++wordsFreq[w];
        
        for (auto a = 0; a < wordLen; ++a) {
            // cout << "new iteration\n";
            unordered_map<string, int> curFreq;
            auto curLen{0};
            
            auto i{a};
            auto j{a};
            
            while (j < s.size()) {
                // cout << i << " " << j << "\n";
                auto word{s.substr(j, wordLen)};
                // cout << word << "\n";
                if (wordsFreq.find(word) != wordsFreq.end()) {
                    ++curFreq[word];
                    ++curLen;
                    j += wordLen;
                    
                    if (curFreq[word] > wordsFreq[word]) {
                        while (i < j && curFreq[word] > wordsFreq[word]) {
                            auto delWord{s.substr(i, wordLen)};
                            --curFreq[delWord];
                            --curLen;
                            i += wordLen;
                        }
                    }
                    else if (curLen == words.size()) {
                        set.insert(i);
                        --curFreq[s.substr(i, wordLen)];
                        --curLen;
                        i += wordLen;
                    }
                } else {
                    j += wordLen;
                    i = j;
                    curLen = 0;
                    curFreq.clear();
                }
            }
        }

        vector<int> ans(set.begin(), set.end());
        return ans;
    }
};

// "wordgoodgoodgoodbestword"
// ["word","good","best","good"]
// "aaa"
// ["a","a"]
// "dddddddddddd"
// ["dddd","dddd"]