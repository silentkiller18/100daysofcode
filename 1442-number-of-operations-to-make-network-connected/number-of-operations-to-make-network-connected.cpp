class DisjointSetUnion {
    vector<int> size, parent;
    public:
    DisjointSetUnion(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;
        if(size[pu]<size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSetUnion dsu(n);
        int wireFree = 0;
        for(auto &connection : connections) {
            if(dsu.findParent(connection[0]) == dsu.findParent(connection[1])) {
                wireFree++;
                continue;
            }
            dsu.unionBySize(connection[0], connection[1]);
        }
        int component = 0;
        set<int> s;
        for(int i=0;i<n;i++) {
            if(s.find(dsu.findParent(i)) == s.end()) {
                component++;
                s.insert(dsu.findParent(i));
            }
        }
        if((s.size()-1) <= wireFree) {
            return s.size()-1;
        }
        return -1;
    }
};