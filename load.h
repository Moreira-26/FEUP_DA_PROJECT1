#ifndef PROJECT_LOAD_H
#define PROJECT_LOAD_H

#include "defs.h"
#include "manageOrders.h"
class Load {
    string FILE_ORDERS = "encomendas1.txt";
    string FILE_COURIER = "carrinhas.txt";

    /**
     * Method responsible for reading a courier from the order's file and creating each courier
     * @param manageOrders class where the courier will be stored
     */
    void couriers(ManageOrders &manageOrders);
    /**
     * Method responsible for reading an order from the order's file and creating each order
     * @param manageOrders class where the orders will be stored
     */
    void orders(ManageOrders &manageOrders);

public:
    /**
     *  Constructor of class Load
     */
    Load();
    /**
     * Method responsible for calling couriers() and orders
     * @param manageOrders
     */
    void run(ManageOrders &manageOrders);

};


#endif //PROJECT_LOAD_H
