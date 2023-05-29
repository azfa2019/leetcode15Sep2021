class ParkingSystem {
public:
    vector<int>cars;
    ParkingSystem(int big, int medium, int small) {
        cars.push_back(big);
        
        cars.push_back(medium);
        cars.push_back(small);
    }
    
    bool addCar(int carType) {
        cars[carType-1]--;
        return cars[carType-1]>=0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */