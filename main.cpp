#include <iostream>
#include "load.h"
#include "manageOrders.h"


int main() {
    Load load;
    ManageOrders mO;

    load.run(mO);

    cout << "WEIGHT"<<endl;
    mO.printMap(mO.efficientCourier());
    return 0;
}
