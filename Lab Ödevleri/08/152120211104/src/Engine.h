#pragma once

#include <vector>
#include "Device.h"
#include "Tank.h"

using namespace std;

class Engine : public Device {
	static Engine* INSTANCE;
	double fuelPerSecond;
	bool status;
	Tank* internalTank; // composition
	vector<Tank*> connectedTankList; // aggregation

public:
	Engine();
	bool get_status();
	double get_fuel_per_second();
	double get_internal_tank_capacity();
	double get_internal_tank_fuel_quantity();
	void start();
	void stop();
	void connect_fuel_tank_to_engine(Tank*);
	void disconnect_fuel_tank_from_engine(vector<int>);
	void list_connected_tanks();
	void remove_fuel_tank(vector<int>);
	bool isTankConnected(int);
	void add_fuel_to_internal_tank();
	void consume_fuel();
	void give_fuel_to_fuel_tank();

};