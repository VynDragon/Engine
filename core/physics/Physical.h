#pragma once
#include "../data/Data.h"
#include "../data/Position.h"


namespace Actinium::Physics
{
	class Physical : public Actinium::Data::Data
	{
	public:
		virtual bool	movable(void) const = 0;
	protected:
	};
}
