
#ifndef GRAPH_GUARD
#define GRAPH_GUARD 1
//#define PI 3.14159265358979323846
#include "Point.h"
#include <vector>
#include <string>
#include <cmath>
#include "fltk.h"
#include "std_lib_facilities.h"  // ← Раскомментируй!
#include <functional>
#include <iostream>
#include <cmath>
#include <list>
//=====================================================================================================
constexpr double PI = 3.14159265358979323846;
//=====================================================================================================
namespace Graph_lib {
// defense against ill-behaved Linux macros:
#undef major
#undef minor
//=====================================================================================================
struct Color {
	enum Color_type {
		red=FL_RED, blue=FL_BLUE, green=FL_GREEN,
		yellow=FL_YELLOW, white=FL_WHITE, black=FL_BLACK,
		magenta=FL_MAGENTA, cyan=FL_CYAN, dark_red=FL_DARK_RED,
		dark_green=FL_DARK_GREEN, dark_yellow=FL_DARK_YELLOW, dark_blue=FL_DARK_BLUE,
		dark_magenta=FL_DARK_MAGENTA, dark_cyan=FL_DARK_CYAN
	};
	enum Transparency { invisible = 0, visible=255 };

	Color(Color_type cc) :c(Fl_Color(cc)), v(visible) { }
	Color(Color_type cc, Transparency vv) :c(Fl_Color(cc)), v(vv) { }
	Color(int cc) :c(Fl_Color(cc)), v(visible) { }
	Color(Transparency vv) :c(Fl_Color()), v(vv) { }

	int as_int() const { return c; }
	char visibility() const { return v; }
	void set_visibility(Transparency vv) { v=vv; }
private:
	unsigned char v;	// 0 or 1 for now
	Fl_Color c;
};
//=====================================================================================================
struct Line_style {
	enum Line_style_type {
		solid=FL_SOLID,				// -------
		dash=FL_DASH,				// - - - -
		dot=FL_DOT,					// ....... 
		dashdot=FL_DASHDOT,			// - . - . 
		dashdotdot=FL_DASHDOTDOT,	// -..-..
		none=FL_NONE,				//         
	};
	Line_style(Line_style_type ss) :s(ss), w(0) { }
	Line_style(Line_style_type lst, int ww) :s(lst), w(ww) { }
	Line_style(int ss) :s(ss), w(0) { }

	int width() const { return w; }
	int style() const { return s; }
private:
	int s;
	int w;
};
//=====================================================================================================
class Font {
public:
	enum Font_type {
		helvetica=FL_HELVETICA,
		helvetica_bold=FL_HELVETICA_BOLD,
		helvetica_italic=FL_HELVETICA_ITALIC,
		helvetica_bold_italic=FL_HELVETICA_BOLD_ITALIC,
		courier=FL_COURIER,
  		courier_bold=FL_COURIER_BOLD,
  		courier_italic=FL_COURIER_ITALIC,
  		courier_bold_italic=FL_COURIER_BOLD_ITALIC,
		times=FL_TIMES,
		times_bold=FL_TIMES_BOLD,
		times_italic=FL_TIMES_ITALIC,
		times_bold_italic=FL_TIMES_BOLD_ITALIC,
		symbol=FL_SYMBOL,
		screen=FL_SCREEN,
		screen_bold=FL_SCREEN_BOLD,
		zapf_dingbats=FL_ZAPF_DINGBATS
	};

	Font(Font_type ff) :f(ff) { }
	Font(int ff) :f(ff) { }

	int as_int() const { return f; }
private:
	int f;
};
//=====================================================================================================
template<class T> class Vector_ref {
	vector<T*> v;
	vector<T*> owned;
public:
	Vector_ref() {}

	Vector_ref(T* a, T* b=0, T* c=0, T* d=0)
	{
			if (a) push_back(a);
			if (b) push_back(b);
			if (c) push_back(c);
			if (d) push_back(d);
	}

	~Vector_ref() { for (int i=0; i<owned.size(); ++i) delete owned[i]; }

	void push_back(T& s) { v.push_back(&s); }
	void push_back(T* p) { v.push_back(p); owned.push_back(p); }

	// ???void erase(???)

	T& operator[](int i) { return *v[i]; }
	const T& operator[](int i) const { return *v[i]; }
	int size() const { return v.size(); }
};
//=====================================================================================================
typedef double Fct(double);
//=====================================================================================================
class Shape  {	// deals with color and style, and holds sequence of lines
protected:
	Shape() { }
	Shape(initializer_list<Point> lst);  // add() the Points to this Shape

//	Shape() : lcolor(fl_color()),
//		ls(0),
//		fcolor(Color::invisible) { }
	
