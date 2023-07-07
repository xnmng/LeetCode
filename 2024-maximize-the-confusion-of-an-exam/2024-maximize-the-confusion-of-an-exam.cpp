class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // 1 pass, 2 pointer approach for both F (flip T to F) and T (flip F to T)
        auto ans{0};
                
        auto falseFlipCount{0}; // how many false we flipped
        auto leftFalse{0}; // flip false to true
        
        auto trueFlipCount{0};
        auto leftTrue{0};

        auto right{0};
        while (right < answerKey.size()) {
            if (answerKey[right] == 'T') {
                ++trueFlipCount;
            }
            else if (answerKey[right] == 'F') {
                ++falseFlipCount;
            }
            while (leftFalse <= right && falseFlipCount > k) {
                if (answerKey[leftFalse] == 'F') --falseFlipCount;
                ++leftFalse;
            }
            while (leftTrue <= right && trueFlipCount > k) {
                if (answerKey[leftTrue] == 'T') --trueFlipCount;
                ++leftTrue;
            }
            // cout << right << " " << leftTrue << " " << trueFlipCount << "\n";
            // cout << right << " " << leftFalse << " " << falseFlipCount << "\n\n";
            ++right;
            ans = max(ans, right - leftTrue);
            ans = max(ans, right - leftFalse);
        }
        return ans;
    }
};