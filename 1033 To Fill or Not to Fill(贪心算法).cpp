#include <iostream>
#include <vector>
#include <algorithm>

#define Infinity 65536

using namespace std;

struct gasStation{
    double price, distance;
};

bool Compare( gasStation A, gasStation B );

int main( int argc, const char *argv[] ){

    double Cmax, D, Davg;
    int N;
    cin >> Cmax >> D >> Davg >> N;
    
    vector<gasStation> Station( N+1 );
    gasStation temp;
    for( int i = 1; i <= N; i++ ){
        cin >> temp.price >> temp.distance;
        Station[i] = temp;
    }
    Station[0] = { 0.0, D };
    sort( Station.begin(), Station.end(), Compare );

    double currentDist = 0.0, currentPrice = 0.0, maxReachableDistance = 0.0, totalPrice = 0.0, leftDisance = 0.0;
    if( Station[0].distance != 0 ){
        cout << "The maximum travel distance = 0.00";
        return 0;
    }else{
        currentPrice = Station[0].price;
    }
    while( currentDist !=  D ){
        maxReachableDistance = currentDist + Cmax * Davg;
        double minPrice = Infinity, minPriceDistance = 0;
        bool isReachable = false, isUpdated = false;
        for( int i = 1; i <= N && Station[i].distance <= maxReachableDistance; i++ ){
            if( Station[i].distance <= currentDist ) continue;
            isReachable = true;
            if( currentPrice > Station[i].price){
                isUpdated = true;
                totalPrice += (Station[i].distance - currentDist - leftDisance ) * currentPrice / Davg;
                leftDisance = 0;
                currentPrice = Station[i].price;
                currentDist = Station[i].distance;
                break;
            }else{
                if( Station[i].price < minPrice ){
                    minPrice = Station[i].price;
                    minPriceDistance = Station[i].distance;
                }
            }
        }
        if( isReachable && !isUpdated ){
            totalPrice +=( Cmax - leftDisance / Davg ) * currentPrice;
            leftDisance = Cmax * Davg - ( minPriceDistance - currentDist );
            currentDist = minPriceDistance;
            currentPrice = minPrice;   
        }
        if( !isReachable ){
            currentDist += Cmax * Davg;
            printf("The maximum travel distance = %.2f", currentDist );
            return 0; 
        }

    }
    printf( "%.2f", totalPrice );
    return 0;
}

bool Compare( gasStation A, gasStation B ){
    return A.distance < B.distance;
}
