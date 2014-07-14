#ifndef LIB_THOTH_VEC3_H
#define LIB_THOTH_VEC3_H
#include <iostream>

namespace lth
{
	//Simple base class for any 3D vector / point.
	template <typename T>
	class Vec3
	{
	public:
		Vec3 (T _x,T _y, T _z): x(_x), y(_y), z(_z) {}
		Vec3 () {}
		Vec3<T> operator + (const Vec3<T>& v) const { return Vec3<T>(x+v.x, y+v.y, z+v.z); }
		Vec3<T> operator - (const Vec3<T>& v) const { return Vec3<T>(x-v.x, y-v.y, z-v.z); }
		Vec3<T> operator / (const T i) const { return Vec3<T>(x/i, y/i, z/i); }
		Vec3<T> operator * (const T i) const {return Vec3<T>(x*i, y*i, z*i);  }

		Vec3<T>& operator += (const Vec3<T>& v) { x += v.x; y += v.y; z += v.z; return *this; }
		Vec3<T>& operator -= (const Vec3<T>& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }

		bool operator == (const Vec3<T>& v) const { return x==v.x&&y==v.y&&z==v.z; }
		bool operator != (const Vec3<T>& v) const { return x!=v.x||y!=v.y||z!=v.z; }

        friend std::ostream& operator << (std::ostream &stream, const Vec3 &v)
        {
            return stream << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        }

		T max()
        {
            if (x > y && x > z) return x;
            if (y > z) return y;
            return z;
        }

        Vec3<T> cross(const Vec3<T>& v)
        {
            return Vec3<T>(
            y*v.z-z*v.y,
            z*v.x-x*v.z,
            x*v.y-y*v.x);
        }

        T dot(const Vec3<T>& v)
        {
            return (v.x * x + v.y * y + v.z * z);
        }

		T x;
		T y;
		T z;
	protected:

	};


}


#endif //LIB_THOTH_VEC3_H
