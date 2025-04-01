#include "CommandManager.h"

void CommandManager::run(string file_path) {
	CommandReader command_reader;
	command_reader.set_file_path(file_path);
	Command* command = command_reader.readCommand();

	while (command != NULL) {
		commandList.push_back(command);
		command = command_reader.readCommand();
		if (command->get_command() == "stop_simulation") {
			commandList.push_back(command);
			break;
		}
	}

	runCommands(commandList);
}

void CommandManager::runCommands(vector<Command*> commandList2) {
	for (Command *command : commandList2) {
		string command_line = command->get_command();

		if (command_line == "start_engine") { simulation.start_engine(); }

		else if (command_line == "stop_engine") { simulation.stop_engine(); }

		//else if (command_line == "absorb_fuel") {

		//}

		//else if (command_line == "give_back_fuel") {

		//}
		
		else if (command_line == "add_fuel_tank") { simulation.add_fuel_tank(command->get_parameters()); }

		else if (command_line == "list_fuel_tanks") { simulation.list_fuel_tanks(); }

		else if (command_line == "print_fuel_tank_count") { simulation.print_fuel_tank_count(); }

		else if (command_line == "remove_fuel_tank") { simulation.remove_fuel_tank(command->get_parameters()); }

		else if (command_line == "connect_fuel_tank_to_engine") { simulation.connect_fuel_tank_to_engine(command->get_parameters()); }

		else if (command_line == "disconnect_fuel_tank_from_engine") { simulation.disconnect_fuel_tank_from_engine(command->get_parameters()); }

		else if (command_line == "list_connected_tanks") { simulation.list_connected_tanks(); }

		else if (command_line == "print_total_fuel_quantity") { simulation.print_total_fuel_quantity(); }

		else if (command_line == "print_total_consumed_fuel_quantity") { simulation.print_total_consumed_fuel_quantity(); }

		else if (command_line == "print_tank_info") { simulation.print_tank_info(command->get_parameters()); }

		else if (command_line == "fill_tank") { simulation.fill_tank(command->get_parameters()); }

		else if (command_line == "open_valve") { simulation.open_valve(command->get_parameters()); }
		
		else if (command_line == "close_valve") { simulation.close_valve(command->get_parameters()); }

		else if (command_line == "break_fuel_tank") { simulation.break_fuel_tank(command->get_parameters()); }

		else if (command_line == "repair_fuel_tank") { simulation.repair_fuel_tank(command->get_parameters()); }

		else if (command_line == "wait") { simulation.wait(command->get_parameters()); }

		else if (command_line == "stop_simulation") {
			simulation.stop_simulation();
			return;
		}
	}
}

void CommandManager::run_file_writer(string file_path) {
	output.set_file_path(file_path);
	output.write_file();
}

