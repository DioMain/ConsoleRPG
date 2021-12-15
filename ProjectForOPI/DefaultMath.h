#pragma once

// Class which have two parameters
class Vector2
{
public:
	
	int x;
	int y;

	/// <summary>
	/// Initialization
	/// </summary>
	/// <param name="x">X</param>
	/// <param name="y">Y</param>
	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	/// <summary>
	/// Initialization
	/// </summary>
	Vector2() {
		this->x = 0;
		this->y = 0;
	}

	/// <summary>
	/// Vector function
	/// </summary>
	/// <param name="vec">Vector2</param>
	/// <returns>Length of vector</returns>
	static float Length(Vector2 vec) {
		return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	}

	/// <summary>
	/// Vectors function
	/// </summary>
	/// <param name="vec0">First Vector2</param>
	/// <param name="vec1">Second Vector2</param>
	/// <returns>Dot of two vectors</returns>
	static float Dot(Vector2 vec0, Vector2 vec1) {
		return vec0.x * vec1.x + vec0.y * vec1.y;
	}

	/// <summary>
	/// Vectors function
	/// </summary>
	/// <param name="vec0">First Vector2</param>
	/// <param name="vec1">Second Vector2</param>
	/// <returns>Angle between two vectors</returns>
	static float Angle(Vector2 vec0, Vector2 vec1) {
		return Dot(vec0, vec1) / (Length(vec0) * Length(vec1));
	}

private:

};

Vector2 operator + (Vector2 left, Vector2 right) {

	Vector2 vec(left.x + right.x, left.y + right.y);

	return vec;
}

Vector2 operator - (Vector2 left, Vector2 right) {

	Vector2 vec(left.x - right.x, left.y - right.y);

	return vec;
}

bool operator == (Vector2 left, Vector2 right) {
	return (left.x == right.x && left.y == right.y) ? true : false;
}