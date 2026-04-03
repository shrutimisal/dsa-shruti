#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int primsMST(int V , vector<pair<int,int>> adj[]){
    //MST set creation :
    vector<bool> inMST(V , false);
    //Pirority Queue creation :
    priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq; // minheap

    int mstCost = 0;

    pq.push({0,0}); // (weight , source ) --> in this format it will be stored in PQ

    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int u = p.second;

        pq.pop();

        if(!inMST[u]){
            inMST[u] = true;
            mstCost += wt;

            for(int i=0; i< adj[u].size(); i++){
                int v = adj[u][i].first;
                int wt = adj[u][i].second;
                pq.push({wt,v});
            }
        }
    }
    return mstCost;
}

int main (){
    int V = 4;
    vector<pair<int,int>> adj[V];

    adj[0].push_back({1,10}); // v , wt
    adj[1].push_back({0,10});  // u(src) , wt

    adj[0].push_back({3,30});
    adj[3].push_back({0,30});

    adj[0].push_back({2,15});
    adj[2].push_back({0,15});

    adj[1].push_back({3,40});
    adj[3].push_back({1,40});

    adj[2].push_back({3,50});
    adj[3].push_back({2,50});

    cout<< "MST Cost : " << primsMST(V,adj) << endl;

    return 0;
}