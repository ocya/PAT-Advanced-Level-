#include <iostream>
#include <map>
#include <string>
#include <vector>


#define MaxVertexNum 2001

using namespace std;

typedef struct GNode *MGraph;
struct GNode{
    int Nv, Ne;
    int G[MaxVertexNum][MaxVertexNum];
    int Weight[MaxVertexNum];
};
map<string, int> stringToInteger;
map<int,string> integerToString;
map<string, int> Ans;
vector<bool> isVisited( MaxVertexNum, false );
int Idx = 0;
int N, K;

MGraph BuildMGraph( );
void DFS( MGraph Graph, int V, int &VertexCount, int &TotalWeight, int &HeadVertex );
int main( int argc, const char *argv[] ){
    
    cin >> N >> K;
    MGraph Graph = BuildMGraph();
    int V, VertexCount, TotalWeight, HeadVertex;
    for( V = 1; V <= Graph->Nv; V++ ){
        if( !isVisited[V] ){
            VertexCount = 0; TotalWeight = 0; HeadVertex = V;
            DFS( Graph, V, VertexCount, TotalWeight, HeadVertex );
            if( TotalWeight > K && VertexCount > 2 ){
                Ans[ integerToString[HeadVertex] ] = VertexCount;
            }
        }
    }

    cout << Ans.size() << endl;
    for( auto i = Ans.begin(); i != Ans.end(); ++i ){
        cout << i->first << ' ' << i->second << endl;
    }

    return 0;
}


int stringToIntegerFun( string s ){
    if( stringToInteger[s] == 0 ){
        stringToInteger[s] = ++Idx;
        integerToString[Idx] = s;
    }
    return stringToInteger[s];
}

MGraph BuildMGraph( ){
    MGraph Graph = new GNode;
    Graph->Ne = N;
    string Name1, Name2;
    int Time;
    int V, W;
    for( V = 1; V <= MaxVertexNum; V++ ){
        Graph->Weight[V] = 0;
        for( W = 1; W <= MaxVertexNum; W++ ){
            Graph->G[V][W] = 0;
        }
    }
        
    for( int i = 0; i < Graph->Ne; i++ ){
        cin >> Name1 >> Name2 >> Time;
        V = stringToIntegerFun( Name1 );
        W = stringToIntegerFun( Name2 );
        Graph->G[V][W] += Time;
        Graph->G[W][V] += Time;
        Graph->Weight[V] += Time;
        Graph->Weight[W] += Time;
    }
    Graph->Nv = Idx; 

    return Graph;
    
}


void DFS( MGraph Graph, int V, int &VertexCount, int &TotalWeight, int &HeadVertex ){
    isVisited[V] = true;
    VertexCount++;
    if( Graph->Weight[V] > Graph->Weight[HeadVertex] )
        HeadVertex = V;

    for( int W = 1; W <= Graph->Nv; W++ ){
        if(Graph->G[V][W] != 0 ){      
            TotalWeight += Graph->G[V][W];
            Graph->G[V][W] = 0; Graph->G[W][V] = 0;
            if( !isVisited[W] )   
                DFS( Graph, W, VertexCount, TotalWeight, HeadVertex );   
        }
    }
    

}
