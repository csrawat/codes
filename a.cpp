#include<bits/stdc++.h>

using namespace std;

vector<int> max_sum_subarray(vector<int> a)
{
    vector<int> res(3,-1);
    int curr_max = a[0],max=a[0],start_index=0,end_index=0,mstart=0,mend=0;

    for(int i=1;i<a.size();i++)
    {
        if(curr_max<0)
        {
            start_index = i;
            end_index = i;
            curr_max = a[i];
        }
        else
        {
            curr_max += a[i];
            end_index = i;
        }

        if(curr_max>max)
        {
            mstart = start_index;
            mend = end_index;
            max = curr_max;
        }
    }


    res[0] = max;
    res[1] = mstart;
    res[2] = mend;

    return res;

}


int main()
{
    vector<vector<int> > a = {

                {6,-5,-7,4,-4},
                {-9,3,-6,5,2},
                {-10,4,7,-6,3},
                {-8,9,-3,3,-7}
            };

        int n = a.size();
        int m = a[0].size();


        int left_index=0,right_index=0,up_index=0,down_index=0,max_sum=a[0][0];

        vector<int> res(3);
        for(int i=0;i<m;i++)
        {
            vector<int> row_sum(n,0);
            for(int j=i;j<m;j++)
            {

                for(int k=0;k<n;k++)
                {
                    row_sum[k] += a[k][j];
                }


                res = max_sum_subarray(row_sum);
                if(res[0]>max_sum)
                {
                    max_sum = res[0];
                    left_index = i;
                    right_index = j;
                    up_index = res[1];
                    down_index = res[2];
                }
            }
        }


        cout << "top left ( " << up_index << " , " << left_index << " )\n";
        cout << "bottom right ( " << down_index << " , " << right_index << " )\n";
        cout << "Sum: " << max_sum;



}
