#include "FileReader.h"

string FileReader::readLine() {
	getline(input_file, line);
	return line;
}