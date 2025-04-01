#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h> 

using namespace std;

//! Engine class
class Engine {
	bool status = false;
	const double fuel_per_second = 5.5;
	const double engine_tank_capacity = 55.0;
	double engine_tank_quantity = 0;
	int connected_tank_count = 0;

public:
	void start_engine() {
		if (connected_tank_count > 0 && engine_tank_quantity > 0) {
			status = true;
		}
		else {
			status = false;
		}
	}

	void stop_engine() { status = false; }

	void add_connected_tank() { connected_tank_count++; }

	double consume_fuel(int time = 1) { 
		if (fuel_per_second * time > engine_tank_quantity) {
			double count = fuel_per_second* time - engine_tank_quantity;
			engine_tank_quantity = 0;
			return count;
		}
		else {
			engine_tank_quantity -= fuel_per_second * time;
			return 0;
		}
	}

	void set_engine_tank_quantity(int _quantity) { engine_tank_quantity = _quantity; }

	double add_fuel_to_initial_tank(double _quantity) {
		engine_tank_quantity += _quantity;
		if (engine_tank_quantity > engine_tank_capacity) {
			_quantity = engine_tank_quantity - engine_tank_capacity;
			engine_tank_quantity = engine_tank_capacity;
			return _quantity;
		}
		else { return 0; }
	}

	bool get_status() const { return status; }

	double get_fuel_per_second() const { return fuel_per_second; }

	double get_engine_tank_capacity() const { return engine_tank_capacity; }

	double get_engine_tank_quantity() const { return engine_tank_quantity; }

	int get_connected_tank_count() const { return connected_tank_count; }
};

//! Tank class
class Tank {
	double capacity;
	double fuel_quantity;
	bool broken;
	bool connected;
	int ID;

public:
	//! constructor
	Tank(double _quantity, int _ID) {
		capacity = _quantity;
		ID = _ID;
		fuel_quantity = 0;
		broken = false;
		connected = false;
	}

	//! finding tank ID
	int tank_id_find(int _ID) {
		if (ID == _ID) {
			return ID;
		}
		else {
			return -1;
		}
	}

	void connect_fuel_tank_to_engine() { connected = true; }

	void disconnect_fuel_tank_to_engine() { connected = false; }

	void break_fuel_tank() { broken = true; }

	void repair_fuel_tank() { broken = false; }

	void fill_tank(double _quantity) {
		fuel_quantity += _quantity;
		if (fuel_quantity > capacity) {
			fuel_quantity = capacity;
		}
	}

	double give_back_fuel_from_engine(double excess_fuel_quantity) {
		fuel_quantity += excess_fuel_quantity;
		if (fuel_quantity > capacity) {
			excess_fuel_quantity = fuel_quantity - capacity;
			fuel_quantity = capacity;
			return excess_fuel_quantity;
		}
		else { return 0; }
	}

	void decrease_fuel(double _quantity) {
		fuel_quantity = _quantity;
	}

	int get_tank_ID() const { return ID; }

	bool get_connected_statement() const { return connected; }

	double get_capacity() const { return capacity; }

	double get_fuel_quantity() const { return fuel_quantity; }

	bool get_broken_statement() const { return broken; }
};

//! valve class
class Valve {
	bool valve_statement;
	int valve_ID;

public:
	//! constructor
	Valve(int _valve_ID) {
		valve_statement = false;
		valve_ID = _valve_ID;
	}

	//! finding valve ID
	int valve_id_find(int _ID) {
		if (valve_ID == _ID) {
			return valve_ID;
		}
		else {
			return -1;
		}
	}

	void open_valve() { valve_statement = true; }

	void close_valve() { valve_statement = false; }

	int get_valve_ID() const { return valve_ID; }

	bool get_valve_satement() const { return valve_statement; }
};

//! for counting process then find the consumed fuel
int process = 0;

