#pragma once

#include "Tank.h"
#include <vector>

using namespace std;

class TankManager {
	vector<Tank*> tankList; // aggregation

public:
	void add_fuel_tank(vector<int>);
	void list_fuel_tanks();
	void print_fuel_tank_count();
	void remove_fuel_tank(vector<int>);
	Tank* get_tank(vector<int>);
	void print_total_fuel_quantity();
	void print_tank_info(vector<int>);
	void fill_tank(vector<int>);
	void open_valve(vector<int>);
	void close_valve(vector<int>);
	void break_fuel_tank(vector<int>);
	void repair_fuel_tank(vector<int>);
};