#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define MaxN 100000

using namespace std;

struct Node{
    char Letter;
    int Next;
};

int FindLength( vector<Node> &Info, int Address);

int main( int argc, const char *argv[] ){

    vector<Node> Info( MaxN );  
    int First, Second, N;
    cin >> First >> Second >> N;
    int Idx;
    for( int i = 0; i < N ; i++ ){
        cin >> Idx;
        cin >> Info[Idx].Letter >> Info[Idx].Next;
    }
    int Len1, Len2;
    Len1 = FindLength( Info, First );
    Len2 = FindLength( Info, Second );
    if( Len1 > Len2 ){
        int Difference = Len1 - Len2;
        for( int i = 0; i < Difference; i++ ){
            First = Info[First].Next;
        }
    }else{
       int Difference = Len2 - Len1;
        for( int i = 0; i < Difference; i++ ){
            Second = Info[Second].Next;
        } 
    }
    while( Second != First ){
        First = Info[First].Next;
        Second = Info[Second].Next;
    }
    if( First == -1 ) printf( "-1" );
    else printf( "%05d", First);

    return 0;
}

int FindLength( vector<Node> &Info, int Address){
    int Length = 0;
    while( Address != -1 && Length < MaxN){
        Length++;
        Address = Info[Address].Next;
    }
    return Length;
}

/*

1、计算单词长度，较长者指针先移动difference
2、比较address，移动Common指针
3、输出格式问题，-1 和 5位地址格式不同
*/



