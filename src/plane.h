#ifndef LIB_THOTH_PLANE_H
#define LIB_THOTH_PLANE_H
#include <iostream>
#include "line.h"
#include "HasMemberCheck.h"


namespace lth
{
	template <typename T, typename U>
	class Plane
	{
	public:
		Plane(T &_normal, U &_distance);
		Plane();
		//rotateByLine(const Line line, const U rotation);
	
    	protected:
		T normal;
		U distance;
	};
	Plane<T,U>::Plane(){}
	Plane<T,U>::Plane(T &_normal, U &_distance)
	{
		if(lth::checkValidTemplateArgument<T>())
		{
			normal = _normal;
			distance = _distance;
		} else 
		{
			throw std::invalid_argument( "Plane was templated with unusable class.");
		}
	}

	//void Plane<T,U>::rotateByLine(const Line line, const float rotation){}
	
}

#endif //LIB_THOTH_PLANE_H
