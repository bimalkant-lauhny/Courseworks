#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  // <p>hello</p>
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  printf("<p>%s</p>", text);

  cout << endl;

  // <ul><li>hello</li><li>world</li></ul>
  string words[] = { "hello", "world" };
  std::ostringstream oss;
  oss << "<ul>";
  for (auto w : words)
    oss << "<li>" << w << "</li>";
  oss << "</ul>";
  printf(oss.str().c_str());

  getchar();
  return 0;
}