int main()
{
	//! class objects
	Engine engine;
	vector<Tank> fuel_tanks_list;
	vector<Valve> valve_list;
	double total_fuel_quantity = 0;
	double excess_fuel_quantity = 0;

	//! get input and output file name from user
	string input_file_name, output_file_name;
	cout << "Enter input file name and output file name" << endl;
	cin >> input_file_name >> output_file_name;

	//! file operations
	ifstream input(input_file_name);
	ofstream output(output_file_name);

	//! check if the file couldn't opened
	if (!input.is_open()) {
		while (!input.is_open()) {
			system("cls");
			cout << "File couldn't opened. Please try again!!!" << endl;
			cout << "Enter input file name" << endl;
			cin >> input_file_name;	
		}
		system("cls");
	}

	//! reading commands form input txt
	string line, quantity_1 = "", quantity_2 = "";
	int index_1 = 0, index_2 = 0;
	int tank_count = 1;
	bool is_ID_find = false;

	do {
		getline(input, line);

		if (line == "") { while (line == "") { getline(input, line); } }

		if (line[line.size() - 1] == ';') { line.resize(line.size() - 1); }
		
		//! check if the operation contains quantity
		while (line[index_1] != NULL) {
			if (line[index_1] == ' ') {
				index_2 = index_1;
				while (line[index_2] != NULL) {
					if (line[index_2] == ' ') {
						index_2++;
						while (line[index_2] != ' ' && line[index_2] != NULL) {
							quantity_2 += line[index_2];
							index_2++;
						}
						if (quantity_1 == "") {
							quantity_1 = quantity_2;
							quantity_2 = "";
						}
					}
					else {
						if (line[index_2] != NULL) {
							index_2++;
						}
					}
				}
				line.resize(index_1);
				break;
			}
			else
				index_1++;
		}

		//! ----------- Cases -----------
	
		//! Case:
		if (line == "start_engine") {
			if (engine.get_connected_tank_count() > 0) {
				while (engine.get_engine_tank_quantity() < 20) {
					int random_fuel_tank_index = rand() % fuel_tanks_list.size();
					if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
						double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
						adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

						if (adding_fuel == 0) {
							fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
						}
						else {
							fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
						}
					}
				}
			}
			engine.start_engine();
			if (!engine.get_status()) {
				output << "Engine couldn't start!" << endl;
			}
			else {
				output << "Engine started!" << endl;
			}
		}
		//! Case:
		else if (line == "stop_engine") {
			if (!engine.get_status()) {
				output << "Engine already not work!" << endl;
			}
			else {
				engine.stop_engine();
				output << "Engine stopped!" << endl;
			}

			//! give back fuel inside engine when it's stopped
			excess_fuel_quantity = engine.get_engine_tank_quantity();
			engine.set_engine_tank_quantity(0);
			bool break_min = false;
			while (excess_fuel_quantity != 0) {
				int min_fuel_index;
				for (int i = 0; i < fuel_tanks_list.size(); i++) {
					double min_fuel_of_tanks = fuel_tanks_list[i].get_fuel_quantity();
					for (min_fuel_index = i; min_fuel_index < fuel_tanks_list.size(); min_fuel_index++) {
						if (min_fuel_of_tanks > fuel_tanks_list[min_fuel_index].get_fuel_quantity()) {
							min_fuel_of_tanks = fuel_tanks_list[min_fuel_index].get_fuel_quantity();
							break_min = true;
							break;
						}
					}
					if (break_min) {
						break;
					}
				}
				excess_fuel_quantity = fuel_tanks_list[min_fuel_index].give_back_fuel_from_engine(excess_fuel_quantity);
			}
		}
		//! Case:
		else if (line == "absorb_fuel") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}
				process++;
			}
		}
		//! Case:
		else if (line == "give_back_fuel") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
		}
		//! Case:
		else if (line == "add_fuel_tank") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			Tank tank(stod(quantity_1), tank_count);
			fuel_tanks_list.push_back(tank);

			Valve valve(tank_count);
			valve_list.push_back(valve);

			tank_count++;
		}
		//! Case:
		else if (line == "list_fuel_tanks") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (int i = 0; i < fuel_tanks_list.size(); i++) {
				output << "Fuel Tank " << fuel_tanks_list[i].get_tank_ID() << endl;
			}
		}
		//! Case:
		else if (line == "remove_fuel_tank") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			//! for tanks
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " deleted!" << endl;
					fuel_tanks_list.erase(it);
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}

			//! for valves
			for (vector<Valve>::iterator it = valve_list.begin(); it != valve_list.end(); ++it) {
				if (it->valve_id_find(stoi(quantity_1)) != -1) {
					output << "Valve " << it->get_valve_ID() << " deleted!" << endl;
					valve_list.erase(it);
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Valve couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "connect_fuel_tank_to_engine") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " is connected to engine!" << endl;
					it->connect_fuel_tank_to_engine();
					engine.add_connected_tank();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "disconnect_fuel_tank_from_engine") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " is disconnected to engine!" << endl;
					it->disconnect_fuel_tank_to_engine();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "open_valve") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Valve>::iterator it = valve_list.begin(); it != valve_list.end(); ++it) {
				if (it->valve_id_find(stoi(quantity_1)) != -1) {
					output << "Valve " << it->get_valve_ID() << " is opened!" << endl;
					it->open_valve();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Valve couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "close_valve") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Valve>::iterator it = valve_list.begin(); it != valve_list.end(); ++it) {
				if (it->valve_id_find(stoi(quantity_1)) != -1) {
					output << "Valve " << it->get_valve_ID() << " is closed!" << endl;
					it->close_valve();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Valve couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "break_fuel_tank") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " is broken!" << endl;
					it->break_fuel_tank();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}	
		}
		//! Case:
		else if (line == "repair_fuel_tank") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " is repaired!" << endl;
					it->repair_fuel_tank();
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "print_fuel_tank_count") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			output << "\nFuel Tank Count is: " << tank_count - 1 << endl;
		}
		//! Case:
		else if (line == "list_connected_tanks") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (int i = 0; i < fuel_tanks_list.size(); i++) {
				if (fuel_tanks_list[i].get_connected_statement()) {
					output << "Fuel Tank " << fuel_tanks_list[i].get_tank_ID() << endl;
				}
			}
		}
		//! Case:
		else if (line == "print_tank_info") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "\nTank " << it->get_tank_ID() << " informations are" << endl;
					output << "-----------------------" << endl;
					output << "Tank " << it->get_tank_ID() << " Capacity is: " << it->get_capacity() << endl;
					output << "Tank " << it->get_tank_ID() << " Fuel Quantity is: " << it->get_fuel_quantity() << endl;
					output << "Tank " << it->get_tank_ID() << " Broken statement is: " << it->get_broken_statement() << endl;
					output << "Tank " << it->get_tank_ID() << " Connected statement is: " << it->get_connected_statement() << endl;
					output << "Tank " << it->get_tank_ID() << " Valve statement is: " << valve_list[stoi(quantity_1)].get_valve_satement() << endl << endl;
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "fill_tank") {
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
			for (vector<Tank>::iterator it = fuel_tanks_list.begin(); it != fuel_tanks_list.end(); ++it) {
				if (it->tank_id_find(stoi(quantity_1)) != -1) {
					output << "Tank " << it->get_tank_ID() << " is filled!" << endl;
					it->fill_tank(stod(quantity_2));
					is_ID_find = true;
					break;
				}
			}
			if (!is_ID_find) {
				output << "Tank couldn't found! The ID must be wrong" << endl;
			}
		}
		//! Case:
		else if (line == "wait") {
			if (engine.get_status()) {
				if (engine.consume_fuel(stoi(quantity_1) != 0)) {
					while (engine.consume_fuel(stoi(quantity_1)) != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process += stoi(quantity_1);
			}

		}
		//! Case:
		else if (line == "print_total_consumed_fuel_quantity") {
			output << "Total Consumed Fuel is: " << engine.get_fuel_per_second() * process << endl;
			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
		}
		//! Case:
		else if (line == "print_total_fuel_quantity") {
			for (int i = 0; i < fuel_tanks_list.size(); i++) {
				total_fuel_quantity += fuel_tanks_list[i].get_fuel_quantity();
			}
			output << "Total Fuel Quantity is: " << total_fuel_quantity << endl;

			if (engine.get_status()) {
				if (engine.consume_fuel() != 0) {
					while (engine.consume_fuel() != 0) {
						while (engine.get_engine_tank_quantity() < 20) {
							int random_fuel_tank_index = rand() % fuel_tanks_list.size();
							if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
								double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
								adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

								if (adding_fuel == 0) {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
								}
								else {
									fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
								}
							}
						}
					}
				}

				if (engine.get_engine_tank_quantity() < 20) {
					while (engine.get_engine_tank_quantity() < 20) {
						int random_fuel_tank_index = rand() % fuel_tanks_list.size();
						if (!fuel_tanks_list[random_fuel_tank_index].get_broken_statement() && fuel_tanks_list[random_fuel_tank_index].get_connected_statement() && valve_list[random_fuel_tank_index].get_valve_satement()) {
							double adding_fuel = fuel_tanks_list[random_fuel_tank_index].get_fuel_quantity();
							adding_fuel = engine.add_fuel_to_initial_tank(adding_fuel);

							if (adding_fuel == 0) {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(fuel_tanks_list[random_fuel_tank_index].get_capacity());
							}
							else {
								fuel_tanks_list[random_fuel_tank_index].decrease_fuel(adding_fuel);
							}
						}
					}
				}

				process++;
			}
		}

		quantity_1 = quantity_2 = "";
		index_1 = index_2 = 0;
		is_ID_find = false;

	} while (line != "stop_simulation");

	output << "Simulation Stopped!";
}