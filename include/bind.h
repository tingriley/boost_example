
#ifndef __BIND__
#define __BIND__
#include <boost/bind/bind.hpp>
#include <boost/function.hpp>

using namespace std;

class button
{
public:
    boost::function<void(int x)> onClick;
};

class player
{
public:
    void play(int x);
    void stop(int x);
};
#endif
