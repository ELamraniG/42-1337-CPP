#include <iostream>

class dog{
    public:
    int n;

        dog(int e) : n(e)
        { 
            std::cout << "dog constructor" << std::endl;
        }
        // dog(dog &doggie)
        // { 
        //     this->n = doggie.n;
        //     std::cout << "dog conocpy " << std::endl;
        // }
        ~dog() 
        {
             std::cout << "dog destructor" << std::endl; 
        }
};

int main()
{
    dog d1(5);
    dog d2(d1);
        std::cout << d2.n << std::endl;
    return 0;
}