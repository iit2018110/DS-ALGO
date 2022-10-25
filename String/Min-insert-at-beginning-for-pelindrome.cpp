vector<int> compute(string pat)
{
    vector<int> lps(pat.size());
    lps [0] = 0;
    int len =0;
    int i=1;
    while(i<pat.size())
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] =0;
                i++;
            }
        }
    }
    return lps;
}

int Solution::solve(string A) 
{
    string str,A2;
    A2 = A;
    reverse(A2.begin(),A2.end());
    str = A + '$' + A2;
    vector <int> lps = compute(str);
    int size = A.size();
    int ans = size - lps[str.size()-1]; 
    return ans;
}

