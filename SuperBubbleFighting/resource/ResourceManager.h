#ifndef RESOURCEMANANGER_H
#define RESOURCEMANAGER_H




class ResourceManager
{

public:
	template <typename Resource>

	bool load(std::string path);



	ResourceManager();
	~ResourceManager();
};


#endif RESOURCEMANAGER_H

