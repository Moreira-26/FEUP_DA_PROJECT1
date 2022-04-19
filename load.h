#ifndef PROJECT_LOAD_H
#define PROJECT_LOAD_H

#include "defs.h"
#include "manageOrders.h"
class Load {
    string FILE_ORDERS = "encomendas1.txt";
    string FILE_COURIER = "carrinhas.txt";

    void couriers(ManageOrders &manageOrders);
    void orders(ManageOrders &manageOrders);

public:
    Load();
    void run(ManageOrders &manageOrders);

};


#endif //PROJECT_LOAD_H
