#ifndef PROJECT_COURIER_H
#define PROJECT_COURIER_H

#include "defs.h"
#include "order.h"

class Courier {
    static int idSt;
    int id;
    int volMax;
    int weightMax;
    int fee;
    vector<Order> orders;

public:
    Courier(int volMax, int weightMax, int fee );
    int getId();
    int getVolMax();
    int getWeightMax();
    int getFee();
    vector<Order> getOrders();
    void addOrder(Order &order);
};


#endif //PROJECT_COURIER_H
