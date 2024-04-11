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
        else
        {
            i+=bad_match[str[i]-'a'];
            j=patlen-1;
        }
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