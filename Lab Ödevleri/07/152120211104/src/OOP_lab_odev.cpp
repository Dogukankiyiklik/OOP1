#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//! class for engine
class Engine {
private:
	double fuel_per_second;
	bool status;
	int connected = 0;

public:
	void connected_engine() {
		connected++;
	}

	void un_connected_engine() {
		if (connected == 0) {
			cout << "There is not connected fuel tank" << endl;
		}
		else {
			connected--;
		}
	}

	void start_engine() {
		status = true;
		if (connected == 0) { // if engine has no connected fuel tank, engine will stop
			cout << "There is no connected fuel tank on the engine" << endl;
			stop_engine();
		}
	}

	void stop_engine() {
		if (status == false) {
			cout << "Engine is already not work" << endl;
		}
		else {
			cout << "The engine stop!" << endl;
			status = false;
		}
	}

	void absorb_fuel(double quantity) {

	}

	void give_back_fuel(double quantity) {

	}
};

//! class for fuel tank
class Tank {
private:
	double capacity, fuel_quantity;
	bool broken, connect, valve;
	int tank_id;

public:
	//! constructor
	Tank(double size, int id) {
		capacity = size;
		fuel_quantity = capacity;

		tank_id = id;

		broken = false;
		connect = false;
		valve = false;
	}

	void break_fuel_tank() {
		broken = true;
	}

	void repair_fuel_tank() {
		broken = false;
	}

	void open_valve() {
		valve = true;
	}

	void close_valve() {
		valve = false;
	}

	void connect_fuel_tank_to_engine() {
		connect = true;
	}

	void disconnect_fuel_tank_from_engine() {
		connect = false;
	}

	int tank_id_find(int id) {
		if (tank_id == id) {
			return id;
		}
		else {
			return -1;
		}
	}

	void print_information() {
		cout << "Tank id: " << tank_id << endl;
		cout << "Tank capacity of " << tank_id << ". tank is: " << capacity << endl;
		cout << "Tank fuel quantity of " << tank_id << ". tank is: " << fuel_quantity << endl;
		if (broken == true)
			cout << "Tank broken statement of " << tank_id << ". tank is: BROKEN " << endl;

		if (broken == false)
			cout << "Tank broken statement of " << tank_id << ". tank is: NOT BROKEN " << endl;

		if (connect == true)
			cout << "Tank connect statement of " << tank_id << ". tank is: CONNECTED " << endl;

		if (connect == false)
			cout << "Tank connect statement of " << tank_id << ". tank is: UNCONNECTED " << endl;

		if (valve == true)
			cout << "Tank valve statement of " << tank_id << ". tank is: OPEN" << endl;

		if (valve == false)
			cout << "Tank valve statement of " << tank_id << ". tank is: CLOSE" << endl;

		cout << endl;
	}

	int return_tank_id() {
		return tank_id;
	}

	bool return_valve_statement() {
		return valve;
	}
};

//! class for file manager
class FileManeger {
private:
	string inputFile, outputFile;
	Engine engine;
	vector<Tank> fuelTanks;

public:
	//! constructor
	FileManeger(string inputF, string outputF) {
		inputFile = inputF;
		outputFile = outputF;
	}

	int read() {
		ifstream input(inputFile);
		ofstream output(outputFile);

		int tankCount = 0;
		int tankID;

		//! check if the file couldn't be opened
		if (!input) {
			cout << "File could NOT opened";
			return 0;
		}

		string operation, quantity;

		do {
			getline(input, operation);
			if (operation == "") {
				getline(input, operation);
			}

			// case 1
			if (operation == "start_engine") {
				engine.start_engine();
			}
			// case 2
			else if (operation == "stop_engine") {
				engine.stop_engine();
			}
			// case 3
			else if (operation == "list_fuel_tanks") {
				for (int i = 0; i < fuelTanks.size(); i++) {
					fuelTanks[i].print_information();
				}
			}
			// other cases
			else {
				//! check if the operation contains quantity
				int index1 = 0, index2;
				while (operation[index1] != NULL && operation != "stop_simulation") {
					if (operation[index1] == '<') {
						index2 = index1;
						index2++;
						while (operation[index2] != '>') {
							quantity += operation[index2];
							index2++;
						}
						operation.resize(index1 - 1);
						break;
					}
					else
						index1++;
				}

				// case 4
				if (operation == "absorb_fuel") {
					engine.absorb_fuel(stod(quantity));
				}
				// case 5
				else if (operation == "give_back_fuel") {
					engine.give_back_fuel(stod(quantity));
				}
				// case 6
				else if (operation == "add_fuel_tank") {
					Tank tank(stod(quantity), tankCount);
					tankCount++;
					fuelTanks.push_back(tank);
				}
				// case 7
				else if (operation == "remove_fuel_tank") {
					for (vector<Tank>::iterator it = fuelTanks.begin(); it != fuelTanks.end(); ++it) {
						tankID = it->tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks.erase(it);
							break;
						}
					}
				}
				// case 8
				else if (operation == "connect_fuel_tank_to_engine") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].connect_fuel_tank_to_engine();
							break;
						}
					}
					engine.connected_engine();
				}
				// case 9
				else if (operation == "disconnect_fuel_tank_from_engine") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].disconnect_fuel_tank_from_engine();
							break;
						}
					}
					engine.un_connected_engine();
				}
				// case 10
				else if (operation == "open_valve") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].open_valve();
							break;
						}
					}
				}
				// case 11
				else if (operation == "close_valve") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].close_valve();
							break;
						}
					}
				}
				// case 12
				else if (operation == "break_fuel_tank") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].break_fuel_tank();
							break;
						}
					}
				}
				// case 13
				else if (operation == "repair_fuel_tank") {
					for (int i = 0; i < fuelTanks.size(); i++) {
						tankID = fuelTanks[i].tank_id_find(stoi(quantity));
						if (tankID != -1) {
							fuelTanks[i].repair_fuel_tank();
							break;
						}
					}
				}
				quantity = "";
			}

		} while (operation != "stop_simulation");

		cout << "The engine simulation stopped!" << endl;
		for (int i = 0; i < fuelTanks.size(); i++) {
			cout << "Tank " << fuelTanks[i].return_tank_id() + 1 << ": simulation stopped" << endl;
			cout << "Valve " << fuelTanks[i].return_tank_id() + 1 << ": simulation stopped" << endl;
		}

		return 0;
	}

	void write() {

	}
};

int main()
{
	FileManeger file("input.txt", "output.txt");
	file.read();
}