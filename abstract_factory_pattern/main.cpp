#include <iostream>

// 食草动物.
class herbivore
{
public:
    virtual ~herbivore() {}
};

// 食肉动物.
class carnivore
{
public:
    virtual ~carnivore() {}
    virtual void eat(herbivore* h) = 0;
};

// 角马.
class wildebeest : public herbivore
{
};

// 野牛.
class bison : public herbivore
{
};

// 狮子.
class lion : public carnivore
{
public:
    void eat(herbivore*)
    {
        std::cout << "lion eat wildebeest" << std::endl;
    }
};

// 狼.
class wolf : public carnivore
{
public:
    void eat(herbivore*)
    {
        std::cout << "wolf eat bison" << std::endl;
    }
};

// 抽象工厂.
class factory
{
public:
    virtual ~factory() {}
    // 创建食草动物.
    virtual herbivore* create_herbivore() = 0;
    // 创建食肉动物.
    virtual carnivore* create_carnivore() = 0;
};

// 非洲工厂.
class africa_factory : public factory
{
public:
    virtual herbivore* create_herbivore()
    {
        return new wildebeest();
    }

    virtual carnivore* create_carnivore()
    {
        return new lion();
    }
};

// 美洲工厂.
class america_factory : public factory
{
public:
    virtual herbivore* create_herbivore()
    {
        return new bison();
    }

    virtual carnivore* create_carnivore()
    {
        return new wolf();
    }
};

// 动物世界（客户端）.
class animal_world
{
public:
    animal_world(factory* f)
    {
        _herbivore = f->create_herbivore(); 
        _carnivore = f->create_carnivore();
    }

    void start()
    {
        _carnivore->eat(_herbivore);
    }

private:
    herbivore* _herbivore;
    carnivore* _carnivore;
};

int main()
{
    factory* factory1 = new africa_factory();
    animal_world* world1 = new animal_world(factory1);
    world1->start();

    factory* factory2 = new america_factory();
    animal_world* world2 = new animal_world(factory2);
    world2->start();

    delete factory1;
    delete world1;
    delete factory2;
    delete world2;

    return 0;
}

