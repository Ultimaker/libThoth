#ifndef LIB_THOTH_LINE_H
#define LIB_THOTH_LINE_H
#include <iostream>

#include "HasMemberCheck.h"


namespace lth
{
	template <typename T>
	class Line
	{
	public:
		Line(T &_origin, T &_direction);
		T intersectWithLine(Line intersectionLine);
    protected:
		T origin;
		T direction;

	};

	template <typename T>
	Line<T>::Line(T &_origin, T &_direction)
	{
		if(lth::checkValidTemplateArgument<T>())//has_member_x<T>() && has_member_y<T>() && has_member_z<T>())
		{
			origin = _origin;
			direction = _direction;
		} else {
			throw std::invalid_argument( "Line was templated with unusable class." );
		}
	}

	// Find closest point to two 3D lines.
	// Will not handle some degenerate cases.
    	template <typename T>
	T Line<T>::intersectWithLine(Line<T> intersection_line)
	{
		// Define intermediate quantities.
		T q12 = origin - intersection_line.origin;
		auto v1_dot_v1 = direction.dot(direction);
		auto v2_dot_v2 = intersection_line.direction.dot(intersection_line.direction);
		auto v1_dot_v2 = direction.dot(intersection_line.direction);
		auto q12_dot_v1 = q12.dot(direction);
		auto q12_dot_v2 = q12.dot(intersection_line.direction);
		// Calculate scale factors.
		auto denom = v1_dot_v1 * v2_dot_v2 - v1_dot_v2 * v1_dot_v2;
		auto s =  (v1_dot_v2 / denom) * q12_dot_v2 - (v2_dot_v2 / denom) * q12_dot_v1;
		auto t = -(v1_dot_v2 / denom) * q12_dot_v1 + (v1_dot_v1 / denom) * q12_dot_v2;
		T result = T((origin + direction * s) + (intersection_line.origin + intersection_line.direction * t))/2.;
		return result;
	}
}


#endif //LIB_THOTH_LINE_H
