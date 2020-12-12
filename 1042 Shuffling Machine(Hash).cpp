#include <iostream>
#include <vector>
#include <string>

#define cardCounts 54

using namespace std;


int main() {

    int N;
    cin >> N;
    vector<string> color( 4 );
    color[0] = "S"; color[1] = "H"; color[2] = "C"; color[3] = "D"; ;
    vector<string> initialCardPermuation;
    for( int i = 0; i < 4; i++ ){
        for( int j = 1; j <= 13; j++ ){
            initialCardPermuation.push_back( color[i] + to_string( j ) );
        }
    }
    initialCardPermuation.push_back( "J1" ); initialCardPermuation.push_back( "J2" );


    vector<int> permutation( cardCounts );
    for( int i = 0; i < cardCounts; i++ ){
        cin >> permutation[i];
    }
    vector<string> resultCardPermuation( cardCounts );
    for( int i = 0; i < N; i++ ){
        for( int j = 0; j < cardCounts; j++ ){
            resultCardPermuation[permutation[j] - 1] = initialCardPermuation[ j ];
        }
        initialCardPermuation = resultCardPermuation;
    }


    for( int i = 0; i < cardCounts; i++ ){
        if( i != 0 ) cout << ' ';
        cout << resultCardPermuation[i];
    }

    return 0;
}
