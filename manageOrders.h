#ifndef PROJECT_MANAGEORDERS_H
#define PROJECT_MANAGEORDERS_H

#include "defs.h"
#include "courier.h"

class ManageOrders {
    vector<Courier> couriers;
    vector<Order> ordersNormal;
    vector<Order> ordersExpress;

public:
    ManageOrders();
    void addCourier(Courier& c);
    void addOrder(Order &o);
    void printCouriers();
    void printOrders();
};


#endif //PROJECT_MANAGEORDERS_H
