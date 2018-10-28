/*
 * Criterion.h
 *
 *  Created on: Oct 28, 2018
 *      Author: miquel
 */

#ifndef CRITERION_H_
#define CRITERION_H_

#include <string>
#include <vector>
#include <memory>

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
  Criterion (const string &name, const double weight) :
      _name (name), _weight (weight)
  {
  }

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
  NCriterion (const string &name, const double weight) :
      Criterion (name, weight)
  {
  }

};

#endif /* CRITERION_H_ */
