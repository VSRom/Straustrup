#include "GUI.h"

using namespace Graph_lib;

struct Simple_window : Window {
    // Конструктор — только объявление
    Simple_window(Point xy, int w, int h, const string &title);

    // Методы — только объявления
    bool wait_for_button();
    void next();

    Button next_button;

private:
    bool button_pushed;

    // Статическая функция — только объявление
    static void cb_next(Address, Address addr);
};
