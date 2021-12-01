#include <iostream>

using std::cout;
using std::endl;

class Car
{
private:
    int gasolineGauge;
public:
    Car(const int gas) : gasolineGauge(gas) {}
    int GetGasGauge() const {return gasolineGauge;}
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(const int gas, const int elec) : Car(gas), electricGauge(elec) {}
    int GetElecGauge() const {return electricGauge;}
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(const int gas, const int elec, const int water) : HybridCar(gas, elec), waterGauge(water) {}
    void ShowCurrentGauge()
    {
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main(void)
{
    HybridWaterCar car(100, 200, 50);
    car.ShowCurrentGauge();

    return 0;
}