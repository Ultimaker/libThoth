#ifndef LIB_THOTH_PLANE_H
#define LIB_THOTH_PLANE_H
#include <iostream>
#include "line.h"
#include "vecUtil.h"
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
        	Line<T> intersectWithPlane(Plane<T,U> plane);
        	T getNormal();
        	T rotateVectorAroundLine(T point, Line<T> line, float angle);
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
	T Plane<T,U>::getNormal()
    {
        return normal;
    }
    template <typename T, typename U>
	T Plane<T,U>::intersectWithLine(const Line<T> line)
    {
        U normal_dot_origin = normal.dot(line.origin);
        U normal_dot_direction = normal.dot(line.direction);
        U depth = (normal[2] - normal_dot_origin) / normal_dot_direction;
        return T(line.origin + (((distance - normal_dot_origin) / normal_dot_direction) * line.direction));
    }

    template <typename T, typename U>
    Line<T> Plane<T,U>::intersectWithPlane(Plane<T,U> plane)
    {
        T line_direction = normal.cross(plane.getNormal());
        T v = line_direction.cross(normal);
        v /= sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
        //v /= norm(v);
        T line_origin = plane.intersectWithLine(Line<T>(normal * distance, v));
        line_direction /= sqrt(line_direction.x * line_direction.x + line_direction.y * line_direction.y + line_direction.z * line_direction.z);
        return Line<T>(line_origin,line_direction);
    }


	//void Plane<T,U>::rotateByLine(const Line line, const float rotation){}

}

#endif //LIB_THOTH_PLANE_H
