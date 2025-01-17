#ifndef DATA_HPP
#define DATA_HPP
 
class Data
{
private:
    int _value;
public:
    Data();
    Data(Data const & src);
    ~Data();
    Data &operator=(Data const & src);
    int getValue() const;
};

#endif