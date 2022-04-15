#ifndef PROJECT_ORDER_H
#define PROJECT_ORDER_H


class Order {
    static int idSt;
    int id;
    bool isExpress;
    int weight;
    int volume;
    int price;
    int time;

public:
    Order(bool isExpress, int weight, int volume, int price,int time);
    int getIsExpress();
    int getWeight();
    int getVolume();
    int getPrice();
    int getTime();
    int getId();
    bool operator<(const Order o1);
};


#endif //PROJECT_ORDER_H
