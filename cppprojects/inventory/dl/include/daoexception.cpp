#ifndef __$__daoexception__
#define __$__daoexception__ 123
#include<iostream>
using namespace std;
namespace inventory
{
namespace data_layer
{
class DAOException:public exception
{
string message;
public:
DAOException();
DAOException(string message);
DAOException(const DAOException &other);
virtual ~DAOException() throw();
DAOException & operator=(const DAOException &other);
const char *what() const throw();
};
}
}
#endif