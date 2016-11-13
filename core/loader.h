
#pragma once

#include <string>
#include <unordered_map>

namespace Actinium
{
	class ModuleLoader
	{
	public:
		virtual int	loadClassLib(const std::string& key, const std::string& path) = 0;
	}
	
}
