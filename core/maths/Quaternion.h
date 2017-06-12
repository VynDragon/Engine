#include "maths_internal.h"

#pragma once


// possible optimisation: caching vector and angle
// ALL EULER ANGLES IN RADIANS

// q = a + bi + cj + dk
// q = w + xi + yj + zk
namespace Actinium::Maths {

	class Quaternion
	{
	public:
		Quaternion(const COORDINATE_TYPE a,const COORDINATE_TYPE b,const COORDINATE_TYPE c,const COORDINATE_TYPE d);
		Quaternion(const COORDINATE_TYPE pitch, const COORDINATE_TYPE roll, const COORDINATE_TYPE yaw);
		Quaternion(const Vector &vector, const COORDINATE_TYPE angle);
		const Quaternion	operator*(const Quaternion &other) const;
		const Vector		vector(void) const; // referenced to forward
		const Quaternion	conjugate(void) const;
		const COORDINATE_TYPE	angle(void) const;
		const COORDINATE_TYPE	getA(void)  const { return a; }
		const COORDINATE_TYPE	getB(void)  const { return b; }
		const COORDINATE_TYPE	getC(void)  const { return c; }
		const COORDINATE_TYPE	getD(void)  const { return d; }
		void			setA(const COORDINATE_TYPE a) { this->a = a; }
		void			setB(const COORDINATE_TYPE b) { this->b = b; }
		void			setC(const COORDINATE_TYPE c) { this->c = c; }
		void			setD(const COORDINATE_TYPE d) { this->d = d; }
	protected:
		COORDINATE_TYPE	a; // real part, sometimes w
		COORDINATE_TYPE	b; // x
		COORDINATE_TYPE	c; // y
		COORDINATE_TYPE	d; // z
	};

}
