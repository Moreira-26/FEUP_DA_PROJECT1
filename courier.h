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

public:
    /**
     * Constructor of class Courier
     * @param volMax courier's max volume
     * @param weightMax courier's max weight
     * @param fee courier's fee
     */
    Courier(int volMax, int weightMax, int fee );

    /**
     * This method returns the courier's id
     * @return the id value
     */
    int getId();

    /**
     * This method returns the courier's max volume
     * @return the max volume value
     */
    int getVolMax();

    /**
     * This method returns the courier's max weight
     * @return the max weight value
     */
    int getWeightMax();

    /**
     * This method returns the courier's fee
     * @return the fee value
     */
    int getFee();

};


#endif //PROJECT_COURIER_H
