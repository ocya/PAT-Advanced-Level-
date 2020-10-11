#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string Double( string S );
int main( int argc, const char *argv[] ){

    string S;
    getline( cin, S );
    vector<int> OriginalMap(10), DoubleMap(10);
    for( int i = 0; i < S.length(); i++ )
        OriginalMap[S[i] - '0']++;
    string Temp =  Double( S );

    for( int i = 0; i < Temp.length(); i++ )
        DoubleMap[Temp[i] - '0']++;
    if( OriginalMap == DoubleMap ) cout << "Yes\n";
    else cout << "No\n";
    cout << Temp;
    return 0;
}

string Double( string S ){
    int Digit;
    string DoubleStr;
    reverse( S.begin(), S.end() );
    bool Carrier = false;
    for( int i = 0; i < S.length(); i++ ){
        Digit = S[i] - '0';
        Digit *= 2;
        if( Carrier ){
            Digit += 1;
            Carrier = false;
        } 
        if( Digit >= 10 ){
            Carrier = true;
            Digit -= 10;
        } 
        DoubleStr += to_string( Digit );
    }
    //最后进位不要忘记
    if( Carrier ) DoubleStr += '1';
    reverse( DoubleStr.begin(), DoubleStr.end() );
    
    return DoubleStr;
}
