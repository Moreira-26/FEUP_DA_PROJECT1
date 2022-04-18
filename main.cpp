#include <iostream>
#include "load.h"
#include "manageOrders.h"


int main() {
    Load load;
    ManageOrders mO;

    load.run(mO);

    mO.menu();
    return 0;
}
