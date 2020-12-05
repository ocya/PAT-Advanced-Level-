#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    string Name, Id;
    char Gender;
    int Grade;
};

bool MaleCompare( Node A, Node B );
bool FemaleCompare( Node A, Node B );
int main( int argc, const char *argv[] ){

    int N;
    cin >> N;
    Node Info;
    vector<Node> Male, Female;
    for( int i = 0; i < N; i++ ){
        cin >> Info.Name >> Info.Gender >> Info.Id >> Info.Grade;
        if( Info.Gender == 'M' ){
            Male.push_back( Info );
        }else{
            Female.push_back( Info );
        }
    }
    sort( Male.begin(), Male.end(), MaleCompare );
    sort( Female.begin(), Female.end(), FemaleCompare );
    bool isExistMale = false, isExistFemale = false;
    if( Female.size() == 0 ) cout << "Absent" << endl;
    else{
        isExistFemale = true;
        cout << Female[0].Name << ' ' << Female[0].Id << endl;
    }
    if( Male.size() == 0 ) cout << "Absent" << endl;
    else{
        isExistMale = true;
        cout << Male[0].Name << ' ' << Male[0].Id << endl;
    }
    if( isExistMale && isExistFemale ){
        cout << Female[0].Grade - Male[0].Grade << endl;
    }else cout <<  "NA" << endl;
    return 0;
}

bool MaleCompare( Node A, Node B ){
    return A.Grade < B.Grade;
}

bool FemaleCompare( Node A, Node B ){
    return A.Grade > B.Grade;
}
