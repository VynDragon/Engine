#include "definitions.h"

class Data
{
public:
	int getUpdatePriority(void);
	int getcleanPriority(void);
protected:
	int updatePriority = 0;
	int cleanPriority = 0;
};
