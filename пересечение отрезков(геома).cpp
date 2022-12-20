#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
struct Point {
	double x, y;
	Point() {
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

	void scan() {
		cin >> x >> y;
	}

	double operator %(const Point & other) const {
		return (x * other.x + y * other.y);
	}

	double operator *(const Point & other) const {
		return (x * other.y - other.x * y);
	}

	bool operator< (const Point & other) const {
		return x < other.x - eps || abs(x - other.x) < eps && y < other.y - eps;
	}
	
	Point turn() const {
		return Point(-y, x);
	}
	
	void print() {
		cout << fixed << setprecision(6) << x << " " << y << endl;
	}
};
bool doubleEqual(double a, double b) {
	return fabs(a - b) < eps;
}

bool doubleLess(double a, double b) {
	return a < b && !doubleEqual(a, b);
}

double Max(double a, double b) {
	if (doubleLess(a, b))
	{
		return b;
	}
	else
		return a;

}
double length(double x, double y) {
	return sqrt(x * x + y * y);
}

double dist_p_l(Point x, int a, int b, int c) {
	return abs(a * x.x + b * x.y + c) / length(a, b);
}

void find_coef(double *a, double *b, double *c, Point x, Point y) {
	*a = x.y - y.y;
	*b = y.x - x.x;
	*c = x.x * y.y - x.y * y.x;
}

bool Point_bel(Point x, Point a, Point b) {
	if (a.x > b.x)
		swap(a, b);
	if ((b - a) * (b - x) == 0 && (a.x < x.x || doubleEqual(a.x, x.x)) && (x.x < b.x || doubleEqual(b.x, x.x)) && ((x.y < a.y || doubleEqual(a.y, x.y)) && (b.y < x.y || doubleEqual(b.y, x.y)) || (x.y < b.y || doubleEqual(x.y, b.y)) && (a.y < x.y || doubleEqual(a.y, x.y))))
		return 1;
	return 0;
}

double Len(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp(Point i, Point j) {
	return (i.x < j.x) || (i.x == j.x && i.y < j.y);
}

void Add(const Point & p, vector<Point>& point) {
	while (point.size() > 1) {
		Point v1 = point[point.size() - 2] - point.back();
		Point v2 = point[point.size() - 2] - p;
		if (v2 * v1 > 0) {
			break;
		}
		point.pop_back();
	}
	point.push_back(p);
}

int Parall(Point x, Point y, Point n, Point m) {
	double a, b, c, a1, b1, c1;
	find_coef(&a, &b, &c, x, y);
	find_coef(&a1, &b1, &c1, n, m);
	if (doubleEqual(a * b1, a1 * b) && doubleEqual(b * c1, b1 * c))
		return 2;
	else if (doubleEqual(a * b1, a1 * b) && !doubleEqual(b * c1, b1 * c))
		return 1;
	else
		return 0;
}

Point creat_Point(double x, double y) {
	Point a = { x,y };
	return a;
}

double get(double a, double b, double x, double y) {
	return a * y - b * x;
}

bool Qve(Point a, Point p, Point b, Point o) {
	if (((a - o) * (b - o)) * ((b - o) * (p - o)) <= 0 && ((a - o) * (b - o)) * ((a - o) * (p - o)) >= 0)
		return 1;
	return 0;
}

pair<Point, Point> Ans(Point x, Point y, Point n, Point m) {
	Point p = { 1e6,1e6 }, t = { 1e6, 1e6 };
	int f = Parall(x, y, n, m);
	if (f == 1) {
		return{ p, t };
	}
	else if (f == 2) {
		if (y < x)
			swap(x, y);
		if (m < n)
			swap(n, m);
		if (Point_bel(x, n, m) || Point_bel(y, n, m) || Point_bel(n, x, y) || Point_bel(m, x, y))
			return{ max(x,n), min(y,m) };
		return{ p, t };
	}
	else {
		double a, b, c, a1, b1, c1;
		find_coef(&a, &b, &c, x, y);
		find_coef(&a1, &b1, &c1, n, m);
		if (Qve(x, m, y, n) && Qve(n, x, m, y) && Qve(y, n, x, m) && Qve(m, y, n, x)) {
			double d = get(a, b, a1, b1);
			double d1 = -1.0 * get(c, b, c1, b1);
			double d2 = -1.0 * get(a, c, a1, c1);
			p = { d1 / d, d2 / d };
			return{ p, t };
		}
		return{ p, t };
	}
}

int main() {
	
	Point x, y, n, m;
	x.scan();
	y.scan();
	n.scan();
	m.scan();
	pair<Point, Point > a = Ans(x, y, n, m);
	if (doubleEqual(a.second.x, 1e6))
	{
		if (doubleEqual(a.first.x, 1e6))
		{
			cout << "Empty";
		}
		else
		{
			a.first.print();
		}
	}
	else
	{
		a.first.print();
		if (!doubleEqual(a.first.x, a.second.x) || !doubleEqual(a.first.y, a.second.y))
			a.second.print();
	}
	return 0;
}
