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
    void addOrder(Order& o);
    vector<Order>& getOrdersExpress();
    vector<Order>& getOrdersNormal();
    void printCouriers();
    void printOrders();
    void printMap(map<int,vector<Order>> mapResult);
    void averageTime(vector<Order> ordersExpress);
    map<int,vector<Order>> efficientCourierVol();
    map<int,vector<Order>> efficientCourierWeight();
};


#endif //PROJECT_MANAGEORDERS_H
