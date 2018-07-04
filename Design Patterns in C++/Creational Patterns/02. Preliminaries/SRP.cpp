/**
* SOLID Design Principle 1 : Single Responsibility Principle (SRP)
* Defn. A class should only have a single responsibility.
*/

#include <string>
#include <vector>
#include <fstream>

struct Journal
{
  std::string title;
  std::vector<std::string> entries;

  explicit Journal(const std::string& title)
    : title{title}
  {
  }

  /**
  * add() functions adds a journal entry to the Journal instance
  */
  void add(const std::string& entry)
  {
    entries.push_back(entry);
  }

  /**
  * save() function could be added here which would save the jounal
  * to a file, but, that might violate SRP because saving should be
  * responsibility of some other class (like Persistence Manager below)
  */
};

struct PersistenceManager
{
  /**
  * Now suppose if someone wants to change the medium to save 
  * jounal (other than a file), the developer might have to go
  * to Jounal class to perform changes, whereas, in our case
  * only PersistenceManager must be edited
  */
  static void save(const Journal& j, const std::string& filename)
  {
    std::ofstream ofs(filename);
    for (auto& s : j.entries)
      ofs << s << std::endl;
  }
};
