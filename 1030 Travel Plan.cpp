#include <iostream>
#include <vector>
#include <stack>

#define maxVertexNum 501
#define infinity 65536

using namespace std;

typedef struct ENode *Edge;
struct ENode{
    int V,W;
    int Dist,Cost;
};

typedef struct GNode *MGraph;
struct GNode{
    int Nv, Ne, S, D;
    int Dist[maxVertexNum][maxVertexNum];
    int Cost[maxVertexNum][maxVertexNum];
};

MGraph BuildMGraph();
void Dijkstra( MGraph Graph, int S );
vector<int> Dist( maxVertexNum, infinity );
vector<int> Cost( maxVertexNum, infinity );
vector<int> Path( maxVertexNum, -1 );
vector<bool> isVisited( maxVertexNum, false );
int main( int argc, const char *argv[] ){

    MGraph Graph = BuildMGraph();
    Dijkstra( Graph, Graph->S );
    //cout << Dist[Graph->D] << ' ' << Cost[Graph->D];
    int D = Graph->D;
    stack<int> pathDisplay;
    while( Path[D] != -1 ){
        pathDisplay.push( D );
        D = Path[D];
    }
    pathDisplay.push( Graph->S );
    while( !pathDisplay.empty() ){
        cout << pathDisplay.top() << ' ';
        pathDisplay.pop();
    }
    cout << Dist[Graph->D] << ' ' << Cost[Graph->D];
    return 0;
}

int FindMinDistVertex( MGraph Graph ){
    int MinV = -1;
    int MinDist = infinity;
    for( int V = 0; V < Graph->Nv; V++ ){
        if( !isVisited[V] && Dist[V] < MinDist ){
            MinDist = Dist[V];
            MinV = V;
        }
    }
    
    return MinV;
}

void Dijkstra( MGraph Graph, int S ){
    int V;
    for( V = 0; V < Graph->Nv ; V++ ){
        Dist[V] = Graph->Dist[S][V];
        Cost[V] = Graph->Cost[S][V];
        if( Dist[V] != infinity )
            Path[V] = S;
    } 
    Dist[S] = 0; Cost[S] = 0;
    isVisited[S] = true;

    while(1){
        V = FindMinDistVertex( Graph );
        if( V == -1 )
            break;
        isVisited[V] = true;

        for( int W = 0; W < Graph->Nv; W++ ){
            if( Graph->Dist[V][W] != infinity && !isVisited[W] ){
                if(Dist[W] > Dist[V] + Graph->Dist[V][W] ){
                    Dist[W] = Dist[V] + Graph->Dist[V][W];
                    Cost[W] = Cost[V] + Graph->Cost[V][W];
                    Path[W] = V;
                }else if( Dist[W] == Dist[V] + Graph->Dist[V][W] && Cost[W] > Cost[V] + Graph->Cost[V][W]){
                    Cost[W] = Cost[V] + Graph->Cost[V][W];
                    Path[W] = V;
                }
            }
        }
    }
}

MGraph BuildMGraph(){

    MGraph Graph = new GNode;
    int N, M, S, D;
    cin >> N >> M >> S >> D;
    Graph->Nv = N; Graph->Ne = M;
    Graph->S = S; Graph->D = D;
    for( int i = 0; i < Graph->Nv; i++ )
        for( int j = 0; j < Graph->Nv; j++ ){
            Graph->Dist[i][j] = infinity;
            Graph->Cost[i][j] = infinity;
        }
    int V, W, Cost, Dist;
    for( int i = 0 ; i < Graph->Ne; i++ ){
        cin >> V  >> W  >> Dist >> Cost;
        Graph->Cost[V][W] = Cost;
        Graph->Cost[W][V] = Cost;
        Graph->Dist[V][W] = Dist;
        Graph->Dist[W][V] = Dist;
    }

    return Graph;
    
}
