#pragma once
#include "FileOperator.h"
#include <fstream>

class FileWriter :public FileOperator {
public:
	ofstream output_file;
	void write_file();
	void set_file_path(string);
};