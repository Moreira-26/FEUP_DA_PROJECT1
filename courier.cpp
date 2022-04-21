//
// Created by moreira on 02/04/22.
//

#include "courier.h"

int Courier::idSt = 1;

Courier::Courier(int volMax, int weightMax, int fee) {
    this->volMax = volMax;
    this->weightMax = weightMax;
    this->fee = fee;
    this->id = idSt;
    idSt++;
}

int Courier::getId() {
    return this->id;
}

int Courier::getVolMax() {
    return volMax;
}

int Courier::getWeightMax() {
    return weightMax;
}

int Courier::getFee() {
    return fee;
}



