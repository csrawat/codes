#include<bits/stdc++.h>
#define ppi pair<int,pair<int ,int> > // stores { element , { index of array , index of element in array } }
using namespace std;

vector<int> mergeSort(vector<vector<int> > arr)
{
    vector<int> res;    // stores final result
    priority_queue<ppi,vector<ppi>,greater<ppi> > pq;   // creating min_heap ( root of heap contains min element )

    // insert first element of each array into the pq
    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }

    while(!pq.empty())
    {
        ppi curr = pq.top();
        pq.pop();

        int data = curr.first;          // element
        int i = curr.second.first;      // index of array
        int j = curr.second.second;     // index of element in array

        res.push_back(data);

        if(j+1<arr[i].size())   // checking if there are more elements present in the array to process 
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
