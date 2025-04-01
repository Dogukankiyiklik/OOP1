#pragma once
#include "fileReader.h"
#include "Command.h"
#include <sstream>

class CommandReader :public FileReader {
	string line;
public:
	Command* readCommand();
	void set_file_path(string);
};