#include <stdexcept>
using namespace std;

class DZero : public runtime_error 
{
public:
   DZero()
      : runtime_error( "attempted to divide by zero" ) {}
}; 
