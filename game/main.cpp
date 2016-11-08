#include <iostream>

#include "../core/maths/maths.h"
#include "../core/data/data_.h"
#include "../core/render/render.h"

int main(int ac, char **av)
{
	Actinium::Data::DefaultDataManagerIp man;
	//auto dis = new Actinium::Data::Object;
	Actinium::Data::Data *dis = new Actinium::Data::DefaultChunkIp;
	std::cout << man.add(dis) << std::endl;
	std::cout << man.add(dis) << std::endl;
	std::cout << man.add(dis) << std::endl;
	std::cout << man.remove(dis) << std::endl;
	std::cout << man.remove(dis) << std::endl;
	std::cout << man.remove(dis) << std::endl;
	/*std::cout.precision(22);
	std::cout << "hello world" << std::endl;
	Actinium::Maths::Quaternion q(0,M_PI / (COORDINATE_TYPE)2.0,0);
	std::cout << q.angle() << std::endl;
	std::cout << q.vector().getX() << "," << q.vector().getY() << "," << q.vector().getZ() << std::endl;
	std::cout << q.getA() << "," << q.getD() << "," << q.getC() << ","<< q.getD() <<std::endl;*/
}
