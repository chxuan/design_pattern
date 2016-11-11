#include <iostream>
#include <vector>

class tool
{
public:
    virtual ~tool() {}

    virtual void draw() = 0; 
};

class pdf : public tool
{
public:
    virtual void draw()
    {
        std::cout << "pdf draw" << std::endl;
    }
};

class doc : public tool
{
public:
    virtual void draw()
    {
        std::cout << "doc draw" << std::endl;
    }
};

class shape
{
public:
    virtual ~shape() {}

    void pain()
    {
        _tool->draw();    
    }

    tool* _tool;
};

class rectangle : public shape
{
public:
    rectangle()
    {
        std::cout << "rectangle" << std::endl;
    }
};

class circle : public shape
{
public:
    circle()
    {
        std::cout << "circle" << std::endl;
    }
};

int main()
{
    shape* s = new rectangle();
    s->_tool = new pdf();
    s->pain();

    shape* s2 = new circle();
    s2->_tool = new doc();
    s2->pain();

    delete s->_tool;
    delete s;
    delete s2->_tool;
    delete s2;
    return 0;
}
