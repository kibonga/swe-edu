#include "design-parking-system.h"

class ParkingSystem {
public:
    unordered_map<int, int> map;
    ParkingSystem(int big, int medium, int small) {
        map[1] = big;
        map[2] = medium;
        map[3] = small;
    }

    bool addCar(int carType) {
        if(map.find(carType) == map.end()) {
            return false;
        }
        if(map[carType] <= 0) {
            return false;
        }
        map[carType]--;
        return true;
    }
};

void runDesignParkingSystemExample() {
    ParkingSystem ps = ParkingSystem(1, 1, 0);
    cout << "Add car = " << ps.addCar(1) << endl;
    cout << "Add car = " << ps.addCar(2) << endl;
    cout << "Add car = " << ps.addCar(3) << endl;
    cout << "Add car = " << ps.addCar(1) << endl;
}
