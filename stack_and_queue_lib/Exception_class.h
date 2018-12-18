#pragma once

class Exceptions_from_stack_queue_multystack
{
public:
	void except_throw(int nomber)
	{
		switch (nomber)
		{
		case 101:
			throw("Attempt to create stack with negative size");
			break;
		case 102:
			throw("Attempt to put into full stack");
			break;
		case 103:
			throw("Attempt to get from empty stack");
			break;
		case 104:
			throw("Error with index of stack when IsFull, it is out of range");
			break;
		case 105:
			throw("Error with index of stack when IsEmpty, it is out of range");
			break;
		case 106:
			throw("Attempt to create queue with negative size");
			break;
		case 107:
			throw("Attempt to put into full queue");
			break;
		case 108:
			throw("Attempt to get from empty queue");
			break;
		case 109:
			throw("Error with index of queue when IsFull, it is out of range");
			break;
		case 110:
			throw("Error with index of queue when IsEmpty, it is out of range");
			break;
		case 111:
			throw("Attempt to create multystack with negative size or negative count of stacks");
			break;
		case 112:
			throw("Attempt to create multystack with more count of stacks than size of multystack");
			break;
		case 113:
			throw("Attempt to put item into full multystack");
			break;
		case 114:
			throw("This stack is empty");
			break;
		default:
			throw("Unknown error");
			break;
		}
	}
};