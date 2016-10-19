#include "parts_internal.h"

#pragma once
namespace Parts
{
	class Data
	{
	public:
		int getUpdatePriority(void) const { return updatePriority; }
		int getcleanPriority(void) const { return cleanPriority; }
	protected:
		int updatePriority = 0;
		int cleanPriority = 0;
	};
}
