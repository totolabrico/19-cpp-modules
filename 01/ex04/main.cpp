#include <iostream>
#include <fstream>

void sed(std::ifstream *in, std::ofstream *out, std::string needle, std::string newstr)
{
    std::string prov;
    char c;

    while(in->get(c))
    {
        if(c == needle[prov.length()])
        {
            prov += c;
            if(needle.length() == prov.length())
            {
                *out << newstr;
                prov.clear();
            }
        }
        else
        {
            *out << prov;
            *out << c;
            prov.clear();
        }
    };
}

int main(int argc, char **argv)
{
    std::ifstream ifs;
    std::ofstream ofs;
    std::string needle;
    std::string replace;
    std::string dest;

    if(argc != 4)
        return(1);
    ifs.open(argv[1]);
    if(!ifs.is_open())
        return(1);
    dest = std::string(argv[1]) + ".replace";
    ofs.open(dest.c_str()); 
    if(!ofs.is_open())
    {
        ifs.close();
        return(1);
    }
    needle = argv[2];
    replace = argv[3];
    sed(&ifs, &ofs, needle, replace);
    ifs.close();
    ofs.close();
    return(0);
}