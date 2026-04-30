#include "PPP/Point.h"
#include "PPP/Simple_window.h"
#include "PPP/Graph.h"
#include "PPP/GUI.h"
#include "PPP/Window.h"
//=======================================================================================================
int main()
{
	Simple_window win9I(Point(0, 0), 1200, 800, "Hello");
	
	Vector_ref<Star> star;

	for (int i = 0; i < 20; i++)
	{
		star.push_back(new Star(Point(200 + i * 25, 200 + i * 25), 5 + i, 25 + i * 3, 1 + i * 10));
		star[star.size() - 1].set_color(Color(i + 16 * 2));
		star[star.size() - 1].set_fill_color(Color(i * 20 + 16 * 2));

		win9I.attach(star[star.size() - 1]);
	}

	win9I.wait_for_button();
}
//=======================================================================================================
/*

//=======================================================================================================
	V	19. Определите класс Star. Одним из его параметров должно быть количество точек
Нарисуйте несколько звездочек с разным количеством точек, разноцветными линиями и разными цветами заполнения.
//=======================================================================================================
	Vector_ref<Star> star;

	for (int i = 0; i < 20; i++)
	{
		star.push_back(new Star(Point(200 + i * 25, 200 + i * 25), 5 + i, 25 + i * 3, 1 + i * 10));
		star[star.size() - 1].set_color(Color(i + 16 * 2));
		star[star.size() - 1].set_fill_color(Color(i * 20 + 16 * 2));

		win9I.attach(star[star.size() - 1]);
	}
//=======================================================================================================
	V	18. Определите класс Poly, представляющий многоугольник, так, чтобы его конструктор проверял,
действительно ли его точки образуют многоугольник. Подсказка: вы должны передавать в конструктор координаты точек.
//=======================================================================================================
Point p1(160, 200);
	Point p2(160, 310);
	Point p3(320, 390);
	Point p4(335, 200);

	Poly pol{ p1, p2, p3, p4 };
	pol.set_style(Line_style(Line_style::solid, 3));
	pol.set_fill_color(Color::green);
	win9I.attach(pol);
//=======================================================================================================
	V	17. Покройте окно узорами в виде маленьких разноцветных шестиугольников.
//=======================================================================================================
	int x_size = win9I.x_max();
	int y_size = win9I.y_max();
	win9I.wait_for_button();

	Point center(0, 0);
	Vector_ref<Regular_hexogon> rh;

	for (int i = 0; i < x_size; ++i)
	{
		for (int j = 0; j < y_size; ++j)
		{
			rh.push_back(new Regular_hexogon(Point(center.x, center.y), 15, 6));
			rh[rh.size() - 1].set_fill_color(Color(i * 1 + j));
			rh[rh.size() - 1].set_style(Line_style(Line_style::solid, 2));
			win9I.attach(rh[rh.size() - 1]);
			center.y += 30;
		}
	center.x += 30;
	center.y = 0;
	}
//=======================================================================================================
	V	16. Покройте окно узорами в виде маленьких шестиугольников.
//=======================================================================================================
	int x_size = win9I.x_max();
	int y_size = win9I.y_max();
	win9I.wait_for_button();

	Point center(0, 0);
	Vector_ref<Regular_hexogon> rh;

	for (int i = 0; i < x_size; ++i)
	{
		for (int j = 0; j < y_size; ++j)
		{
			rh.push_back(new Regular_hexogon(Point(center.x, center.y), 15, 6));
			rh[rh.size() - 1].set_fill_color(Color(i * 1 + j));
			rh[rh.size() - 1].set_style(Line_style(Line_style::solid, 2));
			win9I.attach(rh[rh.size() - 1]);
			center.y += 30;
		}
	center.x += 30;
	center.y = 0;
	}
//=======================================================================================================
	V	15. Покройте окно узорами в виде маленьких прямоугольных треугольников.
//=======================================================================================================
	int x_size = win9I.x_max();
	int y_size = win9I.y_max();
	win9I.wait_for_button();
	Point center(0, 0);
	Vector_ref<Triangle> tr;

	for (int i = 0; i < x_size; ++i)
	{
		for (int j = 0; j < y_size; ++j)
		{
			tr.push_back(new Triangle(Point(center.x, center.y), 10, 15, 0));
			tr[tr.size() - 1].set_fill_color(Color(i * 1 + j));
			tr[tr.size() - 1].set_style(Line_style(Line_style::solid, 2));
			win9I.attach(tr[tr.size() - 1]);
			center.y += 15;
		}
	center.x += 10;
	center.y = 0;
	}
//=======================================================================================================
	V	14. Определите класс для прямоугольного треугольника.
Составьте восьмиугольник из восьми прямоугольных треугольников разного цвета.
//=======================================================================================================
Vector_ref<Triangle> tr;

for (int i = 0; i < 8; ++i)
		{
			tr.push_back(new Triangle(Point(500, 600), 100, 150, i * 45));
			tr[tr.size() - 1].set_fill_color(Color(i * 16 + 1));
			tr[tr.size() - 1].set_style(Line_style(Line_style::solid, 2));
			win9I.attach(tr[tr.size() - 1]);
		}
//=======================================================================================================
	V	13. Нарисуйте матрицу цвета из раздела 13.10, но без линий, окаймляющих каждый квадрат.
//=======================================================================================================
Vector_ref<Rectangle> vr;
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j)
		{
			vr.push_back(new Rectangle(Point(i * 20, j * 20), 20, 20));
			vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
			vr[vr.size() - 1].set_style(Line_style(Line_style::none));
			win9I.attach(vr[vr.size() - 1]);
		}

//=======================================================================================================
	V	12. Нарисуйте окружность. Заставьте метку перемещаться по окружности
(пусть она перемещается каждый раз, когда вы щелкаете на кнопке Next).
//=======================================================================================================
Circle circ(Point(300, 300), 150);
	circ.set_style(Line_style(Line_style::solid, 2));

	win9I.attach(circ);


	for (int i = 0; i < 10000000; i += 10)
	{
		Circle circus(side(Point(300, 300), 150, i), 3);
		circus.set_fill_color(Color::black);
		circus.set_style(Line_style(Line_style::solid, 1));

		win9I.attach(circus);

		win9I.wait_for_button();
	}
//=======================================================================================================
	V	11. Нарисуйте эллипс размером 300×200 пикселей.
Нарисуйте ось x длиной 400 пикселей и ось y размером 300 пикселей, проходящие через центр эллипса.

Пометьте фокусы. Отметьте точку на эллипсе, которая не принадлежит ни одной из осей.
Соедините эту точку с фокусами двумя линиями.
//=======================================================================================================

	Ellipse el(Point(400, 250), 150, 100);
	el.set_style(Line_style(Line_style::solid, 3));

	Point ax(el.center().x - 200, el.center().y);
	Point ay(el.center().x, el.center().y + 150);

	Axis x(Axis::Orientation::x, ax, 400, 25, "X");
	x.set_style(Line_style(Line_style::solid, 2));

	Axis y(Axis::Orientation::y, ay, 300, 25, "Y");
	y.set_style(Line_style(Line_style::solid, 2));

	Point f1(el.focus1());
	Point f2(el.focus2());

	Point fxy(475, 280);

	Line lf1(fxy, f1);
	Line lf2(fxy, f2);
	lf1.set_style(Line_style(Line_style::solid, 2));
	lf2.set_style(Line_style(Line_style::solid, 2));

	win9I.attach(el);
	win9I.attach(x);
	win9I.attach(y);

	win9I.attach(lf1);
	win9I.attach(lf2);

//=======================================================================================================
	V	10. Определите класс Regular_hexagon.
В качестве аргументов конструктора используйте центр, количество сторон (не меньше двух) и расстояние от центра до угла.
//=======================================================================================================
Regular_hexogon rh(Point(200, 200), 50, 9);
	rh.set_style(Line_style(Line_style::solid, 3));
	rh.set_fill_color(Color::dark_red);

	win9I.attach(rh);
//=======================================================================================================
	V	9. Покройте часть окна узорами в виде объектов класса Regular_hexagon (используйте не меньше восьми шестиугольников).
//=======================================================================================================
	V	8. Определите класс Regular_hexagon (шестиугольник — это правильный шестисторонний многоугольник).
В качестве аргументов конструктора используйте центр и расстояние от центра до угловой точки.
//=======================================================================================================

	Regular_hexogon_s rh(Point(200, 200), 50);
	rh.set_style(Line_style(Line_style::solid, 3));
	rh.set_fill_color(Color::dark_red);

	win9I.attach(rh);
//=======================================================================================================
	V	7. Создайте цветную диаграмму RGB (поищите пример в вебе).
//=======================================================================================================
	Circle circ_R(Point(600, 180), 160);
	circ_R.set_style(Line_style(Line_style::solid, 5));
	circ_R.set_color(Color::black);
	circ_R.set_fill_color(Color::red);

	Circle circ_G(Point(490, 360), 160);
	circ_G.set_style(Line_style(Line_style::solid, 5));
	circ_G.set_color(Color::black);
	circ_G.set_fill_color(Color::green);

	Circle circ_B(Point(710, 360), 160);
	circ_B.set_style(Line_style(Line_style::solid, 5));
	circ_B.set_color(Color::black);
	circ_B.set_fill_color(Color::blue);

	Arc arc_B(Point(710, 360), 160, 160, 160, 50, 180);
	arc_B.set_style(Line_style(Line_style::solid, 5));

	Arc arc_G(Point(490, 360), 160, 160, 160, 180, -50);
	arc_G.set_style(Line_style(Line_style::solid, 5));


	win9I.attach(circ_G);
	win9I.attach(circ_B);
	win9I.attach(circ_R);

	win9I.attach(arc_B);
	win9I.attach(arc_G);

//=======================================================================================================
	V	6. Напишите программу, рисующую диаграмму классов, похожую на ту, которая изображена в разделе 12.6.
Программировать будет проще, если начать с определения класса Box,
объект которого представляет собой прямоугольник с текстовой меткой.
//=======================================================================================================
#include <memory>
//=======================================================================================================
std::unique_ptr<Arrow> arrow_setting(Point &t1, Point &t2, const int &l, const int &r)
{
	auto ar = std::make_unique<Arrow>(t1, t2, l, r);
	ar->set_color(Color::black);
	ar->set_style(Line_style(Line_style::solid, 3));

	return ar;
}
//=======================================================================================================
std::unique_ptr<Box_Text> box_setting(Point &t1, Point &t2, Point &t3, Point &t4, Point &t5, Point &t6, Point &t7, Point &t8, Arc &a1, Arc &a2, Arc &a3, Arc &a4, const std::string &str)
{
	auto box_text = std::make_unique<Box_Text> (t1, t2, t3, t4, t5, t6, t7, t8, a1, a2, a3, a4, str);
	box_text->Box::set_color(Color::black);
	box_text->Box::set_style(Line_style(Line_style::solid, 3));
	box_text->Text::set_font_size(14);
	box_text->Text::set_font(FL_BOLD);
	box_text->Box::set_fill_color(Color::dark_yellow);

	return box_text;
}
//=======================================================================================================
//box-1(window)
	Point tl1(115, 45);Point tl2(115, 60);Point tl3(120, 64);Point tl4(185, 64);Point tl5(189, 62);Point tl6(189, 45);Point tl7(187, 40);Point tl8(120, 40);
	Arc arc1(Point(120, 45), 5, 5, 90, 180);Arc arc2(Point(120, 59), 5, 5, 180, 270);Arc arc3(Point(184, 59), 5, 5, 270, 360);Arc arc4(Point(184, 45), 5, 5, 0, 90);
	//box-2(Simple_window)
	Point ml1(90, 135);Point ml2(90, 155);Point ml3(95, 159);Point ml4(218, 159);Point ml5(222, 157);Point ml6(222, 137);Point ml7(220, 133);Point ml8(95, 133);
	Arc mrc1(Point(95, 138), 5, 5, 90, 180);Arc mrc2(Point(95, 154), 5, 5, 180, 270);Arc mrc3(Point(217, 154), 5, 5, 270, 360);Arc mrc4(Point(217, 138), 5, 5, 0, 90);
	//box-3(Line_style)
	Point sl1(250, 45); Point sl2(250, 60); Point sl3(255, 64); Point sl4(341, 64); Point sl5(345, 62); Point sl6(345, 45); Point sl7(343, 40); Point sl8(255, 40);
	Arc src1(Point(255, 45), 5, 5, 90, 180); Arc src2(Point(255, 59), 5, 5, 180, 270); Arc src3(Point(340, 59), 5, 5, 270, 360); Arc src4(Point(340, 45), 5, 5, 0, 90);
	//box-4(Color)
	Point gl1(365, 45); Point gl2(365, 60); Point gl3(370, 64); Point gl4(416, 64); Point gl5(420, 62); Point gl6(420, 45); Point gl7(418, 40); Point gl8(370, 40);
	Arc grc1(Point(370, 45), 5, 5, 90, 180); Arc grc2(Point(370, 59), 5, 5, 180, 270); Arc grc3(Point(415, 59), 5, 5, 270, 360); Arc grc4(Point(415, 45), 5, 5, 0, 90);
	//box-5(Shape)
	Point ql1(278, 117); Point ql2(278, 137); Point ql3(283, 141); Point ql4(338, 141); Point ql5(342, 139); Point ql6(342, 119); Point ql7(340, 115); Point ql8(283, 115);
	Arc qrc1(Point(283, 120), 5, 5, 90, 180); Arc qrc2(Point(283, 136), 5, 5, 180, 270); Arc qrc3(Point(337, 136), 5, 5, 270, 360); Arc qrc4(Point(337, 120), 5, 5, 0, 90);
	//box-6(Point)
	Point wl1(390, 136); Point wl2(390, 155); Point wl3(395, 159); Point wl4(445, 159); Point wl5(449, 157); Point wl6(449, 137); Point wl7(447, 133); Point wl8(395, 133);
	Arc wrc1(Point(395, 138), 5, 5, 90, 180); Arc wrc2(Point(395, 154), 5, 5, 180, 270); Arc wrc3(Point(444, 154), 5, 5, 270, 360); Arc wrc4(Point(444, 138), 5, 5, 0, 90);
	//box-7(Line)
	Point el1(30, 260); Point el2(30, 279); Point el3(35, 283); Point el4(85, 283); Point el5(89, 281); Point el6(89, 261); Point el7(87, 257); Point el8(35, 257);
	Arc erc1(Point(35, 262), 5, 5, 90, 180); Arc erc2(Point(35, 278), 5, 5, 180, 270); Arc erc3(Point(84, 278), 5, 5, 270, 360); Arc erc4(Point(84, 262), 5, 5, 0, 90);
	//box-8(Lines)
	Point rl1(105, 260); Point rl2(105, 279); Point rl3(110, 283); Point rl4(160, 283); Point rl5(164, 281); Point rl6(164, 261); Point rl7(162, 257); Point rl8(110, 257);
	Arc rrc1(Point(110, 262), 5, 5, 90, 180); Arc rrc2(Point(110, 278), 5, 5, 180, 270); Arc rrc3(Point(159, 278), 5, 5, 270, 360); Arc rrc4(Point(159, 262), 5, 5, 0, 90);
	//box-9(Polygon)
	Point yl1(180, 260); Point yl2(180, 279); Point yl3(185, 283); Point yl4(260, 283); Point yl5(264, 281); Point yl6(264, 261); Point yl7(262, 257); Point yl8(185, 257);
	Arc yrc1(Point(185, 262), 5, 5, 90, 180); Arc yrc2(Point(185, 278), 5, 5, 180, 270); Arc yrc3(Point(259, 278), 5, 5, 270, 360); Arc yrc4(Point(259, 262), 5, 5, 0, 90);
	//box-10(Axis)
	Point ul1(285, 260); Point ul2(285, 279); Point ul3(290, 283); Point ul4(340, 283); Point ul5(344, 281); Point ul6(344, 261); Point ul7(342, 257); Point ul8(290, 257);
	Arc urc1(Point(290, 262), 5, 5, 90, 180); Arc urc2(Point(290, 278), 5, 5, 180, 270); Arc urc3(Point(339, 278), 5, 5, 270, 360); Arc urc4(Point(339, 262), 5, 5, 0, 90);
	//box-11(Rectangle)
	Point il1(360, 260); Point il2(360, 279); Point il3(365, 283); Point il4(450, 283); Point il5(454, 281); Point il6(454, 261); Point il7(452, 257); Point il8(365, 257);
	Arc irc1(Point(365, 262), 5, 5, 90, 180); Arc irc2(Point(365, 278), 5, 5, 180, 270); Arc irc3(Point(449, 278), 5, 5, 270, 360); Arc irc4(Point(449, 262), 5, 5, 0, 90);
	//box-12(Text)
	Point ol1(473, 260); Point ol2(473, 279); Point ol3(478, 283); Point ol4(528, 283); Point ol5(532, 281); Point ol6(532, 261); Point ol7(530, 257); Point ol8(478, 257);
	Arc orc1(Point(478, 262), 5, 5, 90, 180); Arc orc2(Point(478, 278), 5, 5, 180, 270); Arc orc3(Point(527, 278), 5, 5, 270, 360); Arc orc4(Point(527, 262), 5, 5, 0, 90);
	//box-13(Image)
	Point pl1(548, 260); Point pl2(548, 279); Point pl3(553, 283); Point pl4(603, 283); Point pl5(607, 281); Point pl6(607, 261); Point pl7(605, 257); Point pl8(553, 257);
	Arc prc1(Point(553, 262), 5, 5, 90, 180); Arc prc2(Point(553, 278), 5, 5, 180, 270); Arc prc3(Point(602, 278), 5, 5, 270, 360); Arc prc4(Point(602, 262), 5, 5, 0, 90);

	//arrow1
	Point at1(154, 133); Point at2(154, 64);
	//arrow2
	Point ft1(57, 258); Point ft2(279, 139);
	//arrow3
	Point gt1(134, 258); Point gt2(289, 141);
	//arrow4
	Point ht1(221, 258); Point ht2(298, 141);
	//arrow5
	Point jt1(311, 258); Point jt2(311, 142);
	//arrow6
	Point kt1(405, 258); Point kt2(320, 142);
	//arrow7
	Point lt1(502, 258); Point lt2(332, 141);
	//arrow8
	Point pt1(576, 258); Point pt2(342, 139);

	auto box_text1 = box_setting(tl1, tl2, tl3, tl4, tl5, tl6, tl7, tl8, arc1, arc2, arc3, arc4, "Window");
	auto box_text2 = box_setting(ml1, ml2, ml3, ml4, ml5, ml6, ml7, ml8, mrc1, mrc2, mrc3, mrc4, "Simple_window");
	auto box_text3 = box_setting(sl1, sl2, sl3, sl4, sl5, sl6, sl7, sl8, src1, src2, src3, src4, "Line_style");
	auto box_text4 = box_setting(gl1, gl2, gl3, gl4, gl5, gl6, gl7, gl8, grc1, grc2, grc3, grc4, "Color");
	auto box_text5 = box_setting(ql1, ql2, ql3, ql4, ql5, ql6, ql7, ql8, qrc1, qrc2, qrc3, qrc4, "Shape");
	auto box_text6 = box_setting(wl1, wl2, wl3, wl4, wl5, wl6, wl7, wl8, wrc1, wrc2, wrc3, wrc4, "Point");
	auto box_text7 = box_setting(el1, el2, el3, el4, el5, el6, el7, el8, erc1, erc2, erc3, erc4, "Line");
	auto box_text8 = box_setting(rl1, rl2, rl3, rl4, rl5, rl6, rl7, rl8, rrc1, rrc2, rrc3, rrc4, "Lines");
	auto box_text9 = box_setting(yl1, yl2, yl3, yl4, yl5, yl6, yl7, yl8, yrc1, yrc2, yrc3, yrc4, "Polygon");
	auto box_text10 = box_setting(ul1, ul2, ul3, ul4, ul5, ul6, ul7, ul8, urc1, urc2, urc3, urc4, "Axis");
	auto box_text11 = box_setting(il1, il2, il3, il4, il5, il6, il7, il8, irc1, irc2, irc3, irc4, "Rectangle");
	auto box_text12 = box_setting(ol1, ol2, ol3, ol4, ol5, ol6, ol7, ol8, orc1, orc2, orc3, orc4, "Text");
	auto box_text13 = box_setting(pl1, pl2, pl3, pl4, pl5, pl6, pl7, pl8, prc1, prc2, prc3, prc4, "Image");

	//arrow from box2 to box1
	auto arrow1 = arrow_setting(at1, at2, 15, 10);
	//arrow Line
	auto arrow2 = arrow_setting(ft1, ft2, 15, 10);
	//arrow Lines
	auto arrow3 = arrow_setting(gt1, gt2, 15, 10);
	//arrow Polygon
	auto arrow4 = arrow_setting(ht1, ht2, 15, 10);
	//arrow Axis
	auto arrow5 = arrow_setting(jt1, jt2, 15, 10);
	//arrow Rectangle
	auto arrow6 = arrow_setting(kt1, kt2, 15, 10);
	//arrow Text
	auto arrow7 = arrow_setting(lt1, lt2, 15, 10);
	//arrow Image
	auto arrow8 = arrow_setting(pt1, pt2, 15, 10);



	win9I.attach(*box_text1);
	win9I.attach(*box_text2);
	win9I.attach(*box_text3);
	win9I.attach(*box_text4);
	win9I.attach(*box_text5);
	win9I.attach(*box_text6);
	win9I.attach(*box_text7);
	win9I.attach(*box_text8);
	win9I.attach(*box_text9);
	win9I.attach(*box_text10);
	win9I.attach(*box_text11);
	win9I.attach(*box_text12);
	win9I.attach(*box_text13);

	win9I.attach(*arrow1);
	win9I.attach(*arrow2);
	win9I.attach(*arrow3);
	win9I.attach(*arrow4);
	win9I.attach(*arrow5);
	win9I.attach(*arrow6);
	win9I.attach(*arrow7);
	win9I.attach(*arrow8);
//=======================================================================================================
	V	5. Определите функции из упр. 4 для классов Circle и Ellipse.
Поместите точки соединения на границах и внутри этих фигур,
но не за пределами окаймляющего их прямоугольника.
//=======================================================================================================
Point n(Circle &c)
{
	Point t(c.center());
	t.y -= c.radius();
	return t;
}
Point s(Circle &c)
{
	Point t(c.center());
	t.y += c.radius();
	return t;
}
Point e(Circle &c)
{
	Point t(c.center());
	t.x += c.radius();
	return t;
}
Point w(Circle &c)
{
	Point t(c.center());
	t.x -= c.radius();
	return t;
}
Point center(Circle &c)
{
	Point t(c.center());
	return t;
}
Point ne(Circle &c)		//45a
{
	Point t(c.center());
	double angle = 45;
	angle = angle * PI / 180;
	t.x += c.radius() * sin(angle);
	t.y -= c.radius() * cos(angle);
	return t;
}
Point se(Circle &c)		//135a
{
	Point t(c.center());
	double angle = 135;
	angle = angle * PI / 180;
	t.x -= c.radius() * sin(angle);
	t.y += c.radius() * cos(angle);

	return t;
}
Point sw(Circle &c)		//225a
{
	Point t(c.center());
	double angle = 225;
	angle = angle * PI / 180;
	t.x -= c.radius() * sin(angle);
	t.y += c.radius() * cos(angle);

	return t;
}
Point nw(Circle &c)		//315a
{
	Point t(c.center());
	double angle = 315;
	angle = angle * PI / 180;
	t.x += c.radius() * sin(angle);
	t.y -= c.radius() * cos(angle);

	return t;
}
//=======================================================================================================
Point n(Ellipse &e)
{
	Point t(e.center());
	t.y -= e.minor();
	return t;
}
Point s(Ellipse &e)
{
	Point t(e.center());
	t.y += e.minor();
	return t;
}
Point e(Ellipse &e)
{
	Point t(e.center());
	t.x += e.major();
	return t;
}
Point w(Ellipse &e)
{
	Point t(e.center());
	t.x -= e.major();
	return t;
}
Point center(Ellipse &e)
{
	Point t(e.center());
	return t;
}
Point ne(Ellipse &e)		//45a
{
	Point t(e.center());
	double angle = 45;
	angle = angle * PI / 180;
	t.x += e.major() * sin(angle);
	t.y -= e.minor() * cos(angle);
	return t;
}
Point se(Ellipse &e)		//135a
{
	Point t(e.center());
	double angle = 135;
	angle = angle * PI / 180;
	t.x -= e.major() * sin(angle);
	t.y += e.minor() * cos(angle);

	return t;
}
Point sw(Ellipse &e)		//225a
{
	Point t(e.center());
	double angle = 225;
	angle = angle * PI / 180;
	t.x -= e.major() * sin(angle);
	t.y += e.minor() * cos(angle);

	return t;
}
Point nw(Ellipse &e)		//315a
{
	Point t(e.center());
	double angle = 315;
	angle = angle * PI / 180;
	t.x += e.major() * sin(angle);
	t.y -= e.minor() * cos(angle);

	return t;
}

//=======================================================================================================
	V	4. Определите функции n(), s(), e(), w(), center(), ne(), se(), sw() и nw().
Каждая из них должна получать аргумент типа Rectangle и возвращать объект типа Point.
Эти функции должны определять точки соединения, расположенные на границах и внутри прямоугольника.
Например, nw(r) — это левый верхний угол объекта класса Rectangle с именем r.
//=======================================================================================================
Point n(Rectangle &r)
{
	Point t(r.po());
	t.y += r.width() / 2;

	return t;
}
Point s(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();
	t.y += r.height() / 2;

	return t;
}
Point e(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;
	t.y += r.height();

	return t;
}
Point w(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;

	return t;
}
Point center(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width() / 2;
	t.y += r.height() / 2;

	return t;
}
Point ne(Rectangle &r)
{
	Point t(r.po());
	t.y += r.height();

	return t;
}
Point se(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();
	t.y += r.height();

	return t;
}
Point sw(Rectangle &r)
{
	Point t(r.po());
	t.x += r.width();

	return t;
}
Point nw(Rectangle &r)
{
	return r.po();
}
//=======================================================================================================
	V	3. Определите класс Arrow, рисующий стрелки.

	Arrow ar(tl1, tl2, 100, 0);
	ar.set_color(Color::dark_green);
	ar.set_style(Line_style(Line_style::solid, 10));
	win9I.attach(ar);
//=======================================================================================================
	V	2. Нарисуйте окно с закругленными углами. Определите класс Box, состоящий из четырех линий и четырех дуг.

	Point tl1(50, 225);
	Point tl2(50, 475);

	Point tl3(75, 500);
	Point tl4(375, 500);

	Point tl5(400, 475);
	Point tl6(400, 225);

	Point tl7(375, 200);
	Point tl8(75, 200);

	Arc arc1(Point(75, 225), 25, 25, 90, 180);

	Arc arc2(Point(75, 465), 25, 25, 180, 270);

	Arc arc3(Point(365, 465), 25, 25, 270, 360);

	Arc arc4(Point(365, 225), 25, 25, 0, 90);

	Box box(tl1, tl2, tl3, tl4, tl5, tl6, tl7, tl8, arc1, arc2, arc3, arc4);
	box.set_color(Color::red);
	box.set_style(Line_style(Line_style::solid, 20));


//=======================================================================================================
	V	1. Определите класс Arc, рисующий часть эллипса.Подсказка: fl_arc().

	Arc arc(Point(200, 200), 100, 150, 30, 290);
	arc.set_style(Line_style(Line_style::solid, 2));
	arc.set_color(Color::dark_green);
	win9I.attach(arc);
	*/
