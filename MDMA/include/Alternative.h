/*
 * Alternative.h
 *
 *  Created on: Oct 28, 2018
 *      Author: miquel
 */

#ifndef ALTERNATIVE_H_
#define ALTERNATIVE_H_

#include <string>
#include <vector>

// Option to be compared to others among various criteria
class Alternative
{
public:
  // Type definitions
  typedef std::string String;
  typedef std::vector<double> VectorDouble;
  typedef std::vector<const Alternative *> Vector;

  /* Constructor
   *
   * @ name: name of the alternative
   * @ ratings: vector of ratings for each of the criteria
   */
  Alternative(const String &name, const VectorDouble &ratings) :
      _name(name), _ratings(ratings)
  {
  }

  /* Returns the name of the alternative
   *
   * return: name of the alternative
   */
  const String & GetName() const
  {
    return _name;
  }

  /* Returns the number of ratings the alternative has
   *
   * return: number of ratings
   */
  unsigned int GetNumberOfRatings() const
  {
    return _ratings.size();
  }

  /* Returns the rating in a selected criterion of the alternative
   *
   * return: rating
   */
  const double & GetRating(unsigned int index) const
  {
    return _ratings[index];
  }

  /* Returns all the ratings of the alternative
   *
   * return: ratings
   */
  const VectorDouble & GetRatings() const
  {
    return _ratings;
  }

private:
  const String _name;
  const VectorDouble _ratings;
};

#endif /* ALTERNATIVE_H_ */
