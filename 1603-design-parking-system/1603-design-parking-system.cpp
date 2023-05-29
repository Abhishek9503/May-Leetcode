
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        a[0] = small;
        a[1] = medium;
        a[2] = big;
    }
    int a[3];

    bool addCar(int carType) {
        return a[3-carType]-->0?true:false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */