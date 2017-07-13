#ifndef _DEBUG_IF_
#define _DEBUG_IF_

#include "systemc.h"

class debug_if : virtual public sc_interface {
public:
	virtual void dump(ostream &os) = 0;
};

#endif
