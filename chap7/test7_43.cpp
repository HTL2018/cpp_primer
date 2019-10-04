#include <vector>

class Nodefault
{
    public:
        Nodefault(int i) {  }
};

class C {
    public:
        C() : def(0) {  }
    private:
        Nodefault def;
};

int main()
{
    C c;

    std::vector<C> vec(10);

    return 0;
}
