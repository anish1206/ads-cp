#include "JobCorrector.h"
#include <string.h>

static int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// Classic DP Algorithm: Levenshtein (Edit) Distance
int edit_distance(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[50][50];
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min3(
                    dp[i][j - 1],    // Insert
                    dp[i - 1][j],    // Remove
                    dp[i - 1][j - 1] // Replace
                );
            }
        }
    }
    return dp[len1][len2];
}
