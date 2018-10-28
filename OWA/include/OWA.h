// Include guards
#ifndef _OWA_H_
#define _OWA_H_

// Included dependencies
#include <string>
#include <vector>
#include <memory>
//#include "criterion.h"
//#include "candidate.h"

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
  OWA(const Criterion::Vector &criteria, const Candidate::Vector &candidates) :
    _numberOfCriteria(criteria.size()), _numberOfCandidates(candidates.size()), _criteria(criteria),
    _candidates(candidates) {}

private:
  // Member variables
  const int _numberOfCriteria;
  const int _numberOfCandidates;
  const Criterion::Vector &_criteria;
  const Candidate::Vector &_candidates;
};

// Characteristic common among all candidates to be used in the OWA procedure to compare them
class Criterion
{
public:
  // Vector type
  typedef std::vector<std::unique_ptr<Criterion>> Vector;

  /* Constructor
   *
   * param "name": Name of the criterion
   * param "weight" Weight of the criterion
   */
  Criterion(const string &name, const double weight) : _name(name), _weight(weight) {}

private:
  // Member variables
  const string _name;
  const double _weight;
};

// Negative criterion (higher score is worse)
class NCriterion : public Criterion
{
public:
  /* Constructor
   *
   * param "name": Name of the criterion
   * param "weight": Weight of the criterion
   */
  NCriterion(const string &name, const double weight) : Criterion(name, weight) {}
};

// Option to be compared to others in the various criteria
class Candidate
{
public:
  // Vector type
  typedef std::vector<std::unique_ptr<Candidate>> Vector;

  /* Constructor
   *
   * param "name": Name of the candidate
   * param "values": Vector of values for each of the criteria in the OWA comparison
   */
  Candidate(const string &name, const FloatVector &values) : _name(name), _values(values) {}

private:
  // Memeber variables
  const string _name;
  const FloatVector _values;
};

#endif // _OWA_H_ 