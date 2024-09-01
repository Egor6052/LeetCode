class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Кількість елементів у original співпадає з m * n ?
        if (original.size() != m * n) {
            return {};
        }

        // Ініціалізуємо 2D масив розміром m x n
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < original.size(); ++i) {
            result[i / n][i % n] = original[i];
        }

        return result;
    }
};
