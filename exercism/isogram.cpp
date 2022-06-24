#include "isogram.h"

#include <map>
#include <utility>

namespace isogram {
bool is_isogram(const std::string &input) {
  std::map<char, int> char_occurences;

  for (const auto &item : input) {
    // If char is not yet inserted to map
    if (char_occurences.count(item) == 0) {
      char_occurences.emplace(std::pair<char, int>(item, 0));
    }
    //  char already exist
    else {
      return false;
    }
  }
  return true;
}
} // namespace isogram
