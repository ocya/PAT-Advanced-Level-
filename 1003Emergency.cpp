#include <iostream>
#include <vector>


#define MaxVertexNum 501
#define Infinity 65536

using namespace std;

typedef struct GNode *MGraph;
struct GNode{
    int Nv, Ne;
    int G[MaxVertexNum][MaxVertexNum];
    int Count[MaxVertexNum];
};

MGraph BuildMGraph();
void Dijkstra( MGraph Graph );
int S, D;

vector<bool> isCollected( MaxVertexNum, false );
vector<int> Distance( MaxVertexNum, Infinity );
vector<int> TeamCount( MaxVertexNum );
vector<int> SolutionCount( MaxVertexNum, 1 );
int main( int argc, const char *argv[] ){

    MGraph Graph = BuildMGraph();
    Dijkstra( Graph );
    cout << SolutionCount[D] << ' ' << TeamCount[D];
    return 0;
}

MGraph BuildMGraph(){
    int N, M;
    cin >> N >> M >> S >> D;
    MGraph Graph = new GNode;
    Graph->Ne = M; Graph->Nv = N;
    int V, W;
    for( V = 0; V < Graph->Nv; V++ )
        for( W = 0; W < Graph->Nv; W++ )
            Graph->G[V][W] = Infinity;
    for( V = 0; V < Graph->Nv; V++ )
        cin >> Graph->Count[V];
    
    int TmpDist;
    for( int i = 0; i < Graph->Ne; i++ ){
        scanf( "%d %d %d", &V, &W, &TmpDist );
        Graph->G[V][W] = Graph->G[W][V] = TmpDist;
    }      
            
    return Graph;
}

int FindMinDistVertex( MGraph Graph ){
    int V, MinV;
    int MinDist = Infinity;
    for( V = 0; V < Graph->Nv; V++ ){
        if( Distance[V] < MinDist && !isCollected[V]){
            MinDist = Distance[V];
            MinV = V;
        }
    }

    if( MinDist == Infinity ) MinV = -1;
    return MinV;
}

void Dijkstra( MGraph Graph ){
    int V, W;
    TeamCount[S] = Graph->Count[S];
    for( W = 0; W < Graph->Nv; W++ ){
        if( Graph->G[S][W] != Infinity )
            TeamCount[W] = TeamCount[S] + Graph->Count[W] ; 
        Distance[W] = Graph->G[S][W];
    }
            


    isCollected[S] = true;
    Distance[S] = 0;

    while( 1 ){
        V = FindMinDistVertex( Graph );
        if( V == -1 ) break;
        isCollected[V] = true;

        for( W = 0; W < Graph->Nv; W++ ){
            if( Graph->G[V][W] != Infinity && !isCollected[W] ){
                if( Distance[W] > Distance[V] + Graph->G[V][W] ){
                    SolutionCount[W] = SolutionCount[V];
                    Distance[W] = Distance[V] + Graph->G[V][W];
                    TeamCount[W] = TeamCount[V] + Graph->Count[W];
                }else if( Distance[W] == Distance[V] + Graph->G[V][W]){
                    SolutionCount[W] += SolutionCount[V];
                    if( TeamCount[W] < TeamCount[V] + Graph->Count[W] ){
                        TeamCount[W] = TeamCount[V] + Graph->Count[W];
                    }
                }
            }
        } 
    }
}