//=======================================================================================================
/*
//=======================================================================================================
	//				Task:2
//										int x_size = win3.x_max();
//										int y_size = win3.y_max();
//										int xy_grid = 100;
//									
//										Lines grid;
//										for (int x = xy_grid; x < x_size; x += xy_grid)
//											grid.add(Point(x, 0), Point(x, y_size));
//										
//										for (int y = xy_grid; y < y_size; y += xy_grid)
//											grid.add(Point(0, y), Point(x_size, y));
//									
//										grid.set_style(Line_style(Line_style::solid, 2));
//										grid.set_color(Color(99));
//									
//										win3.attach(grid);
	//				Task:3
//					Simple_window win3(Point(100, 100), 800, 800, "Two lines");
//					int x_rect = 0;
//					int move_rect = 50;
//					int x_size = win3.x_max();
//					int y_size = win3.y_max();
//					win3.color(Color::black);
//				
//					for (int x = x_rect; x < x_size && x < y_size; x += move_rect)
//					{
//						Rectangle rect(Point(x, x), 50, 50);
//						rect.set_style(Line_style(Line_style::solid, 2));
//						rect.set_color(Color(99));
//						rect.set_fill_color(Color::red);
//						win3.attach(rect);
//					}
//				
//					win3.wait_for_button();
//				}
	////////////////////////////////////////////////////////////////////////////////////////////////
//												Vector_ref<Rectangle> rect;
//												Rectangle x(Point(100, 200), Point(200, 300));
//												rect.push_back(x);
//												rect.push_back(new Rectangle(Point(50, 60), Point(80, 90)));
//											
//												for (int i = 0; i < rect.size(); ++i)
//												{
//													rect[i].move(10, 10);
//													win3.attach(rect[i]);
//												}
//					
//									Vector_ref<Rectangle> vr;
//								
//									for (int i = 0; i < 16; ++i)
//									{
//										for (int j = 0; j < 16; ++j)
//										{
//											vr.push_back(new Rectangle(Point(i * 40, j * 40), 40, 40));
//					
//											vr[vr.size() - 1].set_fill_color(Color(i * 16 + j));
//										}
//									}
//=======================================================================================================/*
//											// рисуем две линии
//											int x_size = win3.x_max(); // определяем размер нашего окна
//											int y_size = win3.y_max();
//											int x_grid = 80;
//											int y_grid = 40;
//											
//											Lines grid;
//											for (int x = x_grid; x < x_size; x += x_grid)
//												grid.add(Point(x, 0), Point(x, y_size)); // вертикальная линия
//											
//											for (int y = y_grid; y < y_size; y += y_grid)
//												grid.add(Point(0, y), Point(x_size, y)); // горизонтальная линия
//											
//											grid.set_style(Line_style(Line_style::dash, 2));
//											grid.set_color(Color(99));
//											
//											Closed_polyline cpl;
//											cpl.add(Point(100, 100));
//											cpl.add(Point(150, 200));
//											cpl.add(Point(250, 250));
//											cpl.add(Point(300, 200));
//											cpl.add(Point(100, 250));
//											cpl.set_style(Line_style(Line_style::solid, 4));
//											cpl.set_color(Color::red);
//											win3.attach(cpl);
//											
//											//	Polygon poly;
//											//	poly.add(Point(100, 100));
//											//	poly.add(Point(150, 200));
//											//	poly.add(Point(250, 250));
//											//	poly.add(Point(300, 200));
//											//	poly.set_style(Line_style(Line_style::solid, 4));
//											//	poly.set_color(Color::red);
//											//	win3.attach(poly);
//											
//											Text t(Point(200, 200), "A closed polyline that isn't a polygon");
//											t.set_color(Color::blue);
//											win3.attach(t);
//											
//											win3.attach(grid);

//								Rectangle rect00(Point(150, 100), 200, 100);
//								Rectangle rect11(Point(50, 50), Point(250, 150));
//								Rectangle rect12(Point(50, 150), Point(250, 250));
//								Rectangle rect21(Point(250, 50), 200, 100);
//								Rectangle rect22(Point(250, 150), 200, 100);
//									// 447 page
//								rect00.set_fill_color(Color::yellow);
//								rect11.set_fill_color(Color::blue);
//								rect11.move(400, 0); // вправо от rect21
//								rect11.set_fill_color(Color::white);
//								
//								win3.set_label("rectangles 2");
//							
//								rect12.set_fill_color(Color::red);
//								rect21.set_fill_color(Color::green);
//							
//								win3.attach(rect00);
//								win3.attach(rect11);
//								win3.attach(rect12);
//								win3.attach(rect21);
//							
//								win3.put_on_top(rect00);
//							
//								rect00.set_color(Color::invisible);
//								rect11.set_color(Color::invisible);
//								rect12.set_color(Color::invisible);
//								rect21.set_color(Color::invisible);
//								rect22.set_color(Color::invisible);
//							
//								Vector_ref<Rectangle> rect;
//								Rectangle x(Point(100, 200), Point(200, 300));
//								rect.push_back(x);
//								rect.push_back(new Rectangle(Point(50, 60), Point(80, 90)));
//							
//								for (int i = 0; i < rect.size(); ++i)
//									rect[i].move(10, 10);
//							
//								win3.attach(x);

//					Vector_ref<Rectangle> vr;
//				
//					for (int i = 0; i < 16; ++i)
//						for (int j = 0; j < 16; ++j)
//						{
//							vr.push_back(new Rectangle(Point(i * 40, j * 40), 40, 40));
//				
//							vr[vr.size()-1].set_fill_color(Color(i * 16 + j));
//				
//							win3.attach(vr[vr.size()-1]);
//						}

//			Circle c1(Point(100, 200), 50);
//			Circle c2(Point(150, 200), 100);
//			Circle c3(Point(200, 200), 150);
//			win3.attach(c1);
//			win3.attach(c2);
//			win3.attach(c3);

//										Ellipse e1(Point(200, 200), 50, 50);
//										Ellipse e2(Point(200, 200), 100, 50);
//										Ellipse e3(Point(200, 200), 100, 150);
//										win3.attach(e1);
//										win3.attach(e2);
//										win3.attach(e3);
//		
//										Ellipse e4(Point(600, 200), 50, 50);
//										Ellipse e5(Point(600, 200), 100, 50);
//										Ellipse e6(Point(600, 200), 100, 150);
//										win3.attach(e4);
//										win3.attach(e5);
//										win3.attach(e6);

//			Marked_polyline mpl("1234");
//			mpl.add(Point(100, 100));
//			mpl.add(Point(150, 200));
//			mpl.add(Point(250, 250));
//			mpl.add(Point(300, 200));
//			win3.attach(mpl);


//	Marks pp("x");
//	pp.add(Point(100, 100));
//	pp.add(Point(150, 200));
//	pp.add(Point(250, 250));
//	pp.add(Point(300, 200));
//	win3.attach(pp);

//		Image rita(Point(0, 0), "rita.jpg");
//		Image path(Point(0, 0), "rita_path.gif");
//		path.set_mask(Point(50, 250), 600, 400); // выбираем желательную область
//		win3.attach(path);
//		win3.attach(rita);
//=======================================================================================================
/*
//=======================================================================================================
	8. Нарисуйте пять олимпийских колец. Если помните их цвета, то раскрасьте их.
use fl_arc()
//=======================================================================================================
Point t1(100, 100);
	Point t2(200, 200);
	Point t3(325, 200);
	Point t4(450, 200);
	Point t5(390, 250);
	Point t6(265, 250);

	Simple_window win(t1, 800, 600, "MyHome");

	Circle c1(t2, 50);
	c1.set_style(Line_style(Line_style::solid, 10));
	c1.set_color(Color::blue);
	win.attach(c1);

	Circle c2(t3, 50);
	c2.set_style(Line_style(Line_style::solid, 10));
	c2.set_color(Color::black);
	win.attach(c2);

	Circle c3(t4, 50);
	c3.set_style(Line_style(Line_style::solid, 10));
	c3.set_color(Color::red);
	win.attach(c3);

	Circle c4(t5, 50);
	c4.set_style(Line_style(Line_style::solid, 10));
	c4.set_color(Color::green);
	win.attach(c4);

	Circle c5(t6, 50);
	c5.set_style(Line_style(Line_style::solid, 10));
	c5.set_color(Color::yellow);
	win.attach(c5);

	win.wait_for_button();
//=======================================================================================================
	V	7. Нарисуйте двумерный дом анфас, как это делают дети: дверь, два окна и крыша с дымовой трубой.
Детали можете выбрать сами, можете даже нарисовать дымок из трубы.
//=======================================================================================================
	Point t1(200, 200);
	Point t2(240, 240);
	Point t3(440, 240);
	Point t4(325, 285);

	Point tl1(265, 240);
	Point tl2(265, 310);
	Point tl3(465, 240);
	Point tl4(465, 310);
	Point tl5(240, 275);
	Point tl6(290, 275);
	Point tl7(440, 275);
	Point tl8(490, 275);

	Simple_window win(t1, 800, 600, "MyHome");

	Polygon p1;
	p1.add(Point(135, 200));
	p1.add(Point(615, 200));
	p1.add(Point(365, 30));
	p1.set_style(Line_style(Line_style::solid, 5));
	p1.set_fill_color(Color::red);
	win.attach(p1);

	Rectangle r1(t1, 350, 200);
	r1.set_fill_color(Color::blue);
	r1.set_style(Line_style(Line_style::solid, 5));
	win.attach(r1);

	Rectangle r2(t2, 50, 70);
	r2.set_fill_color(Color::yellow);
	r2.set_style(Line_style(Line_style::solid, 3));
	win.attach(r2);

	Rectangle r3(t3, 50, 70);
	r3.set_fill_color(Color::yellow);
	r3.set_style(Line_style(Line_style::solid, 3));
	win.attach(r3);

	Line l1(tl1, tl2);
	l1.set_style(Line_style(Line_style::solid, 3));
	win.attach(l1);

	Line l2(tl3, tl4);
	l2.set_style(Line_style(Line_style::solid, 3));
	win.attach(l2);

	Line l3(tl5, tl6);
	l3.set_style(Line_style(Line_style::solid, 3));
	win.attach(l3);

	Line l4(tl7, tl8);
	l4.set_style(Line_style(Line_style::solid, 3));
	win.attach(l4);

	Rectangle r4(t4, 80, 115);
	r4.set_style(Line_style(Line_style::solid, 3));
	r4.set_fill_color(Color::dark_yellow);
	win.attach(r4);

	Polygon p2;
	p2.add(Point(459, 92));
	p2.add(Point(459, 15));
	p2.add(Point(480, 15));
	p2.add(Point(480, 108));
	p2.set_style(Line_style(Line_style::solid, 3));
	p2.set_fill_color(Color::black);
	win.attach(p2);

	Function sine1(sin, 0, 10, Point(474, 20), 5, 10, 20);
	sine1.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine1);

	Function sine2(sin, 0, 10, Point(469, 20), 5, 10, 20);
	sine2.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine2);

	Function sine3(sin, 0, 10, Point(464, 20), 5, 10, 20);
	sine3.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine3);

	Function sine4(sin, 0, 10, Point(459, 20), 5, 10, 20);
	sine4.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine4);

	Function sine5(sin, 0, 10, Point(458, 17), 5, 10, 20);
	sine5.set_style(Line_style(Line_style::solid, 2));
	win.attach(sine5);

	win.wait_for_button();
//=======================================================================================================
	V	6. Что произойдет, если вы нарисуете фигуру, которая не помещается в окне?
Что произойдет, если вы нарисуете окно, которое не помещается на экране?
Напишите две программы, иллюстрирующие эти эффекты.
//=======================================================================================================
	Point tl(-10, -10);
	Simple_window win(tl, 7500, 9200, "MyWindow");


	Rectangle r(tl, 70000, 100000);
	r.set_color(Color::blue);
	win.attach(r);
//=======================================================================================================
	V	5. Нарисуйте красную рамку шириной один дюйм вокруг прямоугольника,
высота которого составляет три четверти высоты вашего экрана, а ширина — две трети ширины экрана.
//=======================================================================================================
Point tl(50, 50);
	Point t2(49, 49);
	Simple_window win(tl, 600, 400, "MyWindow");

	int width = 600 / 1.5;
	int height = 400 - 100;

	Rectangle r(tl, width, height);
	r.set_color(Color::blue);
	win.attach(r);

	Rectangle r2(t2, width + 2, height + 2);
	r2.set_color(Color::red);
	win.attach(r2);
//=======================================================================================================
	V	4. Нарисуйте доску для игры в крестики-нолики размером 3×3, чередуя белые и красные квадраты.
//=======================================================================================================
Можно сделать через Rectangle

	Point t1(50, 50);
	Point t2(50, 100);
	Point t3(50, 150);
	Point t4(100, 50);
	Point t5(100, 100);
	Point t6(100, 150);
	Point t7(150, 50);
	Point t8(150, 100);
	Point t9(150, 150);
	Simple_window win(t1, 800, 600, "MyWindow");

	Rectangle r1(t1, 50, 50);
	r1.set_color(Color::red);
	r1.set_fill_color(Color::red);
	win.attach(r1);

	Rectangle r2(t2, 50, 50);
	r2.set_color(Color::white);
	r2.set_fill_color(Color::white);
	win.attach(r2);

	Rectangle r3(t3, 50, 50);
	r3.set_color(Color::red);
	r3.set_fill_color(Color::red);
	win.attach(r3);

	Rectangle r4(t4, 50, 50);
	r4.set_color(Color::white);
	r4.set_fill_color(Color::white);
	win.attach(r4);

	Rectangle r5(t5, 50, 50);
	r5.set_color(Color::red);
	r5.set_fill_color(Color::red);
	win.attach(r5);

	Rectangle r6(t6, 50, 50);
	r6.set_color(Color::white);
	r6.set_fill_color(Color::white);
	win.attach(r6);

	Rectangle r7(t7, 50, 50);
	r7.set_color(Color::red);
	r7.set_fill_color(Color::red);
	win.attach(r7);

	Rectangle r8(t8, 50, 50);
	r8.set_color(Color::white);
	r8.set_fill_color(Color::white);
	win.attach(r8);

	Rectangle r9(t9, 50, 50);
	r9.set_color(Color::red);
	r9.set_fill_color(Color::red);
	win.attach(r9);
	
	ИЛИ

Polygon poly_1;
	poly_1.add(Point(150, 200));
	poly_1.add(Point(150, 250));
	poly_1.add(Point(200, 250));
	poly_1.add(Point(200, 200));
	poly_1.set_color(Color::red);
	poly_1.set_fill_color(Color::red);
	win.attach(poly_1);

	Polygon poly_2;
	poly_2.add(Point(150, 250));
	poly_2.add(Point(150, 300));
	poly_2.add(Point(200, 300));
	poly_2.add(Point(200, 250));
	poly_2.set_color(Color::white);
	poly_2.set_fill_color(Color::white);
	win.attach(poly_2);

	Polygon poly_3;
	poly_3.add(Point(150, 300));
	poly_3.add(Point(150, 350));
	poly_3.add(Point(200, 350));
	poly_3.add(Point(200, 300));
	poly_3.set_color(Color::red);
	poly_3.set_fill_color(Color::red);
	win.attach(poly_3);

	Polygon poly_4;
	poly_4.add(Point(200, 200));
	poly_4.add(Point(200, 250));
	poly_4.add(Point(250, 250));
	poly_4.add(Point(250, 200));
	poly_4.set_color(Color::white);
	poly_4.set_fill_color(Color::white);
	win.attach(poly_4);

	Polygon poly_5;
	poly_5.add(Point(200, 250));
	poly_5.add(Point(200, 300));
	poly_5.add(Point(250, 300));
	poly_5.add(Point(250, 250));
	poly_5.set_color(Color::red);
	poly_5.set_fill_color(Color::red);
	win.attach(poly_5);

	Polygon poly_6;
	poly_6.add(Point(200, 300));
	poly_6.add(Point(200, 350));
	poly_6.add(Point(250, 350));
	poly_6.add(Point(250, 300));
	poly_6.set_color(Color::white);
	poly_6.set_fill_color(Color::white);
	win.attach(poly_6);

	Polygon poly_7;
	poly_7.add(Point(250, 200));
	poly_7.add(Point(250, 250));
	poly_7.add(Point(300, 250));
	poly_7.add(Point(300, 200));
	poly_7.set_color(Color::red);
	poly_7.set_fill_color(Color::red);
	win.attach(poly_7);

	Polygon poly_8;
	poly_8.add(Point(250, 250));
	poly_8.add(Point(250, 300));
	poly_8.add(Point(300, 300));
	poly_8.add(Point(300, 250));
	poly_8.set_color(Color::white);
	poly_8.set_fill_color(Color::white);
	win.attach(poly_8);

	Polygon poly_9;
	poly_9.add(Point(250, 300));
	poly_9.add(Point(250, 350));
	poly_9.add(Point(300, 350));
	poly_9.add(Point(300, 300));
	poly_9.set_color(Color::red);
	poly_9.set_fill_color(Color::red);
	win.attach(poly_9);
//=======================================================================================================
	V доп	2. Добавьте примеры из раздела 12.7 один за другим, сравнивая их друг с другом.
//=======================================================================================================
	V доп	3. Выполните программу, внеся небольшие изменения (например, измените цвет, местоположение фигур или количество точек) в каждом из примеров.
//=======================================================================================================
//=======================================================================================================
	V	1. Нарисуйте прямоугольник как объект класса Rectangle и как объект класса Polygon.
Сделайте линии объекта класса Polygon красными, а линии объекта класса Rectangle синими.
//=======================================================================================================
Rectangle r(tl, 300, 100);
	r.set_color(Color::dark_blue);
	win.attach(r);
	Polygon p;
	p.add(Point(200, 200));
	p.add(Point(300, 200));
	p.add(Point(300, 250));
	p.add(Point(200, 250));
	p.set_color(Color::dark_red);
	win.attach(p);
//=======================================================================================================
	V	2. Нарисуйте объект класса Rectangle с размерами 100×300 и поместите в него слово “Привет!”.
//=======================================================================================================
	Polygon p;
	p.add(Point(200, 200));
	p.add(Point(300, 200));
	p.add(Point(300, 250));
	p.add(Point(200, 250));
	p.set_color(Color::dark_red);
	win.attach(p);

	Text v(Point(220, 220), "HELLO");
	v.set_color(Color::dark_green);
	v.set_font_size(15);
	win.attach(v);
//=======================================================================================================
	V	3. Нарисуйте ваши инициалы высотой 150 пикселей. Используйте толстую линию. Нарисуйте каждый инициал другим цветом.
//=======================================================================================================
Text v(Point(120, 120), "V");
	v.set_style(Line_style(Line_style::solid, 20));
	v.set_color(Color::dark_green);
	v.set_font_size(150);
	win.attach(v);

	Text s(Point(240, 120), "S");
	s.set_style(Line_style(Line_style::solid, 20));
	s.set_color(Color::dark_blue);
	s.set_font_size(150);
	win.attach(s);

	Text r(Point(360, 120), "R");
	r.set_style(Line_style(Line_style::solid, 20));
	r.set_color(Color::dark_red);
	r.set_font_size(150);
	win.attach(r);
//=======================================================================================================
*/
