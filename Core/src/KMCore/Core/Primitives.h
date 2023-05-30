#pragma once
#include "Core.h"

namespace KMCore
{
	/// <summary>
	/// The primitive Vector2 class
	/// </summary>
	template<typename T>
	class Vector2T
	{
	public:
		Vector2T()
			:x(0), y(0)
		{
		}
		Vector2T(T X, T Y)
			:x(X), y(Y)
		{
		}

		T x, y;
	};


	template <typename T>
	inline Vector2T<T>& operator +=(Vector2T<T>& left, const Vector2T<T>& right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}

	template <typename T>
	inline Vector2T<T>& operator -=(Vector2T<T>& left, const Vector2T<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}

	template <typename T>
	inline Vector2T<T> operator +(const Vector2T<T>& left, const Vector2T<T>& right)
	{
		return Vector2T<T>(left.x + right.x, left.y + right.y);
	}

	template <typename T>
	inline Vector2T<T> operator -(const Vector2T<T>& left, const Vector2T<T>& right)
	{
		return Vector2T<T>(left.x - right.x, left.y - right.y);
	}

	template <typename T>
	inline Vector2T<T> operator -(const Vector2T<T>& right)
	{
		return Vector2T<T>(-right.x, -right.y);
	}

	template <typename T>
	inline bool operator ==(const Vector2T<T>& left, const Vector2T<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	template <typename T>
	inline bool operator !=(const Vector2T<T>& left, const Vector2T<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y);
	}

	typedef Vector2T<float> Vector2;
	typedef Vector2T<int> Vector2Int;
	typedef Vector2T<unsigned int> Vector2u;


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