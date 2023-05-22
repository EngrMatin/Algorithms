#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nodes, edges;
    cin>>nodes>>edges;

    int adj[nodes+1][nodes+1];
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;

        adj[u][v] = 1;
    }

//    for(int i=0; i<nodes; i++)
//    {
//        for(int j=0; j<nodes; j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    int count = 0;
    for(int i=0; i<nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            if(adj[i][j] == 1)
            {
                if(adj[j][i] != 1)
                {
                    adj[i][j] = 0;
                    count++;
                }
            }
        }
    }

    cout<<"\n Number of unidirectional edges= "<<count<<endl;

//    for(int i=0; i<nodes; i++)
//    {
//        for(int j=0; j<nodes; j++)
//        {
//            cout<<adj[i][j]<<" ";
//        }
//        cout<<endl;
//    }

    return 0;
}

/*

0 ----> 1 ----- 2 ----> 3
        |       |
        |       |
        5 <---- 4

no. of nodes = 6
no. of edges = 9


6 9

0 1
1 2
2 1
2 3
1 5
5 1
2 4
4 2
4 5

input
3 6

1 2
2 1
2 3
3 2
1 3
3 1
output
Bi-derectional

Question 2
input
3 5

1 2
2 1
2 3
3 2
1 3
output
2

For question 2:
u-> v te kono edge thakle setake 0 kore diben ba remove kore diben..

2 no e jodi dekhen adj[i][j] e node ache, but adj[j][i] te kono node nei mane sei ta akta directed node, tokhn adj[i][j] er node ta 0 kore deben, ai vabe adj[j][i] er sapekke adj[i][j] teo aki vabe check korben and same kaj krben

*/

