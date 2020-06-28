#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> a)
{
    vector<int> res(3,-1);
    int msf = INT_MIN , meh = 0;
    int n = 0, m = 0;
    for(int i=0;i<a.size();i++)
    {
        meh += a[i];
        if(a[i]>meh)
        {
            meh = a[i];
            if(msf<meh) n = i;
        }

        if(msf<meh)
        {
            msf = meh;
            m = i;
        }
    }

    res[0] = msf;
    res[1] = n;
    res[2] = m;

    return res;
}

int main()
{
    vector<int> arr = {1,1,3,-4,5};
    vector<int> res = solve(arr);
    cout << "sum: " << res[0] << " from: " << res[1] << " to: " << res[2] << "\n";
}
