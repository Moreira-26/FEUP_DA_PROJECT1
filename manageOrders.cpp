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

vector <Order> &ManageOrders::getOrdersExpress() {
    return this->ordersExpress;
}

vector <Order> &ManageOrders::getOrdersNormal() {
    return this->ordersNormal;
}

/////Prints
void ManageOrders::printCouriers() {
    for(Courier& c: couriers){
        cout << c.getId() << endl;
    }
}

void ManageOrders::printOrders() {
    for(Order& o: ordersExpress){
        cout << o.getTime() << endl;
    }
}

void ManageOrders::printMap(map<int,vector<Order>> mapResult) {
    int count = 0;
    for(pair<int,vector<Order>> p:mapResult){
        cout << "id: " << p.first << " ";
        cout << "Encomendas: ";
        for(Order o: p.second){
            cout << o.getId() << " ";
            count++;
        }
        cout << endl;
    }

    cout << "Nº estafetas: " << mapResult.size() << endl;
}


////Compare
struct compareOrdersTime{
    bool operator()(Order o1,Order o2) {
        return (o1.getTime() < o2.getTime());
    }
};

struct compareOrdersVol{
    bool operator()(Order o1,Order o2) {
        return (o1.getVolume() < o2.getVolume());
    }
};

struct compareOrdersWeight{
    bool operator()(Order o1,Order o2) {
        return (o1.getWeight() < o2.getWeight());
    }
};

struct compareCouriersVol{
    bool operator()(Courier c1, Courier c2){
        return (c1.getVolMax() > c2.getVolMax());
    }
};

struct compareCouriersWeight{
    bool operator()(Courier c1, Courier c2){
        return (c1.getWeightMax() > c2.getWeightMax());
    }
};
///Algorithms
void ManageOrders::averageTime(vector <Order> ordersExpress) {
    int timeTotal = 0;
    int time = 0;
    int num = 0;
    sort(ordersExpress.begin(), ordersExpress.end(), compareOrdersTime());
    while(((timeTotal + ordersExpress.front().getTime())  < (3600 * 8)) && !ordersExpress.empty()){
        timeTotal += ordersExpress.front().getTime();
        time += timeTotal + ordersExpress.front().getTime();
        num++;
        cout << "OrderId:" <<  ordersExpress.front().getId() << " min: " << (time/num) / 60 << " " << "sec: " << (time/num) % 60 << endl;
        ordersExpress.erase(ordersExpress.begin());
    }
}

int sumVol(vector<Order> orders){
    int count  = 0;
    for(Order o : orders){
        count += o.getVolume();
    }
    return count;
}

int sumWeight(vector<Order> orders){
    int count  = 0;
    for(Order o : orders){
        count += o.getWeight();
    }
    return count;
}


map<int,vector<Order>> ManageOrders::efficientCourierVol() {
    map<int,vector<Order>> result;

    sort(ordersNormal.begin(),ordersNormal.end(),compareOrdersVol());
    sort(couriers.begin(), couriers.end(), compareCouriersVol());

    for (Order o1:ordersNormal) {
        for(Courier c1:couriers){
            if(result.find(c1.getId()) == result.end()){
                if((c1.getVolMax() >= o1.getVolume()) && (c1.getWeightMax() >= o1.getWeight())){
                    vector<Order> v;
                    v.push_back(o1);
                    result.insert(pair<int,vector<Order>>(c1.getId(),v));
                    break;
                }
            }else{
                if(((sumVol(result[c1.getId()]) + o1.getVolume()) <= c1.getVolMax())
                    && ((sumWeight(result[c1.getId()]) + o1.getWeight()) <= c1.getWeightMax())){
                    result[c1.getId()].push_back(o1);
                    break;
                }
            }
        }
    }
    return result;
}

map<int, vector<Order>> ManageOrders::efficientCourierWeight() {
    map<int,vector<Order>> result;

    sort(ordersNormal.begin(),ordersNormal.end(),compareOrdersWeight());
    sort(couriers.begin(), couriers.end(), compareCouriersWeight());

    for (Order o1:ordersNormal) {
        for(Courier c1:couriers){
            if(result.find(c1.getId()) == result.end()){
                if((c1.getWeightMax() >= o1.getWeight()) && (c1.getVolMax() >= o1.getVolume())){
                    vector<Order> v;
                    v.push_back(o1);
                    result.insert(pair<int,vector<Order>>(c1.getId(),v));
                    break;
                }
            }else{
                if(((sumWeight(result[c1.getId()]) + o1.getWeight()) <= c1.getWeightMax()) &&
                        ((sumVol(result[c1.getId()]) + o1.getVolume()) <= c1.getVolMax())){
                    result[c1.getId()].push_back(o1);
                    break;
                }
            }
        }
    }
    return result;
}







