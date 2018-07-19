#include <string>
#include <vector>
#include <sstream>

#include "initialization.h"
#include "targeting.h"

int main()
{
  std::vector <std::string> ad_DB (65536);
  std::vector <struct CID> camps;

  const int size = addCampaigns("example_data.txt", &ad_DB, &camps);

  std::vector <int> starveList (size);

  bestCamp("input.txt", size, &ad_DB, &camps, &starveList);
}
