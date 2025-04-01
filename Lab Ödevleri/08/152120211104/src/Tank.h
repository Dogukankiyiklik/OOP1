#pragma once

#include "Device.h"
#include "Valve.h"

class Tank :public Device {
	double capacity;
	double fuelQuantity;
	bool broken;
	Valve valve;
	int id;

public:
	Tank(int, double);
	Tank(double, double, bool);
	double get_capacity();
	bool isValveOpen();
	int get_id();
	double get_fuel_quantity();
	void printInfo();
	void fillTank(int);
	void open_valve();
	void close_valve();
	void break_fuel_tank();
	void repair_fuel_tank();
	double set_internal_tank_fuel_quantity(double);
	void absorb_fuel_from_internal_tank(double);
	void set_fuel_quantity(double);
	double give_back_fuel_from_tank(double);
};