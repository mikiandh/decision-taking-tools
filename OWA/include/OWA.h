#ifndef _OWA_H_
#define _OWA_H_

#include "Criterion.h"
#include "Alternative.h"
#include <string>
#include <vector>
#include <memory>

// Global custom types
typedef std::vector<int> IntVector;
typedef std::vector<double> FloatVector;
typedef std::string string;
typedef std::vector<string> StringVector;

/* Interface class 
 * Provides acces to the OWA computation and its results
 */
class OWA
{
public:
  /* Constructor
   *
   * param "criteria": Array of pointers to criteria instances
   */
  OWA (const Criterion::Vector &criteria, const Alternative::Vector &candidates) :
      _numberOfCriteria (criteria.size ()), _numberOfCandidates (
	  candidates.size ()), _criteria (criteria), _candidates (candidates)
  {
  }

private:
  // Member variables
  const int _numberOfCriteria;
  const int _numberOfCandidates;
  const Criterion::Vector &_criteria;
  const Alternative::Vector &_candidates;
};

#endif // _OWA_H_ 
