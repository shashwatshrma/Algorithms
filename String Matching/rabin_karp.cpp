#include <iostream>

using namespace std;

int calculate_hash(string str, int lim)
{
    int hash = 0;
    for (int i = 0; i < lim; i++)
        hash += str[i];
    return hash;
}

bool matches(string str, int beg, int end, string pat)
{
    for (int i = beg, j = 0; i < end; i++, j++)
    {
        if (str[i] != pat[j])
            return false;
    }
    return true;
}

int rabin_karp(string str, string pat)
{
    int k = pat.length();
    int pat_hash = calculate_hash(pat, k);
    int window_hash = calculate_hash(str, k);
    if (pat_hash == window_hash && matches(str, 0, k, pat))
        return 0;
    for (int i = k; i < str.length(); i++)
    {
        window_hash -= str[i - k];
        window_hash += str[i];
        if (pat_hash == window_hash && matches(str, i-k+1, i+1, pat))
            return i-k+1;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str, pat;
        cin >> str >> pat;
        int res = rabin_karp(str, pat);
        if (res == -1)
            cout << "Pattern not found in string" << '\n';
        else
            cout << "Pattern found starting at index " << res << '\n';
    }
}