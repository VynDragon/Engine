#pragma once

#include "Data.h"
#include "Position.h"
#include "DataManager.h"

namespace Actinium::Data
{
	class Chunk  : public Actinium::Data::Data, public Actinium::Data::Position, public Actinium::Data::DataManager
	{
	public:
		virtual COORDINATE_TYPE 	getMeterScale(void) const = 0; // the size of the meter, relative to one unit, as scale * unit = meter value
		
	protected:
	};
	
	class DefaultChunkIp : public Chunk
	{
	public:
		virtual COORDINATE_TYPE getMeterScale(void) const { return scale; }
		
		// Composition
		// Data
		virtual bool		isDeleted(void) const { return this->cData.isDeleted(); }
		virtual bool		try_lock(void) { return this->cData.try_lock(); }
		virtual void		unlock(void) { return this->cData.unlock(); }
		// Position
		virtual const Actinium::Maths::Quaternion	getAngles(void) const { return this->cPosition.getAngles(); }
		virtual const Actinium::Maths::Vector		getPosition(void) const { return this->cPosition.getPosition(); }
		virtual void					setAngles(const Maths::Quaternion &other) { this->cPosition.setAngles(other); }
		virtual	void					setPosition(const Maths::Vector &other) { this->cPosition.setPosition(other); }
		virtual const Actinium::Maths::Vector 		getTopFrontRightPoint(void) const { return this->cPosition.getTopFrontRightPoint(); }
		virtual const Actinium::Maths::Vector 		getBottomBackLeftPoint(void) const { return this->cPosition.getBottomBackLeftPoint(); }
		virtual const Actinium::Maths::Vector 		getSize(void) const { return this->cPosition.getSize(); }
		virtual const Actinium::Maths::Vector		getScale(void) const { return this->cPosition.getScale(); }
		virtual void					setTopFrontRightPoint(const Actinium::Maths::Vector &other) { this->cPosition.setBottomBackLeftPoint(other); }
		virtual void					setBottomBackLeftPoint(const Actinium::Maths::Vector &other) { this->cPosition.setBottomBackLeftPoint(other); }
		virtual void					setScale(const Actinium::Maths::Vector &other) { this->cPosition.setScale(other); }
		// DataManager
		virtual int							add(Actinium::Data::Data* that) { return this->cDataManager.add(that); }
		virtual int							remove(Actinium::Data::Data* that) { return this->cDataManager.remove(that); }
		virtual const std::unordered_set<Actinium::Data::Data*>		&get(const std::type_index &that) const { return this->cDataManager.get(that); }
	protected:
		COORDINATE_TYPE		scale = 1.0;
		
		
		// Composition
		DefaultDataIp		cData;
		DefaultPositionIp	cPosition;
		DefaultDataManagerIp	cDataManager;
	};
}
