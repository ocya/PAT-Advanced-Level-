#include <iostream>
#include <vector>


using namespace std;

int main( int argc, const char *argv[] ){

    vector<double> Odd( 3 );
    vector<int> Ans;
    vector<char> MapData = { 'W', 'T', 'L'};
    double TotalOdd = 1;
    double MaxOdd, TempOdd;
    int Idx;
    for( int i = 0; i < 3; i++ ){
        MaxOdd = 0; Idx = 0;
        for( int j = 0; j < 3; j++ ){
            cin >> TempOdd;
            if( MaxOdd < TempOdd ){
                MaxOdd = TempOdd;
                Idx = j;
            }
        }
        TotalOdd *= MaxOdd;
        Ans.push_back( Idx );
    }
    for( auto i:Ans )
        cout << MapData[i] << ' ';
    
    printf( "%.2lf", (TotalOdd*0.65 - 1)*2 );

    
    
    return 0;
}
