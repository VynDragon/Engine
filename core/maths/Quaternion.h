#include "maths.h"

namespace Maths {

	class Quaternion
	{
	public:
		Quaternion(const COORDINATE_TYPE a,const COORDINATE_TYPE b,const COORDINATE_TYPE c,const COORDINATE_TYPE d);
		const Quaternion	operator*(Quaternion &other);
		const Vector		vector(void) const;
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
		COORDINATE_TYPE	a; // real part
		COORDINATE_TYPE	b;
		COORDINATE_TYPE	c;
		COORDINATE_TYPE	d;
	};

}
