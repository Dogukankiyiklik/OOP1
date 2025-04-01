#include "TankManager.h"

void TankManager::add_fuel_tank(vector<int> parameters) {
	Tank* tank = new Tank(tankList.size() + 1, parameters.front());
	tankList.push_back(tank);
	cout << "Tank " << tank->get_id() << " added!" << endl;
}

void TankManager::list_fuel_tanks() {
	int size = tankList.size();
	cout << "Fuel Tank List: " << endl;
	for (int i = 0; i < size; i++) { cout << "Tank " << tankList[i]->get_id() << endl; }
}

void TankManager::print_fuel_tank_count() { cout << "Fuel Tank Count is: " << tankList.size() << endl; }

void TankManager::remove_fuel_tank(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i] = tankList[size - 1];
			tankList.pop_back();
			cout << "Tank " << parameters.front() << " deleted!" << endl;
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}

Tank* TankManager::get_tank(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			return tankList[i];
		}
	}

	cout << "Tank id couln't found!" << endl;
	return NULL;
}

void TankManager::print_total_fuel_quantity() {
	int size = tankList.size();
	double total_fuel_quantity = 0;
	for (int i = 0; i < size; i++) { total_fuel_quantity += tankList[i]->get_fuel_quantity(); }
	cout << "Total fuel quantity is: " << total_fuel_quantity << endl;
}

void TankManager::print_tank_info(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->printInfo();
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}

void TankManager::fill_tank(vector<int> parameters){
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->fillTank(parameters[1]);
			return;
		}
	}

	cout << "Tank id couldn't found!" << endl;
}

void TankManager::open_valve(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->open_valve();
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}

void TankManager::close_valve(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->close_valve();
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}

void TankManager::break_fuel_tank(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->break_fuel_tank();
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}

void TankManager::repair_fuel_tank(vector<int> parameters) {
	int size = tankList.size();
	for (int i = 0; i < size; i++) {
		if (tankList[i]->get_id() == parameters.front()) {
			tankList[i]->repair_fuel_tank();
			return;
		}
	}

	cout << "Tank id couln't found!" << endl;
}