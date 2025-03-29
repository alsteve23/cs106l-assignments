#include<iostream>
#include<string>
#include<map>
#include"class.h"

universityBuildings::universityBuildings(std::string name, std::string adress,std::string status, int rooms, int availableRooms){
    this->name=name;
    this->adress=adress;
    this->status=status;
    this->rooms=rooms; 
    this->availableRooms=availableRooms;
};

universityBuildings::universityBuildings(){
    this->name="XXXXX";
    this->adress="Urcucquí";
    this->status="Available";
    this->rooms=100;
    this->availableRooms=100;
};

std::map<std::string,int> universityBuildings::roomsIn(){
    std::map<std::string,int> ans{{name,availableRooms}};
    return ans;
};


const std::string universityBuildings::getName(){
    return name;
};
const std::string universityBuildings::getAdress(){
    return adress;
};
const std::string universityBuildings::getStatus(){
    return status;
};
const int universityBuildings::getRooms(){
    return rooms;
};

const int universityBuildings::getAvailableRooms(){
    return availableRooms;
};

void universityBuildings::setName(std::string name){
    this->name=name;
}
void universityBuildings::setAdress(std::string adress){
    this->adress=adress;
}
void universityBuildings::setStatus(std::string status){
    this->status=status;
}
void universityBuildings::setRooms(int rooms){
    this-> rooms=rooms;
};
void universityBuildings::setAvailableRooms(int availableRooms){
    this->availableRooms=availableRooms;
}
