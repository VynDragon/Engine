#include "../maths/maths.h"

#pragma once

namespace Actinium::Data
{
	class Position
	{
	public:
		virtual const Maths::Quaternion	getAngles(void) const = 0;
		virtual const Maths::Vector	getPosition(void) const = 0;
		virtual void			setAngles(const Maths::Quaternion&) = 0;
		virtual	void			setPosition(const Maths::Vector&) = 0;
	protected:
	};
	
	class DefaultPositionIp : public Position
	{
	public:
		virtual const Maths::Quaternion	getAngles(void) const { return this->angles; }
		virtual const Maths::Vector	getPosition(void) const { return this->position; }
		virtual void			setAngles(const Maths::Quaternion &other) { this->angles = other; }
		virtual	void			setPosition(const Maths::Vector &other) { this->position = other; }
	protected:
		Maths::Quaternion	angles = Maths::Quaternion(0,0,0,0);
		Maths::Vector		position = Maths::Vector(0,0,0);
	};
}
