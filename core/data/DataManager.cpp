#include <algorithm>
#include <type_traits>
#include "DataManager.h"
#include "../Exception.h"
#include "../data/Chunk.h"
#include "../physics/physics.h"
#include "../render/render.h"
#include "../script/script.h"

namespace Actinium::Data
{
#define ADDWITHDYNAMICCAST(type, add_to, arg, success_action, failure_action) { if (type casted = dynamic_cast<type>(arg))\
		if (add_to[typeid(type)].insert(casted).second) { \
			success_action;\
		}\
		else\
		{\
			failure_action;\
		}\
	else\
	{\
		failure_action;\
	}\
}
#define REMOVEWITHDYNAMICCAST(type, add_to, arg, success_action, failure_action) { if (type casted = dynamic_cast<type>(arg))\
		if (add_to[typeid(type)].erase(casted)) { \
		success_action;\
		}\
		else\
		{\
			failure_action;\
		}\
	else\
	{\
		failure_action;\
	}\
}
	
	const std::vector<std::type_index> DefaultDataManagerIp::filteredTypes = {
		typeid(Actinium::Render::Renderable),
		typeid(Actinium::Physics::Physical),
		typeid(Actinium::Script::Scriptable),
		typeid(Actinium::Data::Chunk)
	};

	const std::set<Actinium::Data::Data*>	DefaultDataManagerIp::zero;
	
	DefaultDataManagerIp::DefaultDataManagerIp()
	{
		if (DefaultDataManagerIp::checkTypeids(this->filteredTypes))
		{
			throw Actinium::Exception("Typeid are the same! That sucks if that happen to you :( try recompiling the thingie");
		}
	}
	
	int	DefaultDataManagerIp::checkTypeids(const std::vector<std::type_index> &list)
	{
		std::vector<std::type_index> buff;
		for(auto it = list.begin(); it != list.end(); it++)
		{
			if (std::find(buff.begin(), buff.end(), *it) != buff.end())
				return 1;
			buff.push_back(*it);
		}
		return 0;
	}
	int					DefaultDataManagerIp::add(Actinium::Data::Data* that)
	{
		int	ret = 1;
		ADDWITHDYNAMICCAST(Actinium::Render::Renderable*, this->datas, that, ret = 0, )
		ADDWITHDYNAMICCAST(Actinium::Physics::Physical*, this->datas, that, ret = 0, )
		ADDWITHDYNAMICCAST(Actinium::Script::Scriptable*, this->datas, that, ret = 0, )
		ADDWITHDYNAMICCAST(Actinium::Data::Chunk*, this->datas, that, ret = 0, )
		return ret;
	}
	int					DefaultDataManagerIp::remove(Actinium::Data::Data* that)
	{
		int	ret = 1;
		REMOVEWITHDYNAMICCAST(Actinium::Render::Renderable*, this->datas, that, ret = 0, )
		REMOVEWITHDYNAMICCAST(Actinium::Physics::Physical*, this->datas, that, ret = 0, )
		REMOVEWITHDYNAMICCAST(Actinium::Script::Scriptable*, this->datas, that, ret = 0, )
		REMOVEWITHDYNAMICCAST(Actinium::Data::Chunk*, this->datas, that, ret = 0, )
		return ret;
	}
	const std::set<Actinium::Data::Data*>	&DefaultDataManagerIp::get(const std::type_index &that) const
	{
		auto ret = this->datas.find(that);
		if (ret != this->datas.end())
		{
			return ret->second;
		}
		return zero;
	}
}
