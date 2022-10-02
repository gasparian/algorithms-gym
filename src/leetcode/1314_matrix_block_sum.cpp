#include <bits/stdc++.h>

std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int K) {
    std::vector<std::vector<int>> res;
    int n = mat.size();
    int m = mat[0].size();
    res.resize(n, std::vector<int>(m));
    for ( int i=0; i < n; ++i ) {
        for ( int j=0; j < m; ++j ) {
            res[i][j] = 0;
            for ( int ik=std::max(0, i - K); ik <= std::min(n - 1, i + K); ++ik ) {
                for ( int jk=std::max(0, j - K); jk <= std::min(m - 1, j + K); ++jk ) {
                    res[i][j] += mat[ik][jk];
                }
            }
        }
    }
    return res;
}

int main() {
    // mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1 --> [[12,21,16],[27,45,33],[24,39,28]]
    // mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2 --> [[45,45,45],[45,45,45],[45,45,45]]
    return 0;
}
