#pragma once
#include "FileOperator.h"
#include <fstream>
#include <string>
using namespace std;

class FileReader :public FileOperator {
private:
	string line;

protected:
	ifstream input_file;

public:
	string readLine();
};