	void add(Point p)
	{
		points.push_back(p);
	}

	void set_point(int i, Point p)
	{
		points[i] = p;
	}

public:
	void draw() const;					// deal with color and draw_lines
protected:
	virtual void draw_lines() const;	// simply draw the appropriate lines
public:
	virtual void move(int dx, int dy);	// move the shape +=dx and +=dy

	void set_color(Color col) { lcolor = col; }
	Color color() const { return lcolor; }

	void set_style(Line_style sty) { ls = sty; }
	Line_style style() const { return ls; }

	void set_fill_color(Color col) { fcolor = col; }

	Color fill_color() const
	{
		return fcolor;
	}

	Point point(int i) const
	{
		return points[i];
	}

	int number_of_points() const
	{
		return int(points.size());
	}

	Point point_back() const
	{
		return points.back();
	}

	Point point_front() const
	{
		return points.front();
	}

	virtual ~Shape() { }
	/*
	struct Window* attached;
	Shape(const Shape& a)
		:attached(a.attached), points(a.points), line_color(a.line_color), ls(a.ls)
	{
		if (a.attached)error("attempt to copy attached shape");
	}
	*/
	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;
private:
	vector<Point> points;	// not used by all shapes
	Color lcolor{ 0 };
	Line_style ls {0};
	Color fcolor {Color::invisible};

//	Shape(const Shape&);
//	Shape& operator=(const Shape&);
};
//=====================================================================================================
struct Function : Shape {
	// the function parameters are not stored
	Function(Fct f, double r1, double r2, Point orig, int count = 100, double xscale = 25, double yscale = 25);
	//Function(Point orig, Fct f, double r1, double r2, int count, double xscale = 1, double yscale = 1);	
};
//=====================================================================================================
struct Fill {
	Fill() :no_fill(true), fcolor(0) { }
	Fill(Color c) :no_fill(false), fcolor(c) { }

	void set_fill_color(Color col) { fcolor = col; }
	Color fill_color() { return fcolor; }
protected:
	bool no_fill;
	Color fcolor;
};
//=====================================================================================================
struct Line : Shape
{
	Line()
	{ }

	Line(Point p1, Point p2)
	{
		add(p1);
		add(p2);
	}
};
//=====================================================================================================
struct Rectangle : Shape
{
	Rectangle(Point xy, int ww, int hh)
		:p{ xy }, w {ww}, h{ hh }
	{
		if (h <= 0 || w <= 0) error("Bad rectangle: non-positive side");
		add(xy);
	}

	Rectangle(Point x, Point y)
		:w{ y.x - x.x }, h{ y.y - x.y }
	{
		if (h<=0 || w<=0) error("Bad rectangle: first point is not top left");
		add(x);
	}
	void draw_lines() const;

//	void set_fill_color(Color col) { fcolor = col; }
//	Color fill_color() { return fcolor; }

	int height() const
	{ 
		return h;
	}

	int width() const
	{ 
		return w;
	}

