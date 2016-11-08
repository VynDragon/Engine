#pragma once

#include "data_internal.h"
#include "../physics/physics.h"
#include "../render/render.h"
#include "../script/script.h"

namespace Actinium::Data
{
	class Object :	virtual public Actinium::Physics::Physical,\
			virtual public Actinium::Render::Renderable,\
			virtual public Actinium::Script::Scriptable
	{
	public:
		
	protected:
		
	};
	
	class DefaultObjectIp : public Object
	{
	public:
		// Composition
		// Data
		virtual bool		isDeleted(void) const { return this->cData.isDeleted(); }
		virtual bool		try_lock(void) { return this->cData.try_lock(); }
		virtual void		unlock(void) { return this->cData.unlock(); }
		// Position
		virtual const Maths::Quaternion	getAngles(void) const { return this->cPosition.getAngles(); }
		virtual const Maths::Vector	getPosition(void) const { return this->cPosition.getPosition(); }
		virtual void			setAngles(const Maths::Quaternion &other) { this->cPosition.setAngles(other); }
		virtual	void			setPosition(const Maths::Vector &other) { this->cPosition.setPosition(other); }
		// Renderable
	protected:
		// Composition
		DefaultDataIp		cData;
		DefaultPositionIp	cPosition;
		//DefaultRenderableIp	cRenderable;
	};
}
