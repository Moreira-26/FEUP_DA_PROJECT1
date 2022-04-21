#ifndef PROJECT_MANAGEORDERS_H
#define PROJECT_MANAGEORDERS_H

#include "defs.h"
#include "courier.h"

class ManageOrders {
    vector<Courier> couriers;
    vector<Order> orders;

public:
    /**
     * Constructor of class manageOrders
     */
    ManageOrders();

    /**
     * Method responsible for adding a courier
     * @param c courier added
     */
    void addCourier(Courier& c);

    /**
     * Method responsible for adding a order
     * @param o order added
     */
    void addOrder(Order& o);

    /**
     * Method responsible for returning the courier with the given id
     * @param id id of the courier
     * @return courier with the given id
     */
    Courier& getCourierId(int id);

    /**
     * Method responsible for printing the map with the couriers used in the algorithm efficient courier
     * @param mapResult map with the id and orders associated
     */
    void printMapCourier(map<int,vector<Order>> mapResult);

    /**
     *Method responsible for printing the map with the couriers used in the algorithm efficient profit
     * @param mapResult map with the id and orders associated
     */
    void printMapProfit(map<int,vector<Order>> mapResult);

    /**
     * Method responsible for printing and calculating the  best average time taken by each express order
     */
    void averageTime();

    /**
     * Method responsible for calculating the most efficient way of using the couriers
     * @return
     */
    map<int,vector<Order>> efficientCourier();

    /**
     * Method responsible for calculating the most profitable way of delivering the highest number of orders possible
     */
    map<int,vector<Order>> efficientProfit();

    /**
     * Method responsible for printing the menu to the console
     */
    void menu();
};


#endif //PROJECT_MANAGEORDERS_H
