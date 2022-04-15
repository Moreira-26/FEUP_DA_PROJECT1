//
// Created by moreira on 02/04/22.
//

#include "order.h"

int Order::idSt = 1;

Order::Order(bool isExpress, int weight, int volume, int price, int time) {
    this->isExpress = isExpress;
    this->weight = weight;
    this->volume = volume;
    this->price = price;
    this->time = time;
    this->id = idSt;
    idSt++;
}

int Order::getIsExpress() {
    return isExpress;
}

int Order::getWeight() {
    return weight;
}

int Order::getVolume() {
    return volume;
}

int Order::getPrice() {
    return price;
}

int Order::getTime() {
    return time;
}

int Order::getId() {
    return id;
}

bool Order::operator<(const Order o1) {
    return this->getTime() < o1.time;
}

