#pragma once

class Exceptions_from_vector_and_matrix
{
public:
	void except_throw(int nomber)
	{
		switch (nomber)
		{
		case 101:
			throw("Attempt to create a negative size vector");
			break;
		case 102:
			throw("Attempt pass an index that goes beyond memory");
			break;
		case 103:
			throw("Attempt addition of vectors of different lengths");
			break;
		case 104:
			throw("Attempt subtraction of vectors of different lengths");
			break;
		case 105:
			throw("Attempt multiplication of vectors of different lengths");
			break;
		case 106:
			throw("Attempt to create a negative size matrix");
			break;
		case 107:
			throw("Attempt addition of matrix of different lengths");
			break;
		case 108:
			throw("Attempt subtraction of matrix of different lengths");
			break;
		case 109:
			throw("Attempt multiplication of matrix of different lengths");
			break;
		default:
			throw("Unknown error");
			break;
		}
	}
};