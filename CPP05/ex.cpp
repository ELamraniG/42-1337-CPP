#include <iostream>
using namespace std;

class numbers
{
    public:
    int n;
    class numbertoolow : public exception
    {
        public :
            const char *what() const throw() 
            {
                return "shit\n";
            }
        
    };

};


int main()
{
    int n;
    cout << "Enter a number: \n";
    cin >> n;
    numbers numb;
    try{
        numb.n = n;
        if (numb.n < 0)
            throw (numbers::numbertoolow());
    }
    catch (const numbers::numbertoolow& e)
    {
        cout<< e.what();
    }
    return 0;
}