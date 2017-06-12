#include "maths_internal.h"

#pragma once

namespace Actinium::Maths {

	class Vector
	{
	public:
		Vector(const COORDINATE_TYPE x,const COORDINATE_TYPE y,const COORDINATE_TYPE z);
		
		
		const Vector		normalized() const;
		const COORDINATE_TYPE	norm() const;
		const COORDINATE_TYPE	getX(void) const { return x; }
		const COORDINATE_TYPE	getY(void) const { return y; }
		const COORDINATE_TYPE	getZ(void) const { return z; }
		void			setX(const COORDINATE_TYPE x) { this->x = x; }
		void			setY(const COORDINATE_TYPE y) { this->y = y; }
		void			setZ(const COORDINATE_TYPE z) { this->z = z; }
	protected:
		COORDINATE_TYPE	x;
		COORDINATE_TYPE	y;
		COORDINATE_TYPE	z;
	};
	const static Vector	forward = Vector(1.0, 0.0, 0.0);
	const static Vector	up = Vector(0.0, 0.0, 1.0);
}
