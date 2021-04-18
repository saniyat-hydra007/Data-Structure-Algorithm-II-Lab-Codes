/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   18-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: test.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 18-Apr-2021
 */



#include <bits/stdc++.h>
using namespace std;

const int max_value = 1000;

int N, M;

// For calculating length of longest common subsequence

int lcs(string S, string T, int i, int j, int memo[][max_value])
{
        // one or both of the strings are fully traversed

        if (i == N || j == M)
                return 0;

        // if result for the current pair is already present in
        // the table

        if (memo[i][j] != -1)
                return memo[i][j];

        // check if the current characters in both the strings are equal

        if (S[i] == T[j])
                // check for the next characters in both the strings and store the
                // calculated value in the memo table

                memo[i][j] = lcs(S, T, i + 1, j + 1, memo) + 1;
        else

                // check which call has the maximum value and store in
                // the memo table

                memo[i][j] = max(lcs(S, T, i + 1, j, memo), lcs(S, T, i, j + 1, memo));
        return memo[i][j];
}

// Driver Code

int main()
{
        string S = "ABDE";
        string T = "ZBE";

        N = S.length();
        M = T.length();

        // table for memoization

        int memo[N][max_value];

        // initializing memo table with -1

        for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        memo[i][j] = -1;

        cout << "Length of longest common subsequence " << lcs(S, T, 0, 0, memo);

        return 0;
}
