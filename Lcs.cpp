#include <iostream>
using namespace std;
string LCS(string& word1,string& word2)
{
    int row = word1.length();
    int column = word2.length();
    int array[row + 1][column + 1];

    for (int i = 0; i <= row; ++i){
        for (int j = 0; j <= column; ++j){
            if (i == 0 || j == 0){
                array[i][j] = 0;
            }
            else if (word1[i - 1] == word2[j - 1]){
                array[i][j] = array[i - 1][j - 1] + 1;
            }
            else{
             array[i][j] = max(array[i - 1][j], array[i][j - 1]);
            }
        }
    }
    int i = row, j = column;
    string lcs;
    while (i > 0 && j > 0){
        if (word1[i - 1] == word2[j - 1]){
            lcs = word1[i - 1] + lcs;
            --i;
            --j;
        }
        else if (array[i - 1][j] > array[i][j - 1]){
            --i;
        }
        else{
            --j;
        }
    }
    return lcs;
}
int main()
{   string word1 = "ABCDGH";
    string word2 = "AEDFHR";
    string result = LCS(word1, word2);
    cout << "Length of LCS: " << result << endl;
    return 0;
}
