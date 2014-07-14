#ifndef LIB_THOTH_LINE_H
#define LIB_THOTH_LINE_H
#include <iostream>

#include "HasMemberCheck.h"

GENERATE_HAS_MEMBER(setIndex)  // Creates 'has_member_att'.
//GENERATE_HAS_MEMBER(func) // Creates 'has_member_func'.

template<typename T>
class IsClassT {
  private:
    typedef char One;
    typedef struct { char a[2]; } Two;
    template<typename C> static One test(int C::*);
    // Will be chosen if T is anything except a class.
    template<typename C> static Two test(...);
  public:
    enum { Yes = sizeof(IsClassT<T>::template test<T>(0)) == 1 };
    enum { No = !Yes };
};

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
		if(IsClassT<T>::Yes){
            if(has_member_setIndex<T>())
            {
                std::cout << "Aww yeah" << std::endl;;
            } else {
                std::cout << "NOPE" << std::endl;
            }
		} else {
            std::cout << "It aint even a class!" << std::endl;
		}
	}
}


#endif //LIB_THOTH_LINE_H
