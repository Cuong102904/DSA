char *longestPalindrome(char *s)
{
    int n = strlen(s);
    int maxlength = 0;
    int start = 0;
    char *c = (char *)malloc(1001 * sizeof(char)); // allocate memory dynamically
    memset(c, 0, sizeof(c));                       // initialize c with zeros
    int dp[n][n];
    memset(dp, 0, sizeof(dp)); // initialize dp with zeros
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    int i, j;
    for (int diff = 1; diff < n; diff++)
    {
        for (i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (diff == 1)
            {
                dp[i][j] = (s[i] == s[j]) ? 2 : 0;
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            if (dp[i][j] && j - i + 1 > maxlength)
            {
                start = i;
                maxlength = j - i + 1;
            }
        }
    }
    int k = 0;
    for (int j = start; j < start + maxlength; j++)
    {
        c[k++] = s[j];
    }
    c[k] = '\0'; // add null character at the end of c
    return c;
}
