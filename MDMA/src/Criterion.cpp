/*
 * Criterion.cpp
 *
 *  Created on: Nov 18, 2018
 *      Author: miquel
 */

#include "Criterion.h"
#include <iostream>

void Criterion::GetScores(const unsigned int index, const Alternative::Vector &alternatives, VectorDouble &scores) const
{
  double maxRating, minRating, rating;
  maxRating = alternatives[0]->GetRating(index);
  minRating = maxRating;
  for (auto alternative : alternatives)
  {
    rating = alternative->GetRating(index);
    if (rating > maxRating)
      maxRating = rating;
    if (rating < minRating)
      minRating = rating;
  }
  if (minRating == maxRating)
  {
    for (auto alternative : alternatives)
    {
      scores.push_back(0.0);
    }
    return;
  }
  for (auto alternative : alternatives)
  {
    rating = alternative->GetRating(index);
    rating = (rating - minRating) / (maxRating - minRating) * (SCALED_MAX_SCORE - SCALED_MIN_SCORE) + SCALED_MIN_SCORE;
    rating *= _weight;
    //std::cout << "Alternative: " << alternative->GetName() << "; score: " << rating << std::endl;
    scores.push_back(rating);
  }
}

void InverseCriterion::GetScores(const unsigned int index, const Alternative::Vector &alternatives,
    VectorDouble &scores) const
{
  double maxRating, minRating, rating;
  maxRating = alternatives[0]->GetRating(index);
  minRating = maxRating;
  for (auto alternative : alternatives)
  {
    rating = alternative->GetRating(index);
    if (rating > maxRating)
      maxRating = rating;
    if (rating < minRating)
      minRating = rating;
  }
  if (minRating == maxRating)
  {
    for (auto alternative : alternatives)
    {
      scores.push_back(0.0);
    }
    return;
  }
  for (auto alternative : alternatives)
  {
    rating = alternative->GetRating(index);
    rating = (rating - maxRating) / (minRating - maxRating) * (SCALED_MAX_SCORE - SCALED_MIN_SCORE) + SCALED_MIN_SCORE;
    rating *= _weight;
    scores.push_back(rating);
  }
}

