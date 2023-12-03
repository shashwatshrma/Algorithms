#include <iostream>
#include <vector>

using namespace std;

vector<int> calcLPS(string pat)
{
    vector<int> lps(pat.length());
    int i=1, len=0;
    lps[0]=0;
    while (i<pat.length())
    {
        if(pat[len]==pat[i])
        {
            lps[i]=++len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string &str, string &pat)
{
    vector<int> lps=calcLPS(pat);
    int i=0, j=0;
    while (i<str.length() && j<pat.length())
    {
        if(pat[j] == str[i])
        {
            j++;
            i++;
        }
        else
        {
            if(j != 0)
                j=lps[j - 1];
            else
                i++;
        }
    }
    if(j==pat.length())
        return true;
    return false;
}

int main()
{
    string str, pat;
    cin>>str>>pat;
    cout<<KMP(str, pat)<<'\n';
}