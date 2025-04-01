#include "CommandReader.h"

Command* CommandReader::readCommand() {
	Command* command = new Command();

	if (!input_file.is_open()) {
		input_file.open(filePath);

		if (!input_file) {
			cout << "File couldn't opened!";
			return NULL;
		}
	}

	line = readLine();
	stringstream ss(line);
	string token;

	getline(ss, token, ' ');
	command->set_command(token);
	while (getline(ss, token, ' ')) { command->set_parameters(stoi(token)); }

	if (command->get_command() == "") { return NULL; }
	else return command;
}

void CommandReader::set_file_path(string file_path) {
	this->filePath = file_path;
}