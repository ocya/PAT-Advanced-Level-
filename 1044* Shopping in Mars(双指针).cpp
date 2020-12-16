#include <iostream>
#include <vector>


using namespace std;


class Node{   
    public:
    int idxFirst, idxSecond;
    Node( int i, int j ): idxFirst(i), idxSecond(j){ }
};



int main( int argc, const char *argv[] ){

    int N, M;
    cin >> N >> M;
    vector<Node> Answer;
    vector<int> Value( N );
    for( int i = 0; i < N; i++ ){
        scanf( "%d", &Value[i] );       
    }
    int Sum = 0, minGap = 1001;
    for( int i = 0, j = 0; i < N && j <= N; ){
        if( Sum < M ){
            Sum += Value[j++];
        }else{
            if( Sum == M ){
                printf( "%d-%d\n", i+1, j );
                minGap = -1;
            }else if( Sum < minGap ){
                minGap = Sum;
                Answer.clear();
                Answer.push_back( Node( i+1, j ) );
            }else if( Sum == minGap ){
                Answer.push_back( Node( i+1, j ) );
            }
            Sum -= Value[i++];
        }
    }

    for( int i = 0; i < Answer.size(); i++ ){
        cout << Answer[i].idxFirst << '-' << Answer[i].idxSecond << endl; 
    }

    return 0;
}
