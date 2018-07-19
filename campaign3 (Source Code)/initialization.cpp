#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "initialization.h"

int addCampaigns(std::string s, std::vector <std::string> *ad, std::vector <struct CID> *camp)
{
  CID info;
  std::string campDat;
  int adID, uID = 1;

  std::ifstream reader;
  reader.open(s);

  while (std::getline(reader, campDat))
  {
    std::istringstream iss(campDat);
    std::string test;

    iss >> test;

    int dup  = dupCamp(test, camp);
    switch (dup)
    {
      case -1:
        info.id = uID;
        info.campaign = test;
        camp -> push_back(info);

        iss >> adID;
        while(iss)
        {
          if(adID >= 0 && adID < 65536)
            addDB(uID, adID, ad);
          iss >> adID;
        }

        uID++;
        break;

      default:
        iss >> adID;
        while (iss)
        {
          if(adID >= 0)
            addDB(dup, adID, ad);
          iss >> adID;
        }
    }
  }

  return --uID;
}

void addDB(int camp, int index, std::vector <std::string> *db)
{
  if(!dupID(camp, index, db))
  {
    db -> at(index) += std::to_string(camp);
    db -> at(index) += " ";
  }
}

int dupCamp(std::string s, std::vector <struct CID> *c)
{
  for(int i = 0; i < c -> size(); i++)
  {
    if (s == c -> at(i).campaign)
    {
      return ++i;
    }
  }

  return -1;
}

bool dupID(int camp, int index, std::vector <std::string> *db)
{
  int x;
  std::istringstream iss(db -> at(index));

  if(iss.rdbuf() -> in_avail() != 0)
  {
      iss >> x;
      while(iss)
      {
        if(camp == x)
        {
          return true;
        }

        iss >> x;
      }
  }

  return false;
}
