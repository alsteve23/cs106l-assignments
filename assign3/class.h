#include<iostream>
#include<string>
#include<map>

class universityBuildings{
    private:
    std::string name;
    std::string adress;
    std::string status;
    int rooms;
    int availableRooms;
    std::map<std::string,int> roomsIn();
    public:
    universityBuildings(std::string name, std::string adress, std::string status, int rooms, int availableRooms);
    universityBuildings();
    const std::string getName();
    const std::string getAdress();
    const std::string getStatus();
    const int getRooms();
    const int getAvailableRooms();
    void setName(std::string name);
    void setAdress(std::string adress);
    void setStatus(std::string status);
    void setRooms(int rooms);
    void setAvailableRooms(int availableRooms);
    void print();
    void print(std::string name);
};