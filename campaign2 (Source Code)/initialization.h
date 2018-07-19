#ifndef __INITIALIZATION_H__INCLUDED
#define __INITIALIZATION_H__INCLUDED

struct CID
{
  std::string campaign;
  int id;
};

int addCampaigns(std::string s, std::vector <std::string> *ad, std::vector <CID> *camp);
void addDB(int camp, int index, std::vector <std::string> *db);

int dupCamp(std::string s, std::vector <CID> *c);
bool dupID(int camp, int index, std::vector <std::string> *db);

#endif
