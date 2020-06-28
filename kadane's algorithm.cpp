// modified kadane's algorithm. works for both +ve and -ve values and also for all -ve values.

#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> arr)
{
    vector<int> res(3,-1);      // stores max_sum, start_index, end_index
    
    int max = arr[0], start = 0, end = 0, mstart = 0, mend = 0, currmax = arr[0];
    
        for (int i = 1; i < arr.size(); i++) {
            if (  currmax < 0 ) {
                currmax = arr[i];
                start = i;
                end = i;
            } else {
                currmax = currmax + arr[i];
                end = i;
            }

            if (currmax > max) {
                max = currmax;
                mstart = start;
                mend = end;
            }
        }

    res[0] = max;
    res[1] = mstart;
    res[2] = mend;

    return res;
}

int main()
{
    vector<int> arr = {5,-8,1,2,3};
    vector<int> res = solve(arr);
    cout << "sum: " << res[0] << " from: " << res[1] << " to: " << res[2] << "\n";
}
