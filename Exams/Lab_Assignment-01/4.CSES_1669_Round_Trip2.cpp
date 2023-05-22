#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool visited[100005];
vector<int> vec;

bool dfs(int x, int y)
{
    visited[x]=1;
    for(auto i: adj_list[x])
    {
        vec.push_back(i);

        if(!visited[i])
        {
            if(dfs(i,x))
            {
                return 1;
            }
        }
        else if(i!= y)
        {
            return 1;
        }
        vec.pop_back();
    }
    return 0;
}

int main()
{
    int n,m;
    cin >>n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for(int i=1; i<n+1; i++)
    {
        vec.push_back(i);
        if(!visited[i] && dfs(i,0))
        {
            vector<int> ans={*vec.rbegin()};
            for(auto j=vec.rbegin()+1; j!=vec.rend(); j++)
            {
                ans.push_back(*j);
                if (*j==*vec.rbegin())
                {
                    break;
                }
            }

            cout<<ans.size()<<endl;
            for(auto i: ans)
            {
                cout<<i<<" ";
            }

            return 0;
        }

        vec.pop_back();
    }

    cout<<"IMPOSSIBLE";
}


/*
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3

*/
