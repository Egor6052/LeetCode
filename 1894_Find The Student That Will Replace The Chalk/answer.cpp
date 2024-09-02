class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
         long long totalChalk = 0;
        for (int c : chalk) {
            totalChalk += c;
        }

        k %= totalChalk; // Залишок від ділення, щоб знайти ефективний запас крейди

        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) {
                return i; // Якщо запас крейди менший за потребу, повертаємо індекс
            }
            k -= chalk[i]; // Зменшуємо кількість крейди на ту, що витрачає студент
        }

        return -1;
    }
};