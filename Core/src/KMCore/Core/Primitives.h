#pragma once
#include "Core.h"

namespace KMCore
{
	/// <summary>
	/// The primitive Vector2 class
	/// </summary>
	template<typename T>
	class Vector2x
	{
	public:
		Vector2x()
			:x(0), y(0)
		{
		}
		Vector2x(T X, T Y)
			:x(X), y(Y)
		{
		}

		static Vector2x<T> Clamp(Vector2x<T>& vector, T min, T max)
		{
			vector.x = vector.x < min ? min : vector.x > max ? max : vector.x;
			vector.y = vector.y < min ? min : vector.y > max ? max : vector.y;
			return vector;
		}

		static Vector2x<T> zero;
		static Vector2x<T> left;
		static Vector2x<T> right;
		static Vector2x<T> up;
		static Vector2x<T> down;

		T x, y;
	};

	template<typename T>
	Vector2x<T> Vector2x<T>::zero = Vector2x<T>();
	template<typename T>
	Vector2x<T> Vector2x<T>::left = Vector2x<T>(-1, 0);
	template<typename T>
	Vector2x<T> Vector2x<T>::right = Vector2x<T>(1, 0);
	template<typename T>
	Vector2x<T> Vector2x<T>::up = Vector2x<T>(0, -1);
	template<typename T>
	Vector2x<T> Vector2x<T>::down = Vector2x<T>(0, 1);


	template <typename T>
	inline Vector2x<T>& operator +=(Vector2x<T>& left, const Vector2x<T>& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}

	template <typename T>
	inline Vector2x<T>& operator -=(Vector2x<T>& left, const Vector2x<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}

	template <typename T>
	inline Vector2x<T>& operator *=(Vector2x<T>& left, const Vector2x<T>& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		return left;
	}

	template <typename T>
	inline Vector2x<T>& operator *=(Vector2x<T>& left, const T& right)
	{
		left.x *= right;
		left.y *= right;
		return left;
	}

	template <typename T>
	inline Vector2x<T> operator *(const Vector2x<T>& left, const T& right)
	{
		return Vector2x<T>(left.x * right, left.y * right);
	}

	template <typename T>
	inline Vector2x<T>& operator /=(Vector2x<T>& left, const Vector2x<T>& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		return left;
	}

	template <typename T>
	inline Vector2x<T>& operator /=(Vector2x<T>& left, const T& right)
	{
		left.x /= right;
		left.y /= right;
		return left;
	}

	template <typename T>
	inline Vector2x<T> operator /(const Vector2x<T>& left, const T& right)
	{
		return Vector2x<T>(left.x / right, left.y / right);
	}

	template <typename T>
	inline Vector2x<T> operator /(const Vector2x<T>& left, const Vector2x<T>& right)
	{
		return Vector2x<T>(left.x / right.x, left.y / right.y);
	}

	template <typename T>
	inline Vector2x<T> operator +(const Vector2x<T>& left, const Vector2x<T>& right)
	{
		return Vector2x<T>(left.x + right.x, left.y + right.y);
	}

	template <typename T>
	inline Vector2x<T> operator -(const Vector2x<T>& left, const Vector2x<T>& right)
	{
		return Vector2x<T>(left.x - right.x, left.y - right.y);
	}

	template <typename T>
	inline Vector2x<T> operator -(const Vector2x<T>& right)
	{
		return Vector2x<T>(-right.x, -right.y);
	}

	template <typename T>
	inline bool operator ==(const Vector2x<T>& left, const Vector2x<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	template <typename T>
	inline bool operator !=(const Vector2x<T>& left, const Vector2x<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y);
	}

	typedef Vector2x<float> Vector2;
	typedef Vector2x<int> Vector2Int;
	typedef Vector2x<unsigned int> Vector2u;


	/// <summary>
	/// The primitive Vector4 class
	/// </summary>
	template<typename T>
	class Vector4T
	{
	public:
		Vector4T()
			:x(0), y(0), z(0), w(0)
		{
		}
		Vector4T(T X, T Y, T Z, T W)
			:x(X), y(Y), z(Z), w(W)
		{
		}
		~Vector4T() = default;

		T x, y, z, w;


	};

	template <typename T>
	inline Vector4T<T>& operator +=(Vector4T<T>& left, const Vector4T<T>& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		left.w += right.w;

		return left;
	}

	template <typename T>
	inline Vector4T<T>& operator -=(Vector4T<T>& left, const Vector4T<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		left.w -= right.w;

		return left;
	}

	template <typename T>
	inline Vector4T<T> operator +(const Vector4T<T>& left, const Vector4T<T>& right)
	{
		return Vector4T<T>(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
	}

	template <typename T>
	inline Vector4T<T> operator -(const Vector4T<T>& left, const Vector4T<T>& right)
	{
		return Vector4T<T>(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
	}

	template <typename T>
	inline Vector4T<T> operator -(const Vector4T<T>& right)
	{
		return Vector4T<T>(-right.x, -right.y, -right.z, -right.w);
	}

	template <typename T>
	inline Vector4T<T> operator *(const T left, const Vector4T<T>& right)
	{
		return Vector4T<T>(right.x * left, right.y * left, right.z * left, right.w * left);
	}

	template <typename T>
	inline Vector4T<T> operator *(const Vector4T<T>& left, const T right)
	{
		return Vector4T<T>(left.x * right, left.y * right, left.z * right, left.w * right);
	}

	template <typename T>
	inline bool operator ==(const Vector4T<T>& left, const Vector4T<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w);
	}

	template <typename T>
	inline bool operator !=(const Vector4T<T>& left, const Vector4T<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w);
	}

	typedef Vector4T<float> Vector4;
	typedef Vector4T<int> Vector4Int;
}