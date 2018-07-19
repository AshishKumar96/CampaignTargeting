#include <sstream>
#include <vector>
#include <time.h>
#include <iostream>

#include "initialization.h"
#include "targeting.h"

void bestCamp(std::string s, const int size, std::vector <std::string> *db, std::vector <struct CID> *master, std::vector <int> *starve)
{
  int tID;
  {
    bool isEmpty = true;
    std::vector <int> counter (size);
    std::istringstream iss(s);

    iss >> tID;
    while(iss)
    {
      if(tID >= 0 && tID < 65536)
      readDB(db, &counter, tID, &isEmpty);
      iss >> tID;
    }

    int camp = chooseCamp(&counter, starve, isEmpty);

    switch (camp)
    {
      case -1:
      std::cout << "no campaign" << std::endl;
      break;
      default:
      std::cout << master -> at(camp).campaign << std::endl;
      starve -> at(camp)++;
    }
  }
}

void readDB(std::vector <std::string> *db, std::vector <int> *c, int i, bool *empty)
{
  int cID;

  std::string camps = db -> at(i);
  std::istringstream iss(camps);

  if(iss.rdbuf() -> in_avail() != 0)
  {
    *empty = false;
    iss >> cID;
    while(iss)
    {
      c -> at(cID-1)++;
      iss >> cID;
    }
  }
}

int chooseCamp(std::vector <int> *total, std::vector <int> *starve, bool empty)
{
  if (empty != false)
  return -1;

  int loc = 0, large = total -> at(0);
  std::vector <int> equal;

  for (int i = 1; i < total -> size(); i++)
  {
    int x = total -> at(i);
    if(large <= x)
    {
      equal.push_back(loc);
      loc = i;

      if(large < x)
      {
        large = total -> at(i);
        equal.clear();
      }
    }
  }

  equal.push_back(loc);

  if (equal.size() > 1)
    return equal.at(starveCheck(&equal, starve));

  else
    return loc;
}

int starveCheck(std::vector <int> *e, std::vector <int> *s)
{
  int loc = 0;
  std::vector <int> eqStarve;

  for (int i = 1; i < e -> size(); i++)
  {
    if (s -> at(e -> at(loc)) >= s -> at(e -> at(i)))
    {
      eqStarve.push_back(loc);

      if (s -> at(e -> at(loc)) > s -> at(e -> at(i)))
      eqStarve.clear();

      loc = i;
    }
  }

  eqStarve.push_back(loc);

  if(eqStarve.size() > 1)
    return eqStarve.at(randSelect(&eqStarve));
  
  else
    return loc;
}

int randSelect(std::vector <int> *r)
{
  srand(time(NULL));
  return rand()%(r -> size());
}
