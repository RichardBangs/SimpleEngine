#include "EventBase.h"

namespace Simulation
{
	EventBase::EventBase(int frame)
	{
		_frame = frame;
	}
	
	//virtual
	EventBase::~EventBase()
	{
	}

}