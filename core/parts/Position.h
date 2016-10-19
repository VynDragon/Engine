#include "parts_internal.h"
#include "../maths/maths.h"

#pragma once

namespace Parts
{
	class Position
	{
	public:
		const Maths::Quaternion	getAngles(void) const { return this->angles; }
		const Maths::Vector	getPosition(void) const { return this->position; }
	protected:
		Maths::Quaternion	angles;
		Maths::Vector		position;
	};
}
