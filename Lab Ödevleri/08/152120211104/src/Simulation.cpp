#include "Simulation.h"

void Simulation::start_engine() { engine.start(); }

void Simulation::stop_engine() { 
	engine.stop(); 
	if (engine.get_internal_tank_fuel_quantity() > 0) {
		engine.give_fuel_to_fuel_tank();
	}
}

void Simulation::add_fuel_tank(vector<int> parameters) { 
	if (engine.get_status()) { 
		consume_fuel();
		process++; 
	}
	tank_manager.add_fuel_tank(parameters); 
}

void Simulation::list_fuel_tanks() { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.list_fuel_tanks(); 
}

void Simulation::print_fuel_tank_count() { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.print_fuel_tank_count();
}

void Simulation::remove_fuel_tank(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.remove_fuel_tank(parameters); 
	engine.remove_fuel_tank(parameters);
}

void Simulation::connect_fuel_tank_to_engine(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	Tank* _tank = tank_manager.get_tank(parameters);
	engine.connect_fuel_tank_to_engine(_tank);
}

void Simulation::disconnect_fuel_tank_from_engine(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	engine.disconnect_fuel_tank_from_engine(parameters); 
}

void Simulation::list_connected_tanks() { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	engine.list_connected_tanks(); 
}

void Simulation::print_total_fuel_quantity() { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.print_total_fuel_quantity(); 
}

void Simulation::print_tank_info(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.print_tank_info(parameters); 
}

void Simulation::fill_tank(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.fill_tank(parameters); 
}

void Simulation::open_valve(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.open_valve(parameters); 
}

void Simulation::close_valve(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.close_valve(parameters); 
}

void Simulation::break_fuel_tank(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.break_fuel_tank(parameters);
}

void Simulation::repair_fuel_tank(vector<int> parameters) { 
	if (engine.get_status()) {
		consume_fuel();
		process++;
	}
	tank_manager.repair_fuel_tank(parameters); 
}

void Simulation::print_total_consumed_fuel_quantity() { cout << "Total consumed feul Quantity is: " << process * engine.get_fuel_per_second() << endl; }

void Simulation::stop_simulation() { cout << "Simulation Stopped!" << endl; }

void Simulation::wait(vector<int> parameters) { process += parameters.front(); }

void Simulation::consume_fuel() {
	if (engine.get_internal_tank_fuel_quantity() < 20) {
		engine.add_fuel_to_internal_tank();
	}
	engine.consume_fuel();
}