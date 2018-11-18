/*
 * OWA.cpp
 *
 *  Created on: Nov 18, 2018
 *      Author: miquel
 */

#include "OWA.h"

OWA::~OWA()
{
  for (auto criterion : _criteria)
  {
    delete criterion;
  }

  for (auto alternative : _alternatives)
  {
    delete alternative;
  }
}

void OWA::Append(const Criterion * criterion)
{

  _criteria.push_back(new Criterion(*criterion));
  _I++;
}

void OWA::Append(const Alternative * alternative)
{
  _alternatives.push_back(new Alternative(*alternative));
  _J++;
}

void OWA::PrintData()
{

}

bool OWA::CheckData()
{
  if (_criteria.size() != _I)
    return false;
  if (_alternatives.size() != _J)
    return false;
  for (auto alternative : _alternatives)
  {
    if (alternative->GetNumberOfRatings() != _I)
    {
      std::cout << "OWA::CheckData - ERROR: incompatible data for alternative (" << alternative->GetName() << ")"
          << std::endl;
      return false;
    }
  }
  return true;
}
