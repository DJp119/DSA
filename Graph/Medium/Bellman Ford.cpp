vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int>distance(n+1,1e8);
    distance[src]=0;
    // n-1 times
    for(int i=1;i<n;i++){
        // traverse on edge list
        for (int j = 0; j < m; j++) {
          int u = edges[j][0];
          int v = edges[j][1];
          int wt = edges[j][2];

          if ((distance[u] + wt) < distance[v]){
              distance[v]=distance[u]+wt;
          }
        }
    }
    // check for -ve cycles
    bool flag = 0;
        for (int j = 0; j < m; j++) {
          int u = edges[j][0];
          int v = edges[j][1];
          int wt = edges[j][2];

          if (distance[u] != 1e9 && (distance[u] + wt) < distance[v]){
              flag=1;
          }
        }
    if(flag == 0 ) return distance;
}
