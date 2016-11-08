#pragma once
#include "../data/Data.h"

namespace Actinium::Render
{
	class Renderable : public Actinium::Data::Data
	{
	public:
		virtual int	getModel(void) = 0;
	protected:
		
	};
	
	class DefaultRenderableIp : public Renderable
	{
	public:
		
	protected:
		
	};
}

