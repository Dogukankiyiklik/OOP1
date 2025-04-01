#include "CommandManager.h"
using namespace std;

int main(int argc, char* argv[]) {
	CommandManager commands;

	commands.run(argv[1]);
	commands.run_file_writer(argv[2]);

}