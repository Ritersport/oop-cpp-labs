#include "Source\Workflow.h"

int main(int argc, char* argv[]) {
	Executor executor;
	try {
		executor.execute(argv[1]);
	}
	catch (std::exception &exeption) {
		std::cout << exeption.what() << std::endl;
	}
	return 0;
}