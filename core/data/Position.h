#include "../maths/maths.h"
#include "BoundingBox.h"

#pragma once

namespace Actinium::Data
{
	class Position : public Actinium::Data::BoundingBox
	{
	public:
		virtual const Maths::Quaternion		getAngles(void) const = 0;
		virtual const Maths::Vector		getPosition(void) const = 0;
		virtual void				setAngles(const Maths::Quaternion&) = 0;
		virtual	void				setPosition(const Maths::Vector&) = 0;
	protected:
	};
	
	class DefaultPositionIp : public Position
	{
	public:
		virtual const Maths::Quaternion	getAngles(void) const { return this->angles; }
		virtual const Maths::Vector	getPosition(void) const { return this->position; }
		virtual void			setAngles(const Maths::Quaternion &other) { this->angles = other; }
		virtual	void			setPosition(const Maths::Vector &other) { this->position = other; }
		
		// Composition
		// BoundingBox
		virtual const Actinium::Maths::Vector 	getTopFrontRightPoint(void) const { return this->cBoundingBox.getTopFrontRightPoint(); }
		virtual const Actinium::Maths::Vector 	getBottomBackLeftPoint(void) const { return this->cBoundingBox.getBottomBackLeftPoint(); }
		virtual const Actinium::Maths::Vector 	getSize(void) const { return this->cBoundingBox.getSize(); }
		virtual const Actinium::Maths::Vector	getScale(void) const { return this->cBoundingBox.getScale(); }
		virtual void				setTopFrontRightPoint(const Actinium::Maths::Vector &other) { this->cBoundingBox.setBottomBackLeftPoint(other); }
		virtual void				setBottomBackLeftPoint(const Actinium::Maths::Vector &other) { this->cBoundingBox.setBottomBackLeftPoint(other); }
		virtual void				setScale(const Actinium::Maths::Vector &other) { this->cBoundingBox.setScale(other); }
	protected:
		Maths::Quaternion	angles = Maths::Quaternion(0,0,0,0);
		Maths::Vector		position = Maths::Vector(0,0,0);
	
		// Composition
		DefaultBoundingBoxIp	cBoundingBox;
	};
}
