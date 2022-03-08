#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, pair<int, int>> ppi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    int t[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if ((i == 0 || j == 0))
                t[i][j] = 0;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = 1 + t[i - 1][j - 1];

            else
                t[i][j] = max(t[i][j - 1], t[i - 1][j]);
        }
    }

    string s3 = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            s3.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
                j--;
            else
                i--;
        }
    }

    reverse(s3.begin(),s3.end());   //now we have the lcs of the two strings.

int ins=0,del=0;

del = s1.length() - s3.length();
ins = s2.length() - s3.length();

cout<<"Insertion = "<<ins<<endl;
cout<<"Deletion = "<<del<<endl;
    return 0;
}
