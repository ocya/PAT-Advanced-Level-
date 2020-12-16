#include <iostream>
#include <vector>

using namespace std;

int main( int argc, const char *argv[] ){

    int N;
    cin >> N;
    vector<int> Distance( N+1 );
    int tempDistance, sumDistance ;
    Distance[0] = 0;
    for( int i = 1;i <= N; i++ ){
        scanf( "%d", &tempDistance );
        Distance[i] = Distance[i-1] + tempDistance;
    }
    sumDistance = Distance[N];
    int M;
    cin >> M;
    int start, end;
    int gapDistance1, gapDistance2;
    for( int i = 0;i < M; i++ ){
        scanf( "%d %d", &start, &end );
        start -= 1; end -=  1;
        if( start > end ) swap( start, end );
        gapDistance1 = Distance[end] - Distance[start];
        gapDistance2 = sumDistance - gapDistance1;
        printf( "%d\n", ( gapDistance1 < gapDistance2 ? gapDistance1 : gapDistance2 ) );
    }

    return 0;
}
