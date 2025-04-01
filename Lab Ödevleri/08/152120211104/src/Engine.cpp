#include "Engine.h"

Engine::Engine() {
	status = false;
	fuelPerSecond = 5.5;
	internalTank = new Tank(0.0, 55.0, true);
}

double Engine::get_fuel_per_second() { return fuelPerSecond; }

double Engine::get_internal_tank_capacity() { return internalTank->get_capacity(); }

double Engine::get_internal_tank_fuel_quantity() { return internalTank->get_fuel_quantity(); }

void Engine::start() {
	if (connectedTankList.empty()) { cout << "Engine couldn't started!" << endl; }
	else { 
		cout << "Engine started!" << endl;
		status = true;
	}
}

void Engine::stop() {
	if (status) {
		cout << "Engine stopped!" << endl;
		status = false;
	}
	else { cout << "Engine already doesn't work!" << endl; }
}

void Engine::connect_fuel_tank_to_engine(Tank* _tank) {
	if(_tank != NULL) {
		connectedTankList.push_back(_tank);
		cout << "Tank " << _tank->get_id() << " connected to engine!" << endl;
	}
}

void Engine::disconnect_fuel_tank_from_engine(vector<int> parameters) { 
	int size = connectedTankList.size();

	for (int i = 0; i < size; i++) {
		if (connectedTankList[i]->get_id() == parameters.front()) {
			connectedTankList[i] = connectedTankList[size - 1];
			connectedTankList.pop_back();
			cout << "Tank " << parameters.front() << " disconnected from engine!" << endl;
			return;
		}
	}

	cout << "Tank id couldn't found!" << endl;
}

void Engine::list_connected_tanks() {
	if (connectedTankList.empty()) { cout << "There is no connected tank!" << endl; }
	else {
		int size = connectedTankList.size();
		cout << "Connected Tank List: " << endl;
		for (int i = 0; i < size; i++) { cout << "Tank " << connectedTankList[i]->get_id() << endl; }
	}
}

void Engine::remove_fuel_tank(vector<int> parameters) {
	int size = connectedTankList.size();
	for (int i = 0; i < size; i++) {
		if (connectedTankList[i]->get_id() == parameters.front()) {
			connectedTankList[i] = connectedTankList[size - 1];
			connectedTankList.pop_back();
			cout << "Connected Tank " << parameters.front() << " deleted!" << endl;
			return;
		}
	}
}

bool Engine::isTankConnected(int tank_id) {
	int size = connectedTankList.size();
	for (int i = 0; i < size; i++) {
		if (tank_id == connectedTankList[i]->get_id()) { return true; }
	}
	return false;
}

bool Engine::get_status() { return status; }

void Engine::add_fuel_to_internal_tank() {
	while (internalTank->get_fuel_quantity() < 20) {
		int randomIndex = rand() % connectedTankList.size();
		double excess = internalTank->set_internal_tank_fuel_quantity(connectedTankList[randomIndex]->get_fuel_quantity());
		connectedTankList[randomIndex]->set_internal_tank_fuel_quantity(excess);
	}
}

void Engine::consume_fuel() { internalTank->absorb_fuel_from_internal_tank(fuelPerSecond); }

void Engine::give_fuel_to_fuel_tank() {
	while (internalTank->get_fuel_quantity() != 0) {
		int min_index = 0;
		double back_fuel = connectedTankList[0]->get_fuel_quantity();
		int size = connectedTankList.size();

		for (int i = 0; i < size; i++) {
			if (back_fuel > connectedTankList[i]->get_fuel_quantity()) {
				back_fuel = connectedTankList[i]->get_fuel_quantity();
				min_index = i;
			}
		}
		if (back_fuel == connectedTankList[min_index]->get_fuel_quantity()) {
			internalTank->set_fuel_quantity(0);
			return;
		}
		internalTank->set_fuel_quantity(connectedTankList[min_index]->give_back_fuel_from_tank(internalTank->get_fuel_quantity()));
	}
}