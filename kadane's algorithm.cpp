//modified kadane's algorithm. works for both +ve and -ve values and also for all -ve values.
#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> a)
{
    vector<int> res(3,-1);          // stores max sum, start index, end index
    int msf = INT_MIN , meh = 0;    // msf - max so far, meh - max ending here
    int n = 0, m = 0;               // n - start index, m = end index
    
    for(int i=0;i<a.size();i++)
    {
        meh += a[i];
        if(a[i]>meh)
        {
            meh = a[i];
            if(msf<meh) n = i;      // dry run {-1,-2,-3,-4} for understanding this check.
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
