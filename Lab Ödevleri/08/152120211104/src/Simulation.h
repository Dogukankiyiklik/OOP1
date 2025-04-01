#pragma once
#include "TankManager.h"
#include "Engine.h"

class Simulation {
	TankManager tank_manager;
	Engine engine;
	int process = 0;
public:
	void start_engine();
	void stop_engine();
	void add_fuel_tank(vector<int>);
	void list_fuel_tanks();
	void print_fuel_tank_count();
	void remove_fuel_tank(vector<int>);
	void connect_fuel_tank_to_engine(vector<int>);
	void disconnect_fuel_tank_from_engine(vector<int>);
	void list_connected_tanks();
	void print_total_fuel_quantity();
	void print_tank_info(vector<int>);
	void fill_tank(vector<int>);
	void open_valve(vector<int>);
	void close_valve(vector<int>);
	void break_fuel_tank(vector<int>);
	void repair_fuel_tank(vector<int>);
	void stop_simulation();
	void print_total_consumed_fuel_quantity();
	void wait(vector<int>);
	void consume_fuel();

};