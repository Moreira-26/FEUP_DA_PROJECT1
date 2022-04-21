#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H


class Order {
    static int idSt;
    int id;
    int weight;
    int volume;
    int price;
    int time;

public:
    /**
     * Constructor of class order
     * @param weight order's weight
     * @param volume order's volume
     * @param price order's price
     * @param time time needed to deliver the order
     */
    Order( int weight, int volume, int price,int time);

    /**
     * This method returns the order's weight
     * @return the weight value
     */
    int getWeight();

    /**
     * This method returns the order's volume
     * @return the volume value
     */
    int getVolume();

    /**
     * This method returns the order's price
     * @return the price value
     */
    int getPrice();

    /**
     * This method returns the order's time
     * @return the time value
     */
    int getTime();

    /**
     * This method returns the order's id
     * @return the id value
     */
    int getId();

};


#endif //PROJECT_ORDER_H
