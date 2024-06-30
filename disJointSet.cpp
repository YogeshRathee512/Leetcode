class Disjoint {
    vector<int> size;
    vector<int> parent;

public:
    Disjoint(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]); // Path compression
    }

    void unionBySize(int u, int v) {
        int u_par = findParent(u);
        int v_par = findParent(v);

        if(u_par != v_par) {
            if(size[u_par] > size[v_par]) {
                parent[v_par] = u_par;
            } else {
                parent[u_par] = v_par;
            }
        }
        
         int total = size[u_par] + size[v_par]; 
         size[u_par] = total ;
         size[v_par] = total;
    }
};
