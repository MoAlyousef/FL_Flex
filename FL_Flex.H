#include <FL/Fl_Group.H>
#include <FL/fl_types.h>

class WidgetVec {
    Fl_Widget** buf;
    size_t cap;
    size_t len;

public:
    WidgetVec();
    size_t size() const;
    Fl_Widget* at(size_t idx);
    Fl_Widget* operator[](size_t idx);
    void reserve(size_t sz);
    void push_back(Fl_Widget* w);
    ~WidgetVec();
};

struct Fl_Flex : public Fl_Group {
    static const uchar ROW = 0;
    static const uchar COLUMN = 1;

    Fl_Flex(uchar direction);
    Fl_Flex(int w, int h, uchar direction);
    Fl_Flex(int x, int y, int w, int h, uchar direction);
    Fl_Flex(int x, int y, int w, int h, const char* label = nullptr);

    virtual void end();
    virtual void resize(int x, int y, int w, int h);

    void setSize(Fl_Widget* w, int size);

    void margin(int m) { _margin = m; }

    int margin() const { return _margin; }

    void pad(int p) { _pad = p; }

    int pad() const { return _pad; }

    static void setDebug(bool val) { _debug = val; }

private:
    int _margin = 0;
    int _pad = 5;
    static bool _debug;

    WidgetVec setsized;

    void debug();
    void resizeRow(int x, int y, int w, int h);
    void resizeCol(int x, int y, int w, int h);

    bool isSetSize(Fl_Widget* w);
};
