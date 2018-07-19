#include <string>
#include <vector>
#include <iostream>

#include "initialization.h"
#include "targeting.h"

int main()
{
  std::vector <std::string> ad_DB (65536);
  std::vector <struct CID> camps;

  const int size = addCampaigns("example_data.txt", &ad_DB, &camps);

  std::vector <int> starveList (size);

  std::string input;

  while(std::getline(std::cin, input))
  {
    if (input == "-1" || input == "exit")
      break;

    bestCamp(input, size, &ad_DB, &camps, &starveList);
  }

  return 0;
}
