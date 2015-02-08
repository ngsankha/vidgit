#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MEMCHECK(pointer)			\
	if (pointer == NULL) 			\
		std::cout<<"Memory Error\n";
