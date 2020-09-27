#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int TimeConvert( string Time );
int main( int argc, const char *argv[] ){
    
    int N;
    cin >> N;
    map<int, string> SMap;
    map<int, string> EMap;

    int StartTime, EndTime;
    string StringStartTime, StringEndTime, TempId;
    int MinTime = 24*3600, MaxTime = 0;

    for( int i = 0; i < N; i++ ){
        cin >> TempId >> StringStartTime >> StringEndTime;
        StartTime = TimeConvert( StringStartTime );
        EndTime = TimeConvert( StringEndTime );
        SMap[StartTime] = TempId;
        EMap[EndTime] = TempId;
        if( MinTime > StartTime ) MinTime = StartTime;
        if( MaxTime < EndTime ) MaxTime = EndTime;     
    }
    cout << SMap[MinTime] << ' ' << EMap[MaxTime];

    return 0;

}

int TimeConvert( string Time ){
    int Hour, Minute, Second;
    string H, M, S;
    H = Time.substr( 0, 2 ); Time = Time.substr( 3 );
    M = Time.substr( 0, 2 ); Time = Time.substr( 3 );
    S = Time;
    Hour = stoi( H ); Minute = stoi( M ); Second = stoi( S );
    Second += Hour*3600 + Minute*60;
    return Second;
}


 
