#include <iostream>
#include <vector>
using namespace std;



void explore(int e,vector<vector<int> > &adj,vector<int> &visited){
    visited[e]=1;
    int s=adj[e].size();
    for(int i=0;i<s;i++){
        if(visited[adj[e][i]]==0){
            explore(adj[e][i],adj,visited);
        }
    }

}

int main()
{
    int V;
    int E;
    cin>>V;
    cin>>E;
    vector<vector<int> > adj(V,vector<int>());
    int x,y;
    for(int i=0;i<E;i++){
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    int start;
    int ends;
    cin>>start>>ends;
    start--;
    ends--;

    vector<int> visited(V);
    for(int i=0;i<V;i++){
        visited[i]=0;
    }

    explore(start,adj,visited);
    if(visited[ends]==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
}
