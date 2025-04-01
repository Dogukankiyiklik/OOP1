#pragma once
#include <vector>
#include <string>
using namespace std;

class Command {
	string command;
	vector<int> parameters;

public:
	void set_command(string);
	void set_parameters(int);
	string get_command();
	vector<int> get_parameters();
};