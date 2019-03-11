#pragma once

class Exceptions_from_list_arrlist
{
public:
	void except_throw(int nomber)
	{
		switch (nomber)
		{
		case 101:
			throw("Attempt to create NULL item of list");
			break;
		case 102:
			throw("Attempt to delete NULL item from list");
			break;
		case 103:
			throw("Index of item is out of length");
			break;
		case 104:
			throw("Attempt to delete from empty list");
			break;
		case 105:
			throw("Attempt to create a negative size array list");
			break;
		case 106:
			throw("Attempt to put into full array list");
			break;
		case 107:
			throw("Attempt to get from empty array list");
			break;
		default:
			throw("Unknown error");
			break;
		}
	}
};
