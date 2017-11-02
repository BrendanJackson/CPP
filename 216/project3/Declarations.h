/*
|--------------------------------------------------------------------------
| Project #3 Details
|--------------------------------------------------------------------------
|
| Brendan Jackson
| 10/26/2017
| CS216
|
|
|
*/

/* Libraries
************************/
// contains definitions of cin, cout, endl, and input/output operators
#include <iostream>
// contains definition of string conversions
#include <string>
// set precision
#include <iomanip>
// Vectors
#include <vector>

//standard namespace
using namespace std;

/* Class Prototype
************************/
template <class Type>
class GenericRecord
{
private:
  Type structure;
  public:
  void setRecord(Type recordArg){structure = recordArg;};
  Type getRecord(){return structure;};

  //struct accessors
  template <typename dataType>
  void setIdentifier(dataType param){structure.Identifier = param;};

  template <typename dataType>
  void setDescription(dataType param){structure.Description = param;};

  template <typename dataType>
  void setValue(dataType param){structure.Value = param;};

};



/* Struct prototype
************************/
struct Furniture
{
public:
  int Identifier = 2;
  string Description = "string";
  float Value = 2.0;
};


struct Computer
{
public:
  long int Identifier;
  string Description;
  float Value;
};

struct Building
{
public:
    string Identifier;
    string Description;
    double Value;
};
