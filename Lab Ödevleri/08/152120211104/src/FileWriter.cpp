#include "FileWriter.h"

void FileWriter::write_file() {
	output_file.open(filePath);
	streambuf* coutbuf = cout.rdbuf(); 

	cout.rdbuf(output_file.rdbuf());
	cout.rdbuf(coutbuf);
}

void FileWriter::set_file_path(string file_path) {
	this->filePath = file_path;
}