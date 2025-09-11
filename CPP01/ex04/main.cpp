#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
    if (ac !=4)
    {
        std::cout<<"invalide number of parameters, should be 4 : prog name, filename, s1, s2"<<std::endl;
        return 0;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    if (s1.empty() == true)
    {
        std::cout<<"inter a valid string to be replaced"<<std::endl;
        return 0;
    }
    if (filename.empty() == true)
    {
        std::cout<<"no such file"<<std::endl;
        return 0;
    }
    std::string replace = filename + ".replace";
    std::ifstream input(filename);
    if (input.fail() == true)
    {
        std::cout<<"couldn't open file: "<<filename<<std::endl;
        input.close();
        return 0;
    }
    std::ofstream output(replace);
    if (output.fail() == true)
    {
        std::cout<<"couldn't open file: "<<replace<<std::endl;
        output.close();
        return 0;
    }
    std::string readin;
    int pos = 0;
    while (std::getline(input,readin))
    {
        pos = readin.find(s1, pos);
        while (pos != -1)
        {
            readin.erase(pos,s1.length());
            readin.insert(pos,s2);
            pos += s2.length();
            pos = readin.find(s1, pos);
        }
        pos = 0;
        output<<readin;
        if (input.eof() == false)
            output<<std::endl;
    }
    input.close();
    output.close();
}