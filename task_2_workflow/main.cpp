#include "Source\Workflow.h"

int main(int argc, char* argv[]) {
	Executor executor;
	try {
		if (argc != 2)
			throw(std::exception("Error: write schemefile as a parametr"));
		executor.execute(argv[1]);
	}
	catch (std::exception &exeption) {
		std::cout << exeption.what() << std::endl;
	}
	return 0;
}