

#include "load.h"

Load::Load() {

}

void Load::couriers(ManageOrders &manageOrders) {
    string line, volMax, weightMax, fee;
    ifstream couriersStream;
    couriersStream.open(FILE_COURIER);

    getline(couriersStream,line); //Ignore first line

    if(couriersStream.is_open()){
        while (getline(couriersStream,line)){
            stringstream ss(line);
            ss >> volMax;
            ss >> weightMax;
            ss >> fee;
            Courier c(stoi(volMax), stoi(weightMax), stoi(fee));
            manageOrders.addCourier(c);
        }
    }else{
        cout << "CANT OPEN THE FILE" << endl;
    }

    couriersStream.close();
}

void Load::orders(ManageOrders &manageOrders) {
    string line, volume, weight, price, time;
    ifstream ordersStream;
    ordersStream.open(FILE_ORDERS);

    getline(ordersStream, line); //Ignore first line

    if(ordersStream.is_open()){
        while (getline(ordersStream,line)){
            stringstream ss(line);
            ss >> volume;
            ss >> weight;
            ss >> price;
            ss >> time;

            Order o( stoi(weight), stoi(volume),stoi(price),stoi(time));
            manageOrders.addOrder(o);
        }
    }else{
        cout << "CANT OPEN THE FILE" << endl;
    }

    ordersStream.close();
}



void Load::run(ManageOrders &manageOrders) {
    orders(manageOrders);
    couriers(manageOrders);
}


