#include "../maths/maths.h"

#pragma once

namespace Actinium::Data
{
	class BoundingBox
	{
	public:
		virtual const Actinium::Maths::Vector	getTopFrontRightPoint(void) const = 0; // the point of the rectangular cuboid with the highest Z, the Highest X, and the Highest Y relative to the position.
		virtual const Actinium::Maths::Vector	getBottomBackLeftPoint(void) const = 0; // the point of the rectangular cuboid with the lowest Z, the lowest X, and the lowest Y relative to the position.
		virtual const Actinium::Maths::Vector	getSize(void) const = 0;
		virtual const Actinium::Maths::Vector	getScale(void) const = 0; // root value for all stretching operations
		virtual void				setTopFrontRightPoint(const Actinium::Maths::Vector &other) = 0;
		virtual void				setBottomBackLeftPoint(const Actinium::Maths::Vector &other) = 0;
		virtual void				setScale(const Actinium::Maths::Vector &other) = 0;
	protected:
	};
	
	class DefaultBoundingBoxIp : public BoundingBox
	{
	public:
		virtual const Actinium::Maths::Vector 	getTopFrontRightPoint(void) const { return this->tfr; }
		virtual const Actinium::Maths::Vector 	getBottomBackLeftPoint(void) const { return this->bbl; }
		virtual const Actinium::Maths::Vector 	getSize(void) const { return Actinium::Maths::Vector(this->tfr.getX() - this->bbl.getX(), this->tfr.getY() - this->bbl.getY(), this->tfr.getZ() - this->bbl.getZ()); }
		virtual const Actinium::Maths::Vector	getScale(void) const { return this->scale; }
		virtual void				setTopFrontRightPoint(const Actinium::Maths::Vector &other) { this->tfr = other; }
		virtual void				setBottomBackLeftPoint(const Actinium::Maths::Vector &other) { this->bbl = other; }
		virtual void				setScale(const Actinium::Maths::Vector &other) { this->scale = other; }
	protected:
		Actinium::Maths::Vector	scale = Maths::Vector(1.0,1.0,1.0);
		Actinium::Maths::Vector	tfr = Maths::Vector(0,0,0);
		Actinium::Maths::Vector	bbl = Maths::Vector(0,0,0);
	};
}

