#include <cstdlib>
#include <cstdio>
#include <stdexcept>

int
main(int argc, char** argv)
{
	FILE* as = std::fopen("test.as", "r");
	if (as == nullptr) {
		perror("fopen");
		throw std::runtime_error("fopen");
	}
	
	size_t i = 0;
	while (true) {
		char line[256];
		int res = std::fscanf(as, "%s\n", line);
		if (res == 0)
			break;
		std::printf("%d\t%s\n", i++, line);
	}
	
	if (std::fclose(as) != 0) {
		perror("fclose");
		throw std::runtime_error("fclose");
	}
	
	return EXIT_SUCCESS;
}
