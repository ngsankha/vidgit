#include "manager.h"

project* project_init()
{
	std::string directory;
	std::cout<<"Directory to store project Information?\n";
	std::cin>>directory;

	project* new_project = new project(directory);
	MEMCHECK(new_project)
	return new_project;
}

int project::add_basefile()
{
	std::string directory;
	std::cout<<"Directory of the new base file?\n";
	std::cin>>directory;

	base_files.push_back(directory);
	return 0; //Success
}

int project::remove_basefile()
{
	std::string directory;
	std::cout<<"Directory of the new base file?\n";
	std::cin>>directory;

	std::vector<std::string>::iterator it = find(base_files.begin(), base_files.end(), directory);

	if (it == base_files.end())
		std::cout<<"Invalid Directory\n";
	else
	{
		base_files.erase(it);
		std::cout<<"Base file erased\n";
	}

	return 0;
}

int project::apply_op(std::string method_name, std::vector<std::string> params)
{
	//Sql-lite stuff
	return 0;
}