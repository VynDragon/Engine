#include "Quaternion.h"
#include "Vector.h"
#include <math.h>

namespace	Maths
{
	Quaternion::Quaternion(const COORDINATE_TYPE a,const COORDINATE_TYPE b,const COORDINATE_TYPE c,const COORDINATE_TYPE d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	const Quaternion	Quaternion::operator*(Quaternion &other)
	{
		return Quaternion(other.a * this->a - other.b * this->b - other.c * this->c - other.d * this->d,\
		other.a * this->b + other.b * this->a - other.c * this->d + other.d * this->c,\
		other.a * this->c + other.b * this->d + other.c * this->a - other.d * this->b,\
		other.a * this->d + other.b * this->c + other.c * this->b - other.d * this->a);
	}
	const Vector		Quaternion::vector(void) const
	{
		return Vector(b / sqrt(1 - a * a), c / sqrt(1 - a * a), d / sqrt(1 - a * a));
	}
	const COORDINATE_TYPE	Quaternion::angle(void) const
	{
		return (2 * acos(a));
	}
}
