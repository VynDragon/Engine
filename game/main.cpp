#include <iostream>

#include "../core/maths/maths.h"

int main(int ac, char **av)
{
	std::cout << "hello world" << std::endl;
	Maths::Quaternion q(0,M_PI / 2.0,0);
	std::cout << q.angle() << std::endl;
	std::cout << q.vector().getX() << "," << q.vector().getY() << "," << q.vector().getZ() << std::endl;
	std::cout << q.getA() << "," << q.getD() << "," << q.getC() << ","<< q.getD() <<std::endl;
}
