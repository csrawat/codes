#include<bits/stdc++.h>
#define ppi pair<int,pair<int ,int> >
using namespace std;

vector<int> mergeSort(vector<vector<int> > arr)
{
    vector<int> res;
    priority_queue<ppi,vector<ppi>,greater<ppi> > pq;

    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }

    while(!pq.empty())
    {
        ppi curr = pq.top();
        pq.pop();

        int data = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;

        res.push_back(data);

        if(j+1<arr[i].size())
        {
            pq.push({arr[i][j+1],{i,j+1}});
        }
    }


    return res;
}

int main()
{
    vector<vector<int> > arr = {

                            {2,6,12},
                            {1,9},
                            {23, 34, 90, 2000}
                    };

    vector<int> res = mergeSort(arr);

    for(int e:res)
    {
        cout << e << " ";
    }
}
