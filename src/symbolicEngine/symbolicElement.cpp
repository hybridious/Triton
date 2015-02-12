
#include "SymbolicEngine.h"


SymbolicElement::SymbolicElement(std::stringstream &dst, std::stringstream &src, uint64_t id)
{
  //this->isTainted   = !TAINTED;
  this->source      = new std::stringstream(src.str());
  this->destination = new std::stringstream(dst.str());
  this->expression  = new std::stringstream();

  *this->expression << (*this->destination).str() << " = " << (*this->source).str();

  this->id = id;
}


SymbolicElement::~SymbolicElement()
{
  delete this->source;
  delete this->destination;
  delete this->expression;
}

/* Returns the SMT dst and src expression of the symbolic element */
std::stringstream *SymbolicElement::getExpression()
{
  return this->expression;
}

/* Returns the SMT src expression of the symbolic element */
std::stringstream *SymbolicElement::getSource()
{
  return this->source;
}

/* Returns the ID of the symbolic element */
uint64_t SymbolicElement::getID()
{
  return this->id;
}

