class Graph {
    public:
    long long size;
    vector<vector<pair<int,int>>> edges;
    vector<vector<long long>> distances;
    Graph (long long size){
        this->size = size;
        edges.resize(27);
        distances.resize(27, vector<long long>(27, INT_MAX));
    }

    void addEdge(long long origin, long long target, long long capacity){
        

        edges[origin].emplace_back(capacity, target);
    }

    void dijkstra(long long source){
        priority_queue<pair<long long, long long>, vector<pair<long long,long long>>, greater<pair<long long, long long>> > pq;
        distances[source][source] = 0;
        pq.emplace(0, source);

        while (!pq.empty()) {
            long long flow = pq.top().first;
            long long curr = pq.top().second;
            pq.pop();
            if (flow > distances[source][curr]) continue;

            for (auto yea : edges[curr]) {
                if (distances[source][curr] + yea.first < distances[source][yea.second]) {
                    distances[source][yea.second] = distances[source][curr] + yea.first;
                    pq.emplace(distances[source][yea.second], yea.second);
                }
            }
        }
    }
    
    
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        Graph myGraph(original.size());
        for (long long i=0; i<original.size(); i++){
            myGraph.addEdge(original[i] -  96, changed[i] -  96, cost[i]);
        }
        long long total = 0;
        for (long long i=0; i<source.length(); i++){
            if (source[i] == target[i]){
                continue;
            } else {
                if (myGraph.distances[source[i]-  96][source[i]-  96] != 0){
                    myGraph.dijkstra(source[i] - 96);
                }
                if (myGraph.distances[source[i] - 96][target[i] - 96] == INT_MAX){
                    return -1;
                } else {
                    total +=myGraph.distances[source[i] - 96][target[i] - 96];
                }
            }
        }
        return total;
    }
};
