#ifndef LIB_THOTH_MEMBER_CHECK_H
#define LIB_THOTH_MEMBER_CHECK_H

#include <type_traits> // To use 'std::integral_constant'.
#include <iostream>    // To use 'std::cout'.
#include <iomanip>     // To use 'std::boolalpha'.


// Code from C++ templates book. This templated function can be used to check if a
// certain class has a certain member.
// Example usage;
// GENERATE_HAS_MEMBER(setIndex) //Generate a checker that looks for setIndex member
// has_member_setIndex<T>() //True if T has setIndex() or setIndex
// Note that this will NOT work when templating integers / floats/ etc.

#define GENERATE_HAS_MEMBER(member)                                               \
                                                                                  \
template < class T >                                                              \
class HasMember_##member                                                          \
{                                                                                 \
private:                                                                          \
    using Yes = char[2];                                                          \
    using  No = char[1];                                                          \
                                                                                  \
    struct Fallback { int member; };                                              \
    struct Derived : T, Fallback { };                                             \
                                                                                  \
    template < class U >                                                          \
    static No& test ( decltype(U::member)* );                                     \
    template < typename U >                                                       \
    static Yes& test ( U* );                                                      \
                                                                                  \
public:                                                                           \
    static constexpr bool RESULT = sizeof(test<Derived>(nullptr)) == sizeof(Yes); \
};                                                                                \
                                                                                  \
template < class T >                                                              \
struct has_member_##member                                                        \
: public std::integral_constant<bool, HasMember_##member<T>::RESULT>              \
{ };                                                                              \


namespace lth
{
	GENERATE_HAS_MEMBER(x)  // Creates 'has_member_x'.
	GENERATE_HAS_MEMBER(y)  // Creates 'has_member_y'.
	GENERATE_HAS_MEMBER(z)  // Creates 'has_member_z'.
	GENERATE_HAS_MEMBER(dot) // creates 'has_member_dot'.
	template <typename T>
	bool checkValidTemplateArgument(){return (has_member_x<T>() && has_member_y<T>() && has_member_z<T>()) && has_member_dot<T>();}
}
#endif //LIB_THOTH_LINE_H
