#ifndef LIB_THOTH_LINE_H
#define LIB_THOTH_LINE_H
#include <iostream>

#include "HasMemberCheck.h"

GENERATE_HAS_MEMBER(setIndex)  // Creates 'has_member_att'.
//GENERATE_HAS_MEMBER(func) // Creates 'has_member_func'.
namespace lth
{
	template <typename T>
	class Line
	{
	public:
		Line(T test);
	protected:
		T element;
	};


	template <typename T>
	Line<T>::Line(T test)
	{
	}
}


#endif //LIB_THOTH_LINE_H
