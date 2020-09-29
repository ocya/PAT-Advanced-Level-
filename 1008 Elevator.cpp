#include <iostream>
#include <string>


using namespace std;

int main( int argc, const char *argv[] ){

    int N;
    int CurrentLevel, TargetLevel, Difference;
    int Time = 0;
    cin >> N;
    CurrentLevel = 0;
    for( int i = 0; i < N; i++ ){
        cin >> TargetLevel;
        Difference = TargetLevel - CurrentLevel;
        Time +=  (Difference > 0) ? Difference * 6 : -Difference * 4 ;
        CurrentLevel = TargetLevel;
    }
    Time += N * 5;
    cout << Time;
    
    return 0;
}
