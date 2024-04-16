#include <iostream>
#include <vector>

using namespace std;

vector<int> calc_bad_match(string &pat)
{
    int len=pat.length();
    /*
    * only considering lowercase english letters
    * a hashmap may be used for a generalized solution
    */
    vector<int> bad_match(26, len);
    for(int i=0;i<len;i++)
    {
        bad_match[pat[i]-'a'] = max(1, len-i-1);
    }
    return bad_match;
}

bool boyer_moore(string str, string pat)
{
    vector<int> bad_match = calc_bad_match(pat);
    int strlen=str.length();
    int patlen=pat.length();
    int i=patlen-1, j=patlen-1;
    while(i<strlen)
    {
        while(i>=0 && j>=0 && str[i] == pat[j])
        {
            i--;
            j--;
        }
        if(j==-1)
        {
            return true;
        }
        if(i+1>=strlen)
        {
            return false;
        }
        i+=bad_match[str[i+1]-'a'];
        j=patlen-1;
    }
    return false;
}

int main()
{
    string str, pat;
    cin>>str;
    cin>>pat;
    if(boyer_moore(str, pat))
        cout<<"Pattern present in the string"<<endl;
    else
        cout<<"Pattern absent in the string"<<endl;
    return 0;
}

/*
class Solution {
    vector<int> calcBadMatch(string &pat)
    {
        int len=pat.length();
        vector<int> bm(26, len);
        for(int i=len-1;i>=0;i--)
        {
            if(bm[pat[i]-'a'] == len)
                bm[pat[i]-'a'] = max(1, len-1-i);
        }
        return bm;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> bm = calcBadMatch(needle);
        int i=needle.length()-1;
        int j=needle.length()-1;
        for(int i=0;i<26;i++)
        {
            cout<<(char)(i+'a')<<" "<<bm[i]<<endl;
        }
        while(i<haystack.length())
        {
            int oi=i;
            while(j>=0 && i>=0 && needle[j]==haystack[i])
            {
                j--;
                i--;
            }
            if(j<0)
                return i+1;
            i=oi+bm[haystack[i]-'a'];
            j=needle.length()-1;
        }
        return -1;
    }
};
*/