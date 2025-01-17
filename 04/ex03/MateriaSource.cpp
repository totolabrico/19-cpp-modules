#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0 ; i < 4; i++)
        _inventory[i] = NULL;
    //std::cout << "MateriaSource default constructor called" << std::endl;
};

MateriaSource::MateriaSource(MateriaSource const &src)
{
    //std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0 ; i < 4; i++)
        _inventory[i] = NULL;
    *this = src;
};

MateriaSource::~MateriaSource()
{
    for (int i = 0 ; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
    }
    //std::cout << "MateriaSource destructor called" << std::endl;
};

MateriaSource &MateriaSource::operator=(MateriaSource const & src)
{
    //std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if(this == &src)
        return *this;
    for (int i = 0 ; i < 4; i++)
    {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        _inventory[i] = src._inventory[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if(!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i] == NULL)
        {
            _inventory[i] = m;
            /*std::cout << "MateriaSource: "
            << " equip inventory at index "
            << i << " in inventory" << std::endl;*/
            return;
        }
    }
    delete m;
    std::cout << "MateriaSource: Inventory is full!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if(_inventory[i] != NULL && _inventory[i]->getType() == type)
        {
            return _inventory[i]->clone();
        }
    }
    return(NULL);
}
