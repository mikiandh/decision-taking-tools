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
#include <memory>

// Option to be compared to others in the various criteria
class Alternative
{
public:
  // Type definitions
  typedef std::vector<int> IntVector;
  typedef std::vector<double> FloatVector;
  typedef std::string string;
  typedef std::vector<string> StringVector;
  typedef std::vector<std::shared_ptr<Alternative>> Vector;

  /* Constructor
   *
   * param "name": Name of the alternative
   * param "values": Vector of values for each of the criteria in the OWA comparison
   */
  Alternative(const string &name, const FloatVector &values) :
      _name(name), _values(values)
  {
  }

private:
  // Memeber variables
  const string _name;
  const FloatVector _values;
};

#endif /* ALTERNATIVE_H_ */
