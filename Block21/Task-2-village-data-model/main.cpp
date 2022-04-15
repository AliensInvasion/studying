#include <iostream>
#include <vector>

struct Building
{
    int type = 0;
    int space = 0;
    int furnace = 0;
};

struct Room
{
    int space = 0;
    int type = 0;
};

struct Floor
{
    int rooms = 0;
    Room room[4];
};

struct House
{
    int space = 0;
    int floors = 0;
    int floorHeight = 0;
    int furnace = 0;
    Floor floor[3];
};

struct LandPiece
{
    int id = -1;
    int landSize = 400;
    int buildings = 0;
    int haveBuildingTypes = 0;
    House house;
    Building building[3];
};


int buildingTypes(int &type)
{
    if (type == 1) return 1;
    if (type == 2) return 2;
    if (type == 3) return 4;
    return 0;
}

void show(std::vector<LandPiece> &lands)
{
    int villageSpace = 0;
    int buildingsSpace = 0;

    for (auto &i : lands) {

        villageSpace += i.landSize;

        std::cout << "\n------\nNext ID = " << i.id+1 << std::endl;
        std::cout << "Buildings in the land = " << i.buildings+1 << std::endl;
        std::cout << "------\n" << std::endl;


        std::cout << "Main house:"<< std::endl;
        std::cout << "Space = " << i.house.space << std::endl;
        buildingsSpace += i.house.space;
        std::cout << "Floors number = " << i.house.floors << std::endl;
        std::cout << "Floor height = " << i.house.floorHeight << std::endl;
        if (i.house.furnace == 1) std::cout << "Have a furnace." << std::endl;

        for (int j = 0; j < i.house.floors; ++j) {
            std::cout << "------\nFloor " << j+1 << ":"<< std::endl;
            std::cout << "Rooms on the floor = " << i.house.floor[j].rooms << std::endl;
            for (int k = 0; k < i.house.floor[j].rooms; ++k) {
                std::cout << "\nRoom " << k+1 << ":"<< std::endl;
                int type = i.house.floor[j].room[k].type;
                std::string answer;
                if (type == 0) answer = "Living-room";
                if (type == 1) answer = "Bedroom";
                if (type == 2) answer = "Kitchen";
                if (type == 3) answer = "Bathroom";
                if (type == 4) answer = "Children-room";
                std::cout << "Room type is " << answer << std::endl;
                std::cout << "Room space = " << i.house.floor[j].room[k].space << std::endl;

            }
        }

        std::cout << "\n------\nOther buildings:"<< std::endl;
        for (int j = 0; j < i.buildings; ++j) {
            std::cout << "------\nBuilding " << j+1 << ":" << std::endl;
            std::string answer;
            int type = i.building[j].type;
            if (type == 1) answer = "Garage";
            if (type == 2) answer = "Storage";
            if (type == 3) answer = "Bath house";
            std::cout << "Building type is " << answer << std::endl;
            std::cout << "Space = " << i.building[j].space << std::endl;
            buildingsSpace += i.building[j].space;
            if (type == 3 && i.building[j].furnace == 1) std::cout << "Have furnace." << std::endl;
        }

    }

    std::cout << "\n------\nVillage space overall = " << villageSpace << std::endl;
    std::cout << "Buildings space overall = " << buildingsSpace << std::endl;
    std::cout << "Buildings space / Village space = " << std::endl;
    std::cout << (double)buildingsSpace / (double)villageSpace << std::endl;

}

int main() {
    std::vector<LandPiece> lands;
    int num;
    std::cout << "Enter the number of land pieces:" << std::endl;
    std::cin >> num;

    for (int i = 0; i < num; ++i) {
        LandPiece current;
        current.id = i;
        std::cout << "------\nNext section number is " << current.id+1 << ".\n" << std::endl;
        std::cout << "Enter the space of the main house:" << std::endl;
        std::cin >> current.house.space;
        std::cout << "Enter the height of the floor in the main house:" << std::endl;
        std::cin >> current.house.floorHeight;
        std::cout << "Enter the number of the floors in the main house:" << std::endl;
        std::cin >> current.house.floors;
        while (current.house.floors > 3 || current.house.floors < 1) {
            std::cout << "Enter the number of the floors in the main house:" << std::endl;
            std::cin >> current.house.floors;
        }

        std::cout << "Does main house have a furnace?(1/0)" << std::endl;
        std::cin >> current.house.furnace;
        while (current.house.furnace > 1 || current.house.furnace < 0) {
            std::cin.clear();
            std::cout << "Does main house have a furnace?(1/0)" << std::endl;
            std::cin >> current.house.furnace;
        }


        for (int j = 0; j < current.house.floors; ++j) {

            std::cout << "Enter the number(1-4) of the rooms in the floor " << j+1 << ":" << std::endl;
            std::cin >> current.house.floor[j].rooms;
            while (current.house.floor[j].rooms > 4 || current.house.floor[j].rooms < 1) {
                std::cout << "Enter the number(1-4) of the rooms in the floor " << j+1 << ":" << std::endl;
                std::cin >> current.house.floor[j].rooms;
            }

            for (int k = 0; k < current.house.floor[j].rooms; ++k) {

                std::cout << "(Living-room is 0, bedroom is 1, kitchen is 2, bathroom is 3, children-room is 4)" << std::endl;
                std::cout << "Enter the type of the room " << k+1 << ":" << std::endl;
                std::cin >> current.house.floor[j].room[k].type;

                while (current.house.floor[j].room[k].type > 4 || current.house.floor[j].room[k].type < 0) {
                    std::cin.clear();
                    std::cout << "(Living-room is 0, bedroom is 1, kitchen is 2, bathroom is 3, children-room is 4)" << std::endl;
                    std::cout << "Enter the type of the room " << k+1 << ":" << std::endl;
                    std::cin >> current.house.floor[j].room[k].type;
                }

                std::cout << "Enter the space of the room:" << std::endl;
                std::cin >> current.house.floor[j].room[k].space;
            }

        }

        std::cout << "Enter the number of other buildings(1-3):" << std::endl;
        std::cin >> current.buildings;
        while (current.buildings < 0 || current.buildings > 3) {
            std::cout << "Enter the number of other buildings(1-3):" << std::endl;
            std::cin >> current.buildings;
        }

        int type = 0;
        for (int j = 0; j < current.buildings; ++j) {

            std::cout << "(Garage is 1, Storage is 2, Bath-house is 3)" << std::endl;
            std::cout << "Enter the type of building " << j+1 << ":" << std::endl;
            std::cin >> type;

            while (buildingTypes(type) == 0 || (buildingTypes(type) & current.haveBuildingTypes)) {
                std::cin.clear();
                std::cout << "(Garage is 1, Storage is 2, Bath-house is 3)" << std::endl;
                std::cout << "Enter the type of building " << j+1 << ":" << std::endl;
                std::cin >> type;
            }

            current.building[j].type = type;
            current.haveBuildingTypes |= buildingTypes(type);
            std::cout << "Enter the space of the building:" << std::endl;
            std::cin >> current.building[j].space;
            int furnace = -1;
            while (type == 3 && (furnace < 0 || furnace > 1)) {
                std::cin.clear();
                std::cout << "Have a furnace?(1/0)" << std::endl;
                std::cin >> furnace;
            }
            current.building[j].furnace = furnace;
        }
        lands.push_back(current);
    }
    show(lands);
}
