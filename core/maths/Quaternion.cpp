#include "Quaternion.h"
#include "Vector.h"
#include <math.h>

namespace	Actinium::Maths
{
	Quaternion::Quaternion(const COORDINATE_TYPE a,const COORDINATE_TYPE b,const COORDINATE_TYPE c,const COORDINATE_TYPE d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	Quaternion::Quaternion(const COORDINATE_TYPE pitch, const COORDINATE_TYPE roll, const COORDINATE_TYPE yaw)
	{
		const COORDINATE_TYPE t0 = std::cos(yaw * (COORDINATE_TYPE)0.5);
		const COORDINATE_TYPE t1 = std::sin(yaw * (COORDINATE_TYPE)0.5);
		const COORDINATE_TYPE t2 = std::cos(roll * (COORDINATE_TYPE)0.5);
		const COORDINATE_TYPE t3 = std::sin(roll * (COORDINATE_TYPE)0.5);
		const COORDINATE_TYPE t4 = std::cos(pitch * (COORDINATE_TYPE)0.5);
		const COORDINATE_TYPE t5 = std::sin(pitch * (COORDINATE_TYPE)0.5);

		this->a = t0 * t2 * t4 + t1 * t3 * t5;
		this->b = t0 * t3 * t4 - t1 * t2 * t5;
		this->c = t0 * t2 * t5 + t1 * t3 * t4;
		this->d = t1 * t2 * t4 - t0 * t3 * t5;
	}
	Quaternion::Quaternion(const Vector &vector, const COORDINATE_TYPE angle)
	{
		const COORDINATE_TYPE sin_angle = std::sin(angle / 2.0);
		Vector normalized_vector = vector.normalized();
		this->b = normalized_vector.getX() * sin_angle;
		this->c = normalized_vector.getY() * sin_angle;
		this->d = normalized_vector.getZ() * sin_angle;
		this->a = std::cos(angle / 2.0);
	}
	const Quaternion	Quaternion::operator*(const Quaternion &other) const
	{
		return Quaternion(\
		other.a * this->a - other.b * this->b - other.c * this->c - other.d * this->d,\
		other.a * this->b + other.b * this->a - other.c * this->d + other.d * this->c,\
		other.a * this->c + other.b * this->d + other.c * this->a - other.d * this->b,\
		other.a * this->d + other.b * this->c + other.c * this->b - other.d * this->a);
	}
	const Vector		Quaternion::vector(void) const
	{
		/*Quaternion quaternion_vector = Quaternion(up.getX(), up.getY(), up.getZ(), 0);
		Quaternion result = quaternion_vector * (*this) * this->conjugate();
		return Vector(result.a, result.b, result.c);*/
		if (this->a == (COORDINATE_TYPE)1.0)
			return Vector(0, 0, 0);
		const COORDINATE_TYPE aa = sqrt(1 - this->a * this->a);
		return Vector(this->b / aa, this->c / aa, this->d / aa);
	}
	const COORDINATE_TYPE	Quaternion::angle(void) const
	{
		return ((COORDINATE_TYPE)2.0 * acos(this->a));
	}
	
	const Quaternion	Quaternion::conjugate(void) const
	{
		return Quaternion(a, -b, -c, -d);
	}
}
