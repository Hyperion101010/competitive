#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

ll lef = 0;

class g
{
    ll siz;
    list<ll> *adj;

public:
    g(ll siz)
    {
        this->siz = siz;
        adj = new list<ll>[siz];
    }
    void addedge(ll u, ll v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*
    void dfs_util(ll ind, bool visit[])
    {
        //bool visit[siz];
        //memset(visit,false,sizeof(visit));
        visit[ind] = true;
        for (auto i = adj[ind].begin(); i != adj[ind].end(); i++)
        {
            if (!visit[*i])
            {
                dfs_util(*i, visit);
            }
        }
    }
    void dfs(ll ind)
    {
        bool visit[siz];
        memset(visit, false, sizeof(visit));
        dfs_util(ind, visit);
    }*/
    void bfs(ll ind)
    {
        bool visit[siz];
        memset(visit, false, sizeof(visit));
        queue<ll> c;
        c.push(ind);
        while (!c.empty())
        {
            ll cght = c.front();
            visit[cght] = true;
            c.pop();
            if (adj[cght].size() == 2)
            {
                for(auto it = adj[cght].begin(); it!=adj[cght].end();it++){
                   // cout << "for" << cght<<" "<<adj[*it].size()<<'\n';
                    if (adj[*it].size() >=0 )
                    {
                        lef+=1;
                    }
                }
                //cout<<"lef"<<lef<<'\n';
                if( lef ==2){
                    return;
                }
                else{
                    lef=0;
                }
               // return;
            }
            for (auto itr = adj[cght].begin(); itr != adj[cght].end(); itr++)
            {
                if(!visit[*itr]){
                c.push(*itr);
                }
            }
        }
    }
};

int main()
{
    ll sz;
    cin >> sz;
    g dt(sz+1);
    sz -= 1;
    ll df = sz;
    while (sz--)
    {
        ll ip1, ip2;
        cin >> ip1 >> ip2;
        dt.addedge(ip1, ip2);
    }
    dt.bfs(df);
    if (lef==2)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
    return 0;
}
