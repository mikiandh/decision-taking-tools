/*
 * OWA.h
 *
 *  Created on: Oct 28, 2018
 *      Author: miquel
 */

#ifndef _OWA_H_
#define _OWA_H_

#include <vector>
#include <iostream>
#include <iomanip>
#include "Criterion.h"
#include "Alternative.h"

/*
 * Provides acces to the OWA computation and its results
 */
class OWA
{
public:
  // Type definitions
  typedef std::string String;
  typedef std::vector<double> VectorDouble;
  typedef std::vector<std::vector<double> > MatrixDouble;

  /*
   * Constructor
   */
  OWA() :
      _I(0), _J(0)
  {
  }

  /*
   * Destructor
   */
  virtual ~OWA();

  void Append(const Criterion * criterion);

  void Append(const InverseCriterion * criterion);

  void Append(const Alternative * alternative);

  bool CheckData() const;

  void PrintData() const;

  void Compute();

  void PrintMatrix() const;

  void PrintVector() const;

protected:

  unsigned int _I; // number of criteria
  unsigned int _J; // number of alternatives
  VectorDouble _owaVector;
  MatrixDouble _owaMatrix;
  Criterion::Vector _criteria;
  Alternative::Vector _alternatives;
};

#endif // _OWA_H_ 
