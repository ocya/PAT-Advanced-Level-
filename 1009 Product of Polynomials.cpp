#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){
    vector<double> Coefficients( 1001 );
    vector<double> Ans( 2001, 0 );
    vector<int> Idx;
    int N;
    cin >> N;
    int Exp;
    double Coe;
    for( int i = 0; i < N; i++ ){
        cin >> Exp >> Coe;
        Coefficients[Exp] = Coe;
    }
    cin >> N;
    for( int i = 0; i < N; i++ ){
        cin >> Exp >> Coe;
        for( int j = 0; j < 1001; j++ ){
            if( abs(Coefficients[j] - 0) > 0.0000001 )
                Ans[Exp+j] += Coe * Coefficients[j];
        }
    }

    for( int i = 0; i < 2001; i++ ){
        if( abs(Ans[i] - 0) > 0.0000001 ){
            Idx.push_back( i );
        }
    }
    cout << Idx.size();
    reverse( Idx.begin(), Idx.end() );
    for( auto i:Idx ){
        printf( " %d %.1lf", i, Ans[i] );
    }
    return 0;
}
