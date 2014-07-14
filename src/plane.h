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
        T intersectWithLine(const Line<T> line);
    protected:
		T normal;
		U distance;
	};
	template <typename T, typename U>
	Plane<T,U>::Plane(){}
	template <typename T, typename U>
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

    template <typename T, typename U>
	T Plane<T,U>::intersectWithLine(const Line<T> line)
    {
        U normal_dot_origin = normal.dot(line.origin);
        U normal_dot_direction = normal.dot(line.direction);
        U depth = (normal[2] - normal_dot_origin) / normal_dot_direction;
        return T(line.origin + (((distance - normal_dot_origin)/normal_dot_direction) * line.direction));
    }


	//void Plane<T,U>::rotateByLine(const Line line, const float rotation){}

}

#endif //LIB_THOTH_PLANE_H
