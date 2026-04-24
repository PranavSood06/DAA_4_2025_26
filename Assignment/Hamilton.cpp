class Solution {
  public:
  vector<int> path;
  vector<bool> visited;
  vector<vector<int>> adj;
  int v;
    bool dfs(int u){
        if( path.size() == v){
            return true;
        }
        for(int i: adj[u]){
            if(!visited[i]){
                path.push_back(i);
                visited[i] = true;
                if(dfs(i)) return true;
                path.pop_back();
                visited[i] = false;
            }            
        }
        return false;
        
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        adj = vector<vector<int>> (n);
        visited = vector<bool>(n,false);
        for(vector<int> i:edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        v = n;
        for(int st= 0; st<n;st++){
            path.clear();
            visited.assign(n,false);
        path.push_back(st);
        visited[st] = true;
        if(dfs(st)) return true;
        }
        return false;
    }
    
};