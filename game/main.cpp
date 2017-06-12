#include <iostream>

#include "../core/maths/maths.h"
#include "../core/data/data_.h"
#include "../core/render/render.h"

int main(int ac, char **av)
{
	Actinium::Data::DefaultDataManagerIp man;
	//auto dis = new Actinium::Data::Object;
	Actinium::Data::Data *dis = new Actinium::Data::DefaultChunkIp;
	Actinium::Data::Data *dis1 = new Actinium::Data::DefaultChunkIp;
	Actinium::Data::Data *dis2 = new Actinium::Data::DefaultObjectIp;
	std::cout << man.add(dis) << std::endl;
	std::cout << man.add(dis1) << std::endl;
	std::cout << man.add(dis2) << std::endl;
	std::cout << man.get(typeid(Actinium::Data::Chunk*)).size() << std::endl;
	std::cout << man.get(typeid(Actinium::Physics::Physical*)).size() << std::endl;
	std::cout << man.get(typeid(Actinium::Script::Scriptable*)).size() << std::endl;
	std::cout << man.get(typeid(Actinium::Render::Renderable*)).size() << std::endl;
	std::cout << man.remove(dis) << std::endl;
	std::cout << man.remove(dis) << std::endl;
	std::cout << man.remove(dis1) << std::endl;
	
	std::cout.precision(22);
	Actinium::Maths::Quaternion q(Actinium::Maths::Vector(0.0,0.0,1.0), M_PI / (COORDINATE_TYPE)2.0);
	std::cout << q.angle() << std::endl;
	std::cout << q.vector().getX() << "," << q.vector().getY() << "," << q.vector().getZ() << std::endl;
	std::cout << q.getB() << "," << q.getC() << "," << q.getD() << ","<< q.getA() <<std::endl;
}
