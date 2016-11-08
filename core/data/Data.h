#include <mutex>

#pragma once
namespace Actinium::Data
{
	class Data
	{
	public:
		virtual bool		isDeleted(void) const = 0;
		virtual bool		try_lock(void) = 0;
		virtual void		unlock(void) = 0;
	};
	
	class DefaultDataIp : public Actinium::Data::Data
	{
	public:
		virtual bool		isDeleted(void) const { return this->deleted; }
		virtual bool		try_lock(void) { return this->locked.try_lock(); }
		virtual void		unlock(void) { this->locked.unlock(); }
	protected:
		bool		deleted = false;
		std::mutex	locked;
		
	};
}