	Point po() const
	{
		return p;
	}

private:
	int h;			// height
	int w;			// width
	Point p;
//	Color fcolor;	// fill color; 0 means "no fill"
};
struct Arc;
//=====================================================================================================
inline std::pair<Point, Point> rotate_triangle(Point &o, const double &side_a, const double &side_b, int &iter)
{
	double angle = iter * PI / 180;

	// point O == angle 90
	//	double x = o.x + side_a * cos(angle);
	//	double y = o.y + side_a * sin(angle);
	//	
	//	double x2 = o.x + side_b * sin(angle);
	//	double y2 = o.y - side_b * cos(angle);

	// point O == top point a


	Point psa(o.x, o.y + side_b);
	Point psb(o.x + side_a, o.y + side_b);

	double dx = psa.x - o.x;	// direct vector
	double dy = psa.y - o.y;
	double dx2 = psb.x - o.x;
	double dy2 = psb.y - o.y;

	double dist_d = std::sqrt(dx * dx + dy * dy);
	double dist_d2 = std::sqrt(dx2 * dx2 + dy2 * dy2);

	double vec_x = dx / dist_d;
	double vec_y = dy / dist_d;

	double vec_x2 = dx2 / dist_d2;
	double vec_y2 = dy2 / dist_d2;

	double ux_l2 = vec_x * cos(angle) - vec_y * sin(angle);
	double uy_l2 = vec_x * sin(angle) + vec_y * cos(angle);

	double ux_l3 = vec_x2 * cos(angle) - vec_y2 * sin(angle);
	double uy_l3 = vec_x2 * sin(angle) + vec_y2 * cos(angle);


	Point rotate1(o.x + ux_l2 * dist_d, o.y + uy_l2 * dist_d);
	Point rotate2(o.x + ux_l3 * dist_d2, o.y + uy_l3 * dist_d2);

	return { rotate1, rotate2 };
}
//=====================================================================================================
struct Triangle : Shape
{
	Triangle(Point xy, double side_a, double side_b, int rotate)
		: p{ xy }, sa(side_a), sb(side_b), angle(rotate)
	{
		add(xy);

		if (rotate != 0)
		{
			auto [psa, psb] = rotate_triangle(xy, side_a, side_b, rotate);
			add(psa);
			add(psb);
		}

		if (rotate == 0)
		{
			// point O == top point a
			Point psa(xy.x, xy.y + side_b);
			Point psb(xy.x + side_a, xy.y + side_b);
			
			
			// point O == angle 90
			//	Point psa(xy.x + side_a, xy.y);
			//	Point psb(xy.x, xy.y - side_b);
			add(psa);
			add(psb);
		}
	}

	void draw_lines() const;


private:
	Point p;
	double sa;
	double sb;
	int angle;
};
//=====================================================================================================
struct Lines : Shape
{	// indepentdent lines
	Lines()
	{}
	Lines(initializer_list<Point> lst)
		: Shape{ lst }
	{
		if (lst.size() % 2)
			error("odd number of points for Lines");

	}
	void draw_lines() const;

	void add(Point p1, Point p2)
	{
		Shape::add(p1);
		Shape::add(p2);
	}
};
//=====================================================================================================
struct Arc : Shape
{
	Arc(Point p, int rr, int ww, int hh, int s, int e)	// center ,radius, start, end
		: r{ rr }, w(ww), h(hh), start(s), end(e)

	{
		add(Point{ p.x - r, p.y - r });
	}

	Arc()
	{ }

	void draw_lines() const;

	Point center() const
	{
		return { point(0).x + r, point(0).y + r };
	}

	void set_radius(int rr)
	{
		r = rr;
	}

	int radius() const
	{
		return r;
	}

	void set_major(int ww) { w = ww; }
	int major() const { return w; }
	void set_minor(int hh) { h = hh; }
	int minor() const { return h; }

private:
	int w;
	int h;
	int r;
	int start;
	int end;
};
//=====================================================================================================
struct Star : Shape
{
	Star(Point &p, int as, int rr, int rot) // point center, amount top start, radius and rotate
		: amount_top(as), radius(rr), rotate(rot)
	{
		if (amount_top < 4) error("non-positive Star!");
		if (radius <= 0) error("non-positive Star!");

		double step = 360 / amount_top;

		for (int i = 0; i < amount_top; i++)
		{
			
			Point p_out = get_star_points_out(p, step, i);
			add(p_out);

			Point p_in = get_star_points_in(p, step, i);
			add(p_in);
		}
	}

	Point get_star_points_out(const Point &p, double &step, const int iter);
	Point get_star_points_in(const Point &p, double &step, const int iter);

	void draw_lines() const;

private:
	int amount_top;
	int radius;
	int height;
	int rotate;
};
//=====================================================================================================
struct Poly : Shape
{
	Poly(const initializer_list<Point> &lst)
		:Shape{ lst }
	{
		if (lst.size() <= 3) error("non-positive Polygonum");
	}

	void draw_lines() const;
};
//=====================================================================================================
inline Point side(Point &p, const int &dd, int &iter)
{
	double angle = iter * PI / 180;

	double x = p.x + dd * cos(angle);
	double y = p.y - dd * sin(angle);

	Point p1(x, y);

	return p1;
}
//=====================================================================================================
struct Regular_hexogon : Shape
{
	Regular_hexogon(Point xy, int dd, int as)	// point_center, distance, amount side
		:p{ xy }, d(dd), amount_side(as)
	{
		int angle = 360 / as;

		for (int i = 0; i < as * 2; i++)
		{
			int iter = i * angle;

			Point p = side(xy, dd, iter);
			add(p);
		}
	}

	void draw_lines() const;

