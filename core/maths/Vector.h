#include "maths.h"

namespace Maths {

	class Vector
	{
	public:
		Vector(const COORDINATE_TYPE x,const COORDINATE_TYPE y,const COORDINATE_TYPE z);
		const COORDINATE_TYPE	getX(void) { return x; }
		const COORDINATE_TYPE	getY(void) { return y; }
		const COORDINATE_TYPE	getZ(void) { return z; }
		void			setA(const COORDINATE_TYPE x) { this->x = x; }
		void			setB(const COORDINATE_TYPE y) { this->y = y; }
		void			setC(const COORDINATE_TYPE z) { this->z = z; }
	protected:
		COORDINATE_TYPE	x;
		COORDINATE_TYPE	y;
		COORDINATE_TYPE	z;
	};

}
