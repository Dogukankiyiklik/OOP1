#include "Command.h"

void Command::set_command(string line) { this->command = line; }

void Command::set_parameters(int parameter) { this->parameters.push_back(parameter); }

string Command::get_command() { return command; }

vector<int> Command::get_parameters() { return parameters; }