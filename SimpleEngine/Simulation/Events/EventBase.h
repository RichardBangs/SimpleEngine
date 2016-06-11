#pragma once

namespace Simulation
{
	enum eEventType
	{
		PlayerCreated,
		PlayerMove,
		PlayerInteract,

		ObjectCreated
	};


	class EventBase
	{
	public:
		EventBase(int frame);
		virtual ~EventBase();

		virtual eEventType GetType() = 0;

		inline int Frame() { return _frame; }

	protected:

		int _frame;
	};
}