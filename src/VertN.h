#ifndef LIB_THOTH_VERTN_H
#define LIB_THOTH_VERTN_H
#include <iostream>

#include "HasMemberCheck.h"

namespace lth
{
	//Simple base class for meshes; vert that holds a position in 3D space and a normal
	template <typename T>
	class VertN
	{
	public:
		template <typename T>
		VertN(T& _position, T& _normal);
		T position;
		T normal;		
	};
	VertN<T>::VertN(T& _position, T& _normal)
	{
		if(lth::checkValidTemplateArgument<T>()){
			position = _position;
			normal = _normal;
		} else 
		{
			throw std::invalid_argument( "VertN was templated with unusable class." );
		}
	}
}



#endif //LIB_THOTH_VERTN_H
