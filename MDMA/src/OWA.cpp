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
  if (!CheckData())
    return;

  using std::cout;
  using std::endl;
  using std::setfill;
  using std::setw;
  using std::left;

  const unsigned int colN = 3 + _J;
  unsigned int colW = 5;
  for (auto alternative : _alternatives)
  {
    const String &name = alternative->GetName();
    if (name.size() > colW)
      colW = name.size();
  }
  for (auto criterion : _criteria)
  {
    const String &name = criterion->GetName();
    if (name.size() > colW)
      colW = name.size();
  }
  colW *= 2;

  const char hL = '-';
  const char vL = '|';

  cout << left << setfill(hL) << setw(colN * colW + 10) << " " << setfill(' ') << endl;
  cout << left << vL << setw(colW * 3 + 2) << " Criteria ";
  cout << left << vL << vL << setw((colW + 3) * (colN - 3) - 1) << " Alternatives & ratings " << vL << endl;
  cout << left << setfill(hL) << setw(colN * colW + 10) << " " << setfill(' ') << endl;
  cout << left << vL << setw(colW) << " Name " << vL << setw(colW) << " Units " << vL << setw(colW) << " Weight " << vL;
  cout << vL;
  for (auto alternative : _alternatives)
  {
    cout << left << " " << setw(colW) << alternative->GetName() << " " << vL;
  }
  cout << endl << left << setfill(hL) << setw(colN * colW + 10) << " " << setfill(' ') << endl;
  for (unsigned int i = 0; i < _I; ++i)
  {
    auto criterion = _criteria[i];
    cout << vL;
    cout << left << " " << setw(colW - 2) << criterion->GetName() << " " << vL;
    cout << left << " " << setw(colW - 2) << criterion->GetUnits() << " " << vL;
    cout << left << " " << setw(colW - 2) << criterion->GetWeight() << " " << vL;
    cout << vL;
    for (auto alternative : _alternatives)
    {
      cout << left << " " << setw(colW) << alternative->GetRating(i) << " " << vL;
    }
    cout << endl;
  }
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
