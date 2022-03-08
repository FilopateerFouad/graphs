//check the graph is bipartite or not//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
vector<int>col;
bool bi=1;
int t,n,m,cnt;
void DFS(int u){
vis[u]=1;
for(int v:adj[u]){
    if(vis[v]==0){
        col[v]=(1-col[u]);
        DFS(v);
    }
    else if(col[u]==col[v])
        bi=0;
}
}
int main(){
    cin>>t;
    while(t--){
    cin>>n>>m;
    adj.clear();
    vis.clear();
    col.clear();
    col=vector<int>(n,-1);
    vis=vector<bool>(n,0);
    adj.resize(n);
    bi=1;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
             col[i]=0;
             DFS(i);
        }
    }
    if(bi==0)
        cout<<"Scenario #"<<++cnt<<":"<<endl<<"Suspicious bugs found!"<<endl;
    else
        cout<<"Scenario #"<<++cnt<<":"<<endl<<"No suspicious bugs found!"<<endl;
    }

     return 0;
    }
