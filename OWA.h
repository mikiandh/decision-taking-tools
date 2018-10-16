// Include guards
#ifndef __OWA_H__
#define __OWA_H__

// Forward declared dependencies


// Included dependencies
#include <string>
#include <vector>
#include <memory>
#include "criterion.h"
#include "candidate.h"

// Interface class
class OWA
{
public:
  // Custom types
  typedef std::vector<int> IntVector;
  typedef std::vector<double> FloatVector;
  typedef std::vector<string> StringVector;
  typedef std::vector<std::unique_ptr<criterion>> CriteriaVector;

  // Constructor
  /*
   * param "criteria": Array of pointers to criteria instances
   *
   *
   */


private:
  // Member variables
  int numberOfCriteria;
  CriteriaVector criteria; 
  FloatVector weights;

}

#endif // __OWA_H__ 