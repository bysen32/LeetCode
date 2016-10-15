class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, int> namemap;
        vector<double> ans;
        int nameidx = 0;
        for ( p : equations ) {
            if (namemap.find(p.first) == namemap.end()) {
                namemap[p.first] = nameidx;
                nameidx+=1;
            }
            if (namemap.find(p.second) == namemap.end()) {
                namemap[p.second] = nameidx;
                nameidx+=1;
            }
        }
        
        vector<vector<double>> G(nameidx, vector<double>(nameidx, -1));
        for (int i=0; i<equations.size(); ++i) {
            pair<string, string> p = equations[i];
            int src = namemap[p.first];
            int dst = namemap[p.second];
            G[src][dst] = values[i];
            G[dst][src] = 1/values[i];
            G[src][src] = G[dst][dst] = 1;
        }
        
        for ( int i=0; i<nameidx; ++i ) {
            for ( int j=0; j<nameidx; ++j ) {
                if ( G[i][j] != -1 ) {
                    for ( int k=0; k<nameidx; ++k ) {
                        if ( G[j][k] != -1 ) {
                            G[i][k] = G[i][j] * G[j][k];
                        }
                    }
                }
            }
        }
        for ( p : queries ) {
            if ( namemap.find(p.first) == namemap.end() || namemap.find(p.second) == namemap.end() ) {
                ans.push_back(-1);
            }
            else {
                int src = namemap[p.first];
                int dst = namemap[p.second];
                ans.push_back(G[src][dst]);
            }
        }
        return ans;
    }
};