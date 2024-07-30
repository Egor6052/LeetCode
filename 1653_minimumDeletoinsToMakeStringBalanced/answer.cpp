class Solution {
public:
    int minimumDeletions(string s) {
        int numberA = 0;
        int numberB = 0;
        int deleted = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i == 'a') {
                numberA++;
            } else {
                numberB++;
            }
            deleted = min(deleted + (i == 'b' ? 1 : 0), numberB);
        }
        
        return deleted;
    }
};