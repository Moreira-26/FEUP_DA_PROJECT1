#include <iostream>
#include "load.h"
#include "manageOrders.h"


int main() {
    Load load;
    ManageOrders mO;

    load.run(mO);
    cout << "VOLUME" << endl;
    mO.printMap(mO.efficientCourierVol());
    cout << endl;
    cout << endl;
    cout << "WEIGHT"<<endl;
    mO.printMap(mO.efficientCourierWeight());
    return 0;
}
