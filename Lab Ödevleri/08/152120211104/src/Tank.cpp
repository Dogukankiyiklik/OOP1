#include "Tank.h"

Tank::Tank(int id, double capacity) {
	this->capacity = capacity;
	this->id = id;
	fuelQuantity = 0;
	broken = false;
	valve.set_valve_status(false);
}

Tank::Tank(double fuel_quantity, double capacity, bool statement) {
	this->capacity = capacity;
	this->fuelQuantity = fuel_quantity;
	this->broken = !statement;
	this->valve.set_valve_status(statement);
	this->id = 0;
}

bool Tank::isValveOpen() { return valve.get_valve_statement(); }

int Tank::get_id() { return id; }

double Tank::get_capacity() { return capacity; }

double Tank::get_fuel_quantity() { return fuelQuantity; }

void Tank::printInfo() {
	cout << "--------------------------" << endl;
	cout << "Tank informations are:" << endl;
	cout << "--------------------------" << endl;
	cout << "Tank id is: " << id << endl;
	cout << "Tank capacity is: " << capacity << endl;
	cout << "Tank fuel quantity is: " << fuelQuantity << endl;
	cout << "Tank broken statement is: " << broken << endl;
	cout << "Tank valve statement is: " << valve.get_valve_statement() << endl;
}

void Tank::fillTank(int quantity) {
	fuelQuantity += quantity;
	if (fuelQuantity > capacity) { fuelQuantity = capacity; }
}

void Tank::open_valve() { valve.set_valve_status(true); }

void Tank::close_valve() { valve.set_valve_status(false); }

void Tank::break_fuel_tank() { broken = true; }

void Tank::repair_fuel_tank() { broken = false; }

double Tank::set_internal_tank_fuel_quantity(double quantity) {
	double excess = 0;
	fuelQuantity += quantity;
	if (fuelQuantity > capacity) {
		excess = fuelQuantity - capacity;
		fuelQuantity = capacity;
	}
	return excess;
}

void Tank::set_fuel_quantity(double excess) { fuelQuantity = excess; }

void Tank::absorb_fuel_from_internal_tank(double quantity) {
	fuelQuantity -= quantity;
}

double Tank::give_back_fuel_from_tank(double quantity) {
	double excess = 0;
	fuelQuantity += quantity;
	if (fuelQuantity > capacity) {
		excess = fuelQuantity - capacity;
		fuelQuantity = capacity;
	}

	return excess;
}