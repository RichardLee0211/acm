#include<iostream>
#include<tuple>
#include<vector>

int main(){
    /* test of std::tie and std::tuple
    std::tuple<uint, uint, uint> tup{3, 4, 5};
    uint first, second, third;
    std::tie(first, second, third) = tup;
    printf("%u, %u, %u", first, second, third);
    */

    int n{0}; // the number of nodes
    std::vector<std::tuple<int, int, int>> edges{}; // edges with point1, point2, weight
    scanf("%*[^\n]\n", NULL);
    scanf("%d\n", &n);
    while(!feof(stdin)){
        int point1{0}, point2{0}, weight{0};
        scanf("%d %d %d\n", &point1, &point2, &weight);
        if(point1==0 ||  point2==0) break; // the loop checker need to actual touch EOF byte to function, creating a empty loop
        edges.push_back(std::make_tuple(point1, point2, weight));
    }

    for(auto e: edges){
        printf("%d %d %d\n", std::get<0>(e), std::get<1>(e), std::get<2>(e));
    }

    /* this code from handbook data come from a very friendly way
     * in undirect graph, point1 and point2 is commutative
     * it also use INF, which can't be UINT_MAX, INF need to satisfied INF+1=INF, UINT_MAX+1=0
     */
    uint *distance = (uint*)malloc((n+1)*sizeof(uint)); // distance[0] is not used
    int x = 1;
    for (int i = 1; i <= n; i++) distance[i] = INT_MAX;
    distance[x] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            std::tie(a, b, w) = e;
            distance[b] = std::min(distance[b], distance[a]+w);
        }
    }

    for(int i{0}; i<=n; ++i){
        printf("%d ", distance[i]);
    }
}
