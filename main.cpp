#include <iostream>
#include "load.h"
#include "manageOrders.h"


int main() {
    Load load;
    ManageOrders mO;

    load.run(mO);

    cout << "PRICE"<<endl;
    mO.printMap(mO.efficientProfit());
    return 0;
}
