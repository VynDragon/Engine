#pragma once
#include "../data/Data.h"
#include "../data/Position.h"


namespace Actinium::Physics
{
	class Physical
	{
	public:
		virtual bool	movable(void) const = 0;
	protected:
	};
	
	class DefaultPhysicalIp : public Physical
	{
	public:
		virtual bool	movable(void) const { return _movable; }
	protected:
		bool		_movable;
	};
}
