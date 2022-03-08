#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<bool>vis;
int t,n,m,cnt,mxcnt;
void DFS(int u){
vis[u]=1;
cnt++;
for(int v:adj[u]){
    if(vis[v]==0)
        DFS(v);
}
}
int main(){
    cin>>t;
    while(t--){
    cin>>n>>m;
    adj.clear();
    vis=vector<bool>(n,0);
    adj.resize(n);
    cnt=0;
    mxcnt=0;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
             cnt=0;
             DFS(i);
        mxcnt=max(cnt,mxcnt);
        }
    }
    cout<<mxcnt<<endl;
    }
     return 0;
    }