	int distance() const
	{
		return d;
	}

	Point po() const
	{
		return p;
	}

private:
	Point p;
	int d;	//distance
	int amount_side;
};
//=====================================================================================================
struct Regular_hexogon_s : Shape
{
	Regular_hexogon_s(Point xy, int dd)	// point_center and distance to the first angle
		:p{ xy }, d(dd)
	{
		for (int i = 0; i < 6; i++)
		{
			int iter = i * 60;

			Point p = side(xy, dd, iter);
			add(p);
		}
	}

	void draw_lines() const;

	int distance() const
	{
		return d;
	}

	Point po() const
	{
		return p;
	}

private:
	Point p;
	int d;	//distance
};
//=====================================================================================================
bool intersect(Point p1, Point p2, Point p3, Point p4);
//=====================================================================================================
struct Open_polyline : Shape
{	// open sequence of lines
	using Shape::Shape;
	void add(Point p) { Shape::add(p); }
	void draw_lines() const;
};
//=====================================================================================================
struct Closed_polyline : Open_polyline
{	// closed sequence of lines
	using Open_polyline::Open_polyline;
	void draw_lines() const;
	
//	void add(Point p) { Shape::add(p); }
};
//=====================================================================================================
struct Polygon : Closed_polyline {	// closed sequence of non-intersecting lines
	using Closed_polyline::Closed_polyline;
	void add(Point p);
	void draw_lines() const;
};
//=====================================================================================================
struct Arrow : Shape
{
	Arrow(Point xy1, Point xy2, int l, int angle)
		:l1{ xy1, xy2 }, la(l), l2(nullptr), l3(nullptr)
	{
		auto [p1, p2] = calculation(xy1, xy2, l, angle);

		l2 = new Line(xy2, p1);
		l3 = new Line(xy2, p2);
	}

	~Arrow();

	static std::pair<Point, Point> calculation(const Point &xy1, const Point &xy2, const int &l, const int &angle_type);

	void draw_lines() const;
	void set_color(Color c);
	void set_style(Line_style ist);

private:
	Line l1, *l2, *l3;
	int la; //length feather arrow
};
//=====================================================================================================
struct Box : virtual Shape
{
	Box(Point xy_1, Point yx_1, Point xy_2, Point yx_2, Point xy_3, Point yx_3, Point xy_4, Point yx_4, Arc &a1, Arc &a2, Arc &a3, Arc &a4)
		: l1{ xy_1, yx_1 }, l2{ xy_2, yx_2 }, l3{ xy_3, yx_3 }, l4{ xy_4, yx_4 }, arc1{ &a1 }, arc2{ &a2 }, arc3{ &a3 }, arc4{ &a4 }
	{
		int temp_x = xy_2.x - yx_1.x;
		b_xy.x = xy_2.x + temp_x;
		int temp_y = xy_2.y - yx_1.y;
		b_xy.y = yx_1.y - temp_y;

		int p1 = a1.center().x - a1.major();
		int p2 = a1.center().y - a1.minor();
		int p3 = a4.center().x + a4.major();
		int p4 = a2.center().y + a2.minor();

			ww = p3 - p1;
			hh = p4 - p2;

			xp = xy_1.x;
			int yp_temp = xy_1.y - yx_4.y;
			yp = xy_1.y - yp_temp;
	}
	// Arc(Point p, int ww, int hh, int s, int e)
	void draw_lines() const;
	void set_color(Color c);
	void set_style(Line_style ist);

	Point text_box()
	{
		return b_xy;
	}
	int reth()
	{
		return hh;
	}
	int retw()
	{
		return ww;
	}

private:
	int hh;
	int ww;
	Line l1, l2, l3, l4;
	Arc *arc1, *arc2, *arc3, *arc4;
	Point b_xy;
	int xp, yp;
};
//=====================================================================================================
struct Text : virtual Shape
{
	Text(const string &s)			// for text_box
		: lab{ s }
	{ }

	// the point is the bottom left of the first letter
	Text(Point x, const string& s)
		: lab{ s }

	{
		add(x);
	}

	void draw_lines() const;

