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

Courier& ManageOrders::getCourierId(int id){
    for (Courier&c :couriers){
        if(c.getId() == id){
            return  c;
        }
    }
}


///Auxiliar Functions
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

/////Prints
void ManageOrders::printMap(map<int,vector<Order>> mapResult) {
    int count = 0;
    for(pair<int,vector<Order>> p:mapResult){
        cout << "id Estafeta: " << p.first << " " << "Weight: " << getCourierId(p.first).getWeightMax() -
                sumWeight(p.second) << "---" << "Volume " <<getCourierId(p.first).getVolMax() - sumVol(p.second) << " ";
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

struct compareOrdersWeightVol{
    bool operator()(Order o1,Order o2) {
        return (o1.getWeight() + o1.getVolume()  > o2.getWeight() + o2.getVolume());
    }
};


struct compareCouriersWeightVol{
    bool operator()(Courier c1, Courier c2){
        return (c1.getWeightMax() + c1.getVolMax() > c2.getWeightMax() + c2.getVolMax());
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

map<int, vector<Order>> ManageOrders::efficientCourier() {
    map<int,vector<Order>> result;

    sort(ordersNormal.begin(),ordersNormal.end(),compareOrdersWeightVol());
    sort(couriers.begin(), couriers.end(), compareCouriersWeightVol());

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







