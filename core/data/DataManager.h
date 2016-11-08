#pragma once

#include <set>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include "Data.h"

namespace Actinium::Data
{
	class DataManager
	{
	public:
		virtual int						add(Actinium::Data::Data* that) = 0;
		virtual int						remove(Actinium::Data::Data* that) = 0;
		virtual const std::set<Actinium::Data::Data*>		&get(const std::type_index &that) const = 0;
	};

	class DefaultDataManagerIp : public DataManager
	{
	public:
		DefaultDataManagerIp();
		static const std::vector<std::type_index>	filteredTypes;
		static const std::set<Actinium::Data::Data*>	zero;
		virtual int					add(Actinium::Data::Data* that);
		virtual int					remove(Actinium::Data::Data* that);
		virtual const std::set<Actinium::Data::Data*>	&get(const std::type_index &that) const;
		
	protected:
		std::unordered_map<std::type_index, std::set<Actinium::Data::Data*>>	datas;
	private:
		static int	checkTypeids(const std::vector<std::type_index> &list);
	};
}

