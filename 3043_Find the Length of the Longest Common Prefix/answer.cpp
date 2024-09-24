class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> strArr1(arr1.size());
        vector<string> strArr2(arr2.size());
        
        for (int i = 0; i < arr1.size(); ++i) {
            strArr1[i] = to_string(arr1[i]);
        }
        for (int i = 0; i < arr2.size(); ++i) {
            strArr2[i] = to_string(arr2[i]);
        }

        int maxLength = 0;

        for (const string& s1 : strArr1) {
            for (const string& s2 : strArr2) {
                int currentLength = 0;
                int minLength = min(s1.size(), s2.size());

                while (currentLength < minLength && s1[currentLength] == s2[currentLength]) {
                    currentLength++;
                }

                maxLength = max(maxLength, currentLength);
            }
        }

        return maxLength;
    }
};