#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x;
	double y;
	Point()	{
		x = 0;
		y = 0;
	}
	
	Point(double _x, double _y) {

		x = _x;
		y = _y;
	}

	Point operator +(const Point & other) const {
		return Point(x + other.x, y + other.y);
	}

	Point operator -(const Point & other) const {
		return Point(x - other.x, y - other.y);
	}

	Point operator *(double k) const {
		return Point(x * k, y * k);
	}
	
	double operator %(const Point & other) const {
		return (x * other.x + y * other.y);
	}

	double operator *(const Point & other) const {
		return (x * other.y - other.x * y);
	}
	
	void scan() {
		cin >> x >> y;
	}

};

int main() {
	Point a, b, c;
	a.scan();
	b.scan();
	c.scan();
	const double P = 3.14159265358979323846;
	cout << fixed << setprecision(6) << max( fabs(atan2((a - b) * (c - b), (a - b) % (c - b))) ,max( fabs(atan2((b - a) * (c - a), (b - a) % (c - a))) , fabs(atan2((b - c) * (a - c), (b - c) % (a - c))) )) / P * 180;
	return 0;
}
