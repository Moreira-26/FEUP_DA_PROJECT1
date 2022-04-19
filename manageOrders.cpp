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

int sumPrice(vector<Order> orders){
    int count  = 0;
    for(Order o : orders){
        count += o.getPrice();
    }
    return count;
}

/////Menu
void ManageOrders::menu() {
    bool notExit = true;
    int input;

    do{
        cout << "-------- MENU --------" << endl;
        cout << endl;
        cout << "1) Minimize number of couriers" << endl;
        cout << "2) Maximize profit" << endl;
        cout << "3) Minimize time of express orders' delivery" << endl;
        cout << "0) Exit" << endl;
        
        cin >> input;
        while(input != 0 && input != 1 && input != 2 && input != 3) {
            cout << "Input invalido, insira novamente!" << endl;
            cin.clear();
            cin >> input;
        }

        switch (input) {
            case 0:
                notExit = false;
                break;
            case 1:
                printMapCourier(efficientCourier());
                break;
            case 2:
                printMapProfit(efficientProfit());
                break;
            case 3:
                averageTime();
                break;
        }
        
    } while (notExit);
}


/////Prints
void ManageOrders::printMapProfit(map<int,vector<Order>> mapResult) {
    int count = 0;
    int delivered = 0;
    int total = 0;
    for(pair<int,vector<Order>> p:mapResult){
        int aux = sumPrice(p.second) - getCourierId(p.first).getFee();
        if(aux > 0) {
            count+= aux;
            cout << "id Estafeta: " << p.first << " " << "Profit: " << aux << " ";
            cout << "Encomendas: ";
            for(Order o: p.second){
                delivered++;
                cout << o.getId() << " ";
            }
            cout << endl;
        }
        total += p.second.size();
    }

    cout << "Nº couriers: " << mapResult.size() << endl;
    cout << "Total profit: " << count << "€" << endl;
    cout << "Percentage of delivered orders: " << (double) (delivered * 100) / total << "%" << endl;
    cout << endl;
}

void ManageOrders::printMapCourier(map<int,vector<Order>> mapResult) {
    int numOrder = 0;
    for(pair<int,vector<Order>> p:mapResult){
            cout << "id Estafeta: " << p.first << " ";
            cout << "Encomendas: ";
            for(Order o: p.second){
                cout << o.getId() << " ";
                numOrder++;
            }
            cout << endl;
    }

    cout << "Nº estafetas: " << mapResult.size() << endl;
    cout << "Nº encomendas: " << numOrder << endl;
}

void ManageOrders::printMapTime(map<int, vector<Order>> mapResult) {

}


////Compare
struct compareOrdersTime{
    bool operator()(Order o1,Order o2) {
        return (o1.getTime() < o2.getTime());
    }
};

struct compareOrdersWeightVol{
    bool operator()(Order o1,Order o2) {
        return (o1.getWeight() * o1.getVolume()  > o2.getWeight() * o2.getVolume());
    }
};


struct compareCouriersWeightVol{
    bool operator()(Courier c1, Courier c2){
        return (c1.getWeightMax() * c1.getVolMax() > c2.getWeightMax() * c2.getVolMax());
    }
};


struct compareCouriersFee{
    bool operator()(Courier c1, Courier c2){
        return (((double)(c1.getFee())/(c1.getWeightMax() * c1.getVolMax())) < ((double)c2.getFee()/(c2.getWeightMax() * c2.getVolMax())));
    }
};

struct compareOrdersPrice{
    bool operator()(Order o1, Order o2){
        return ((double)o1.getPrice()/(o1.getWeight() * o1.getVolume()) > (double)o2.getPrice()/(o2.getWeight() * o2.getVolume()));
    }
};


///Algorithms
void ManageOrders::averageTime() {
    int timeTotal = 0;
    int time = 0;
    int num = 0;

    if(ordersExpress.empty()){
        cout << "No express deliveries" << endl;
        cout << endl;
        return;
    }
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



map<int,vector<Order>> ManageOrders::efficientProfit(){
    map<int,vector<Order>> result;

    sort(ordersNormal.begin(),ordersNormal.end(),compareOrdersPrice());
    sort(couriers.begin(), couriers.end(), compareCouriersFee());

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











