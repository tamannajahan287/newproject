
#include<iostream>
using namespace std;
int MAX = 500;

int editDistance(string & word1, string & word2)
{
    int row = word1.length();
    int column = word2.length();
    int array[MAX][MAX];

    for (int i = 0; i <= row; ++i) {
        for (int j = 0; j <= column; ++j) {
            if (i == 0 || j == 0) {
                array[i][j] = 0;
            } else if (word1[i - 1] == word2[j - 1]) {
                array[i][j] = array[i - 1][j - 1] + 0;
            } else {
                array[i][j] = min(min(array[i - 1][j] + 1,
                     array[i][j - 1] + 1), array[i - 1][j - 1] + 2);
            }
        }
    }
    return array[row][column];
}

int main() {
    string word1 = "kitten";
    string word2 = "sitting";

    int distance = editDistance(word1, word2);

    cout << "Minimum Edit Distance: " << distance << endl;

    return 0;
}
