/*
 * Criterion.h
 *
 *  Created on: Oct 28, 2018
 *      Author: miquel
 */

#ifndef CRITERION_H_
#define CRITERION_H_

#include <string>
#include "Alternative.h"

/*
 * Characteristic common among all candidates to be used to compare them
 */
class Criterion
{
public:
  // Type definitions
  typedef std::string String;
  typedef std::vector<double> VectorDouble;
  typedef std::vector<const Criterion *> Vector;

  // Public constants
  static const int SCALED_MAX_SCORE = 10;
  static const int SCALED_MIN_SCORE = 0;

  /* Constructor
   *
   * @ name: Name of the criterion
   * @ weight: Weight of the criterion
   */
  Criterion(const String &name, const double weight, const String &units = "N/A") :
      _name(name), _weight(weight), _units(units)
  {
  }

  /* Returns the name of the criterion
   *
   * return: name of the criterion
   */
  const String& GetName() const
  {
    return _name;
  }

  /* Returns the weight of the criterion
   *
   * return: weight of the criterion
   */
  const double GetWeight() const
  {
    return _weight;
  }

  /* Returns the units the criterion is measured in
   *
   * return: units of the criterion
   */
  const String& GetUnits() const
  {
    return _units;
  }

  /* Computes the scaled and weighted score of each alternative in regards to the current criterion
   *
   * @ index: index of the current criterion
   * @ alternatives: vector of alternatives
   * @ scores: vector of scores, must have as many components as alternatives
   */
  virtual void GetScores(const unsigned int index, const Alternative::Vector &alternatives, VectorDouble &scores) const;

  /*
   * Destructor
   */
  virtual ~Criterion()
  {
  }

protected:
  const String _name;
  const double _weight;
  const String _units;
};

// Inverse criterion (higher value results in a lower score)
class InverseCriterion: public Criterion
{
public:
  /* Constructor
   *
   * param "name": name of the criterion
   * param "weight": weight of the criterion
   */
  InverseCriterion(const String &name, const double weight, const String &units = "N/A") :
      Criterion(name, weight, units)
  {
  }

  /* Computes the scaled and weighted score of each alternative in regards to the current inverse criterion
   *
   * @ index: index of the current criterion
   * @ alternatives: vector of alternatives
   * @ scores: vector of scores, must have as many components as alternatives
   */
  void GetScores(const unsigned int index, const Alternative::Vector &alternatives, VectorDouble &scores) const
      override;
};

#endif /* CRITERION_H_ */
