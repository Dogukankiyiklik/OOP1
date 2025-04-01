#pragma once
#include "Command.h"
#include "Simulation.h"
#include "CommandReader.h"
#include "FileWriter.h"

class CommandManager {
	vector<Command*> commandList; // composition
	Simulation simulation;
	FileWriter output;

public:
	void run(string);
	void runCommands(vector<Command*>);
	void run_file_writer(string);
};