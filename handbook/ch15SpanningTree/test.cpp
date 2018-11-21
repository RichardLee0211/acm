#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<string>

struct Edge{
    uint start;
    uint end;
    int weight;
    Edge(uint start, uint end, int weight):
        start{start}, end{end}, weight{weight}{
            // printf("construct\n");
        }
};

bool operator<(const Edge& lh, const Edge& rh){
    if(lh.weight<rh.weight)
        return true;
    else if(lh.weight>rh.weight)
        return false;
    else{
        if(lh.start < rh.start )
            return true;
        else if(lh.start > rh.start)
            return false;
        else{
            if(lh.end < rh.start)
                return true;
            else if(lh.end > rh.end)
                return false;
            else{
                // assert(0);  // repeated edges, the same weight, start and end
                return false;
            }
        }
    }
    assert(0); // should reach here;
    return true;
}

std::ostream &operator<<(std::ostream &os, const Edge& edge){
    os<<edge.start<<" "<<edge.end<<" "<<edge.weight<<"\n";
    return os;
}

struct Node{
    // uint ID;
    uint link; // the next element in the chain or the element itself if it's a representative
    uint size; // for each representive, the size of the corresponding set
    Node(uint ID):link{ID}, size{1}{}
};

std::set<Edge> edges;
std::vector<Node> nodes;

/* find the presentative of nodes[x] */
uint find(uint x){
    if(x>=nodes.size()) return -1;
    while(x!=nodes[x].link) x=nodes[x].link;
    return x;
}
/* if two nodes are the same presentative */
bool same(uint a, uint b){
    return find(a) == find(b);
}

void swap(uint &a, uint &b){
    uint temp = a;
    a = b;
    b = temp;
}

/* unit two points */
void unit(uint a, uint b){
    a = find(a);
    b = find(b);
    if(nodes[a].size < nodes[b].size) swap(a, b);
    nodes[a].size += nodes[b].size;
    nodes[b].link = a;
}

int main(int argc, char* argv[]){
    if(argc<2){
        // TODO_3: make error looks like error in terminal
        fprintf(stderr, "usage: ./%s input_file\n", argv[0]);
        return -1;
    }


    FILE *input_fd = fopen(argv[1], "r");
    if(!input_fd){
        fprintf(stderr, "can't open file: %s\n", argv[1]);
        return -1;
    }

    /* parse file and initial edges */
    char * line=NULL;
    size_t len=0;
    while(getline(&line, &len, input_fd)!=-1){
        if(line[0]=='#' || line[0]=='\n') continue; // TODO_3: the empty line could have some spaces
        char* point1 = strtok(line, " \n");
        char* point2 = strtok(NULL, " \n");
        char* weight = strtok(NULL, " \n");
        uint ipt1  = atoi(point1);
        uint ipt2 = atoi(point2);
        int iwt = atoi(weight);
        edges.insert({ipt1, ipt2, iwt});
    }

    /* get the nodes_max
     * TODO_3: may bring it to initial loop of edges
     */
    uint nodes_max{0};
    for(auto i: edges){
        if(i.start > nodes_max){
            nodes_max = i.start;
        }
        if(i.end > nodes_max){
            nodes_max = i.end;
        }
    }

    /*
     * initial nodes
     * nodes ID start with 1 but nodes[0] should not used for anything, just place holder
     * to make nodes[ID] works
     */
    for(uint i{0}; i<=nodes_max; ++i){
        nodes.push_back({i});
    }

    /* fetch the minEdge and if two points don't have the same presentive, add it to minSpaning tree, and unit them */
    std::vector<Edge> minSpanTree;
    for(uint i{0}; i<nodes_max-1; ){
        auto minEdge=edges.begin();
        if(!same(minEdge->start, minEdge->end)){
            minSpanTree.push_back(*minEdge);
            unit(minEdge->start, minEdge->end);
            ++i;
        }
        edges.erase(minEdge);
    }

    std::cout<<"min spanning tree: \n";
    for(auto i:minSpanTree){
        std::cout<<i;
    }
    printf("\n");
    /*
    */

}
