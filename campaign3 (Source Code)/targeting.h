#ifndef __TARGETING_H__INCLUDED
#define __TARGETING_H__INCLUDED

void bestCamp(std::string s, const int size, std::vector <std::string> *db, std::vector <struct CID> *master, std::vector <int> *starve);
void readDB(std::vector <std::string> *db, std::vector <int> *c, int i, bool *empty);
int chooseCamp(std::vector <int> *total, std::vector <int> *starve, bool empty);

int starveCheck(std::vector <int> *e, std::vector <int> *s);
int randSelect(std::vector <int> *r);

#endif
