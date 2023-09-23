#include <iostream>
#include <vector>

template<typename T>
class Iterator
{
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
};

//
template<typename T>
class ConcreteIterator : public Iterator<T>
{

private:
    std::vector<T> collisions;
    int Position;
public:
    ConcreteIterator(const std::vector<T>& coll)
        :collisions(coll),Position(0)
    {
    }

    T next() override
    {
        T current = collisions[Position];
        Position++;
        return current;
    }

    bool hasNext() override
    {
        return Position < collisions.size();
    }
};

template<typename T>
class Aggregate
{
public:
    virtual Iterator<T>* CreateIterator() = 0;
};

template<typename T>
class ConcreteAggregate : public Aggregate<T>
{
private:
    std::vector<T> collisions;

public:
    ConcreteAggregate(const std::vector<T>& coll)
    :collisions(coll)
    {

    }

    Iterator<T>* CreateIterator() override
    {
        return new ConcreteIterator<T>(collisions);
    }


};



int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    ConcreteAggregate<int> aggregate(numbers);
    Iterator<int>* iterator = aggregate.CreateIterator();

    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    delete iterator;
   
    return 0;
}