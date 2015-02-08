#include "general.h"

class project
{
	std::string directory;
	std::vector<std::string> base_files;
public:
	project(std::string project_directory)
	{
		directory = project_directory;
	}
	int apply_op(std::string method_name, std::vector<std::string> params);
	int add_basefile();
	int remove_basefile();
	int fetch_fromserver();
};

project* project_init();
