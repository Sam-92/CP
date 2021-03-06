long long n , l , in[N] , out[N];
long long timer = 0;
vector<long long> v[N] , up[N];

void dfs(long long node , long long pr){
    in[node] = ++timer;
    
    up[node][0] = pr;
    for(int i = 1 ; i <= l ; i++){
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for(auto child : v[node]){
        if(child != pr){
            dfs(child , node);
        }
    }

    out[node] = ++timer;
}

bool is_ancestor(long long ancestor , long long node){
    return (in[ancestor] <= in[node] && out[ancestor] >= out[node]);
}

long long lca(long long u , long long v){
    if(is_ancestor(u , v)) return u;
    if(is_ancestor(v , u)) return v;

    for(int i = l ; i >= 0 ; i--){
        if(!is_ancestor(up[u][i] , v)) u = up[u][i];
    }

    return up[u][0];
}

void preprocess(long long root){
    timer = 0;
    l = ceil(log2(n));

    for(int i = 0 ; i < n + 1 ; i++){
        up[i].clear();
        in[i] = out[i] = 0;
        up[i].resize(l + 1);
    }

    dfs(root , root);
}
ll climb(ll x , ll d){
    FORR(j , 20 , 0){
        if(d & (1ll << 1ll*j)){
            d -= (1ll << 1ll*j);
            x = up[x][j];
        }
    }
    return x;
}