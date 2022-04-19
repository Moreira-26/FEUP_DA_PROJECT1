#ifndef PROJECT_MANAGEORDERS_H
#define PROJECT_MANAGEORDERS_H

#include "defs.h"
#include "courier.h"

class ManageOrders {
    vector<Courier> couriers;
    vector<Order> orders;

public:
    ManageOrders();
    void addCourier(Courier& c);
    void addOrder(Order& o);
    vector<Order>& getOrders();
    Courier& getCourierId(int id);
    void printMapTime(map<int,vector<Order>> mapResult);
    void printMapCourier(map<int,vector<Order>> mapResult);
    void printMapProfit(map<int,vector<Order>> mapResult);
    void averageTime();
    map<int,vector<Order>> efficientCourier();
    map<int,vector<Order>> efficientProfit();
    void menu();
};


#endif //PROJECT_MANAGEORDERS_H
