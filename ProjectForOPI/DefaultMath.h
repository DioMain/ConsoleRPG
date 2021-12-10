#pragma once

class Vector2
{
public:
	
	int x;
	int y;

	Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Vector2() {
		this->x = 0;
		this->y = 0;
	}

	static float Length(Vector2 vec) {
		return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	}

	static float Dot(Vector2 vec0, Vector2 vec1) {
		return vec0.x * vec1.x + vec0.y * vec1.y;
	}

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