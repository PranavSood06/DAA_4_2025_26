#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

int main(){
    int V = 5;
    vector<Edge> edges = {
        {0,1,4},{0,2,5},{1,2,-3}
    };

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    for(int i=0;i<V-1;i++){
        for(auto e: edges){
            if(dist[e.u]!=INT_MAX && dist[e.u]+e.w<dist[e.v]){
                dist[e.v] = dist[e.u]+e.w;
            }
        }
    }

    for(auto e: edges){
        if(dist[e.u]!=INT_MAX && dist[e.u]+e.w<dist[e.v]){
            cout<<"Negative cycle";
            return 0;
        }
    }

    for(int i=0;i<V;i++) cout<<dist[i]<<" ";
}