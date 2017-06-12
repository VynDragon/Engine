#include "Vector.h"
#include <math.h>

namespace	Actinium::Maths
{
	Vector::Vector(const COORDINATE_TYPE x,const COORDINATE_TYPE y,const COORDINATE_TYPE z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	const COORDINATE_TYPE Vector::norm() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}
	const Vector	Vector::normalized() const
	{
		COORDINATE_TYPE norm_ = norm();
		return Vector(x / norm_, y / norm_, z / norm_);
	}
}
