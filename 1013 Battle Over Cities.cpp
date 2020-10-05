#include <iostream>
#include <vector>

#define MaxVertexNum 1001
#define Infinity 65536

using namespace std;

typedef int Vertex;

typedef struct GNode *MGraph;
struct GNode{
    int Nv, Ne;
    int G[MaxVertexNum][MaxVertexNum];
};

int N, M, K;
MGraph BuildGraph();
int Check( MGraph Graph, Vertex V );
vector<bool> isVisited( MaxVertexNum, false );
int main( int argc, const char *argv[] ){

    MGraph Graph = BuildGraph();
    vector<int> Ans;
    int City;
    for( int i = 0; i < K; i++ ){
        scanf( "%d", &City );
        City -= 1;
        Ans.push_back( Check( Graph, City ) );
        isVisited.assign( MaxVertexNum, false );
    }
    for( int i = 0; i < K; i++ )
        printf( "%d\n", Ans[i] - 1 );
    
    return 0;
}

void DFS( MGraph Graph, Vertex S ){
    isVisited[S] = true;
    for( Vertex V = 0; V < Graph->Nv; V++ ){
        if( !isVisited[V] && Graph->G[S][V] != Infinity )\
            DFS( Graph, V );
    }
}

int Check( MGraph Graph, Vertex V ){
    isVisited[V] = true;
    Vertex W;
    int Count = 0;
    for( W = 0; W < Graph->Nv; W++ ){
        if( !isVisited[W] ){
            DFS( Graph, W );
            Count++;
        }
    }
    return Count;
}

MGraph BuildGraph(){
    Vertex V1, V2;
    MGraph Graph = new GNode;

    cin >> N >> M >> K;
    Graph->Nv = N; Graph->Ne = M;

    for( V1 = 0; V1 < Graph->Nv; V1++ )
        for( V2 = 0; V2 < Graph->Nv; V2++ )
            Graph->G[V1][V2] = Infinity;
        

    for( int i = 0; i < M; i++ ){
        scanf( "%d %d", &V1, &V2 );
        V1 -= 1; V2 -= 1;
        Graph->G[V1][V2] = 1;
        Graph->G[V2][V1] = 1;
    }

    return Graph;
}
