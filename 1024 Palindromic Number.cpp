#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


bool isPalindromicNumber( string S ){
    int len = S.length();
    int i;
    for( i = 0; i < len / 2; i++ ){
        if( S[i] != S[len-1-i] )
            break;
    }
    return (i == len/2) ? true : false;
}

string StrPlus( string S1,string S2){
    int Carrier = 0;
    int Digit1, Digit2, Sum;
    reverse( S1.begin(), S1.end());
    reverse( S2.begin(), S2.end());
    string Result;
    for( int i = 0; i < S1.length(); i++ ){
        Digit1 = S1[i] - '0';
        Digit2 = S2[i] - '0';
        Sum = Digit1 + Digit2 + Carrier;
        Carrier = Sum/10;
        Result += (Sum%10 + '0');
    }
    if( Carrier != 0 )
        Result += (Carrier+ '0');
    reverse( Result.begin(), Result.end());

    return Result;
}

int main( int argc, const char *argv[] ){

    string NStr, TmpNStr;
    int K;
    cin >> NStr >> K;
    int Step;
    int ON, RN;

    for(Step = 0; Step < K; Step++ ){
        if( !isPalindromicNumber(NStr)){
            TmpNStr = NStr;
            reverse( TmpNStr.begin(), TmpNStr.end());
            NStr = StrPlus( NStr, TmpNStr);
        }else {
            cout << NStr << endl << Step;
            break;
        }
    }
    if( Step == K )
        cout << NStr << endl << Step;
    
    return 0;
}
/*
1、判断回文数
2、累加操作
*/




