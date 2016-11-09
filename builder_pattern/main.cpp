#include <iostream>
#include <string>
#include <vector>

// 产品.
class product
{
public:
    void add(const std::string& product_name)
    {
        _product_name_vec.emplace_back(product_name);
    }

    void show()
    {
        for (auto& name : _product_name_vec)
        {
            std::cout << name << std::endl;
        }
    }

private:
    std::vector<std::string> _product_name_vec;
};

// 抽象建造者.
class builder
{
public:
    virtual ~builder() {}
    virtual void build_ricenoodles() = 0;
    virtual void build_cooldish() = 0;
    virtual void build_drink() = 0;
    virtual product* get_product() = 0;
};

// 建造者A.
class builder_a : public builder
{
public:
    builder_a()
    {
        _product = new product;
    }

    ~builder_a()
    {
        delete _product;
    }

    virtual void build_ricenoodles()
    {
        _product->add("ricenoodles a");
    }

    virtual void build_cooldish()
    {
        _product->add("cooldish a");
    }

    virtual void build_drink()
    {
        _product->add("drink a");
    }

    virtual product* get_product()
    {
        return _product;
    }

private:
    product* _product;
};

// 导演.
class director
{
public:
    void construct(builder* b)
    {
        b->build_ricenoodles();
        b->build_cooldish();
        b->build_drink();
    }
};

int main()
{
    director* d = new director();
    builder* b = new builder_a();
    d->construct(b);
    product* p = b->get_product();
    p->show();

    delete b;
    delete d;

    return 0;
}

