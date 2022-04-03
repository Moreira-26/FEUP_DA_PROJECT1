//
// Created by moreira on 03/04/22.
//

#include "manageOrders.h"

ManageOrders::ManageOrders() {

}

void ManageOrders::addCourier(Courier &c) {
    couriers.push_back(c);
}

void ManageOrders::addOrder(Order &o) {
    if(o.getIsExpress()){
        ordersExpress.push_back(o);
    }else{
        ordersNormal.push_back(o);
    }
}

void ManageOrders::printCouriers() {
    for(Courier& c: couriers){
        cout << c.getId() << endl;
    }
}

void ManageOrders::printOrders() {
    for(Order& o:ordersNormal){
        cout << o.getId() << endl;
    }
    cout << endl;
    cout << "EXPRESS" << endl;
    cout << endl;
    for(Order& o: ordersExpress){
        cout << o.getId() << endl;
    }
}




