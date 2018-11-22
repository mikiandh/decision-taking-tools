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

void OWA::Append(const InverseCriterion * criterion)
{
  _criteria.push_back(new InverseCriterion(*criterion));
  _I++;
}

void OWA::Append(const Alternative * alternative)
{
  _alternatives.push_back(new Alternative(*alternative));
  _J++;
}

void OWA::PrintData() const
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

  cout << left << setfill(hL) << setw(colN * colW + 3 * _J + 4) << " " << setfill(' ') << endl;
  cout << left << vL << setw(colW * 3 + 2) << " Criteria ";
  cout << left << vL << vL << setw((colW + 3) * (colN - 3) - 1) << " Alternatives & ratings " << vL << endl;
  cout << left << setfill(hL) << setw(colN * colW + 3 * _J + 4) << " " << setfill(' ') << endl;
  cout << left << vL << setw(colW) << " Name " << vL << setw(colW) << " Units " << vL << setw(colW) << " Weight " << vL;
  cout << vL;
  for (auto alternative : _alternatives)
  {
    cout << left << " " << setw(colW) << alternative->GetName() << " " << vL;
  }
  cout << endl << left << setfill(hL) << setw(colN * colW + 3 * _J + 4) << " " << setfill(' ') << endl;
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
  cout << left << setfill(hL) << setw(colN * colW + 3 * _J + 4) << " " << setfill(' ') << endl;
  cout << endl;
}

bool OWA::CheckData() const
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

void OWA::Compute()
{
  _owaVector.resize(_J, 0.0);
  VectorDouble tmp;

  double quotient = 0;
  for (auto criterion : _criteria)
  {
    quotient += criterion->GetWeight();
  }
  quotient = 1 / quotient / Criterion::SCALED_MAX_SCORE;

  tmp.reserve(_J);
  for (unsigned int i = 0; i < _I; ++i)
  {
    _criteria[i]->GetScores(i, _alternatives, tmp);
    for (unsigned int j = 0; j < _J; ++j)
    {
      _owaVector[j] += tmp[j];
    }
    tmp.clear();
  }
  for (unsigned int j = 0; j < _J; ++j)
  {
    _owaVector[j] *= quotient;
  }
  PrintVector();
}

void OWA::PrintMatrix() const
{

}

void OWA::PrintVector() const
{
  using std::cout;
  using std::endl;
  using std::setfill;
  using std::setw;
  using std::left;

  const unsigned int colN = _J;
  unsigned int colW = 5;
  for (auto alternative : _alternatives)
  {
    const String &name = alternative->GetName();
    if (name.size() > colW)
      colW = name.size();
  }
  colW *= 2;

  const char hL = '-';
  const char vL = '|';

  cout << left << setfill(hL) << setw(colN * colW + 3 * _J) << " " << setfill(' ') << endl;
  cout << vL;
  for (auto alternative : _alternatives)
  {
    cout << left << " " << setw(colW) << alternative->GetName() << " " << vL;
  }
  cout << endl << left << setfill(hL) << setw(colN * colW + 3 * _J) << " " << setfill(' ') << endl;
  cout << vL;
  for (auto owa : _owaVector)
  {
    cout << left << " " << setw(colW) << owa << " " << vL;
  }
  cout << endl << left << setfill(hL) << setw(colN * colW + 3 * _J) << " " << setfill(' ') << endl;
  cout << endl;
}