	void set_label(const string& s)
	{
		lab = s;
	}
	string label() const
	{
		return lab;
	}
	void set_font(Font f)
	{
		fnt = f;
	}
	Font font() const
	{
		return Font(fnt);
	}
	void set_font_size(int s)
	{
		fnt_sz = s;
	}
	int font_size() const
	{
		return fnt_sz;
	}
private:
	string lab;	// label
	Font fnt{ fl_font() };
	int fnt_sz{ (14<fl_size()) ? fl_size() : 14 };	// at least 14 point
};
//=====================================================================================================
struct Box_Text : Box, Text
{
	Box_Text(Point xy_1, Point yx_1, Point xy_2, Point yx_2, Point xy_3, Point yx_3, Point xy_4, Point yx_4,
		Arc &a1, Arc &a2, Arc &a3, Arc &a4, const string &t)

		: Box{ xy_1, yx_1, xy_2, yx_2, xy_3, yx_3, xy_4, yx_4, a1, a2, a3, a4 }, Text{ t }
	{
		add(text_box());
	}

	void draw_lines() const
	{
		Box::draw_lines();
		Text::draw_lines();
	}
};
//=====================================================================================================
struct Axis : Shape
{
	// representation left public
	enum Orientation { x, y, z };
	Axis(Orientation d, Point xy, int length, int nummber_of_notches=0, string label = "");

	void draw_lines() const;
	void move(int dx, int dy);

	void set_color(Color c);

	Text label;
	Lines notches;
//	Orientation orin;
//	int notches;
};
//=====================================================================================================
struct Circle : Shape
{
	Circle(Point p, int rr)	// center and radius
		: r{ rr }

	{
		add(Point{ p.x - r, p.y - r });
	}

	void draw_lines() const;

	Point center() const
	{
		return { point(0).x + r, point(0).y + r };
	}

	void set_radius(int rr)
	{
		r = rr;
	}

	int radius() const
	{
		return r;
	}

private:
	int r;
};
//=====================================================================================================
struct Ellipse : Shape
{
	Ellipse(Point p, int ww, int hh)	// center, min, and max distance from center
	:w{ ww }, h{ hh }
	{
		add(Point{ p.x - ww, p.y - hh });
	}

	void draw_lines() const;

	Point center() const
	{
		return{ point(0).x + w, point(0).y + h };
	}

	Point focus1() const { return{ center().x + int(sqrt(double(w*w - h*h))), center().y }; }
	Point focus2() const { return{ center().x - int(sqrt(double(w*w - h*h))), center().y }; }
	
	void set_major(int ww)
	{
		w = ww;
	}

	int major() const
	{
		return w;
	}

	void set_minor(int hh)
	{
		h = hh;
	}

	int minor() const
	{
		return h;
	}

private:
	int w;
	int h;
};
//=====================================================================================================

struct Mark : Text {
	static const int dw = 4;
	static const int dh = 4;
	Mark(Point xy, char c) : Text(Point(xy.x-dw, xy.y+dh),string(1,c)) {}
};
//=====================================================================================================
struct Marked_polyline : Open_polyline {
	Marked_polyline(const string& m) :mark(m) { }
	void draw_lines() const;
private:
	string mark;
};
//=====================================================================================================
//	struct Marks : Marked_polyline {
//		Marks(const string& m) :Marked_polyline(m)
//		{ set_color(Color(Color::invisible)); }
//	};
//=====================================================================================================
//	struct Mark : Marks {
//		Mark(Point xy, char c) : Marks(string(1,c)) {add(xy); }
//	};
//=====================================================================================================
//	struct Marks : Shape {
//		Marks(char m) : mark(string(1,m)) { }
//		void add(Point p) { Shape::add(p); }
//		void draw_lines() const;
//	private:
//		string mark;
//	};
//=====================================================================================================
struct Bad_image : Fl_Image {
	Bad_image(int h, int w) : Fl_Image(h,w,0) { }
	void draw(int x,int y, int, int, int, int) { draw_empty(x,y); }
};
//=====================================================================================================
struct Suffix {
	enum Encoding { none, jpg, gif, bmp };
};
//=====================================================================================================
Suffix::Encoding get_encoding(const string& s);
//=====================================================================================================
struct Image : Shape {
	Image(Point xy, string s, Suffix::Encoding e = Suffix::none);
	~Image() { delete p; }
	void draw_lines() const;
	void set_mask(Point xy, int ww, int hh) { w=ww; h=hh; cx=xy.x; cy=xy.y; }
	void move(int dx,int dy) { Shape::move(dx,dy); p->draw(point(0).x,point(0).y); }
private:
	int w,h,cx,cy; // define "masking box" within image relative to position (cx,cy)
	Fl_Image* p;
	Text fn;
};
//=====================================================================================================
}
#endif
