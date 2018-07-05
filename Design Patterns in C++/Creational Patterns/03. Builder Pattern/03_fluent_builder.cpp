#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 

struct HTMLElement {
    string name; // p, ul etc..
    string text; // text inside tags
    vector <HTMLElement> childElements;
    const size_t indent_size = 2;

    HTMLElement() {}

    // initializing name and text
    HTMLElement(const string &name, const string &text)
        : name{name}, text{text} {}

    // str in recursive function that builds elements 
    // takes indent (indentation level) as parameter
    string str(int indent=0) const {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size()) {
           oss << string(indent_size * (indent + 1), ' ') << text << endl;
        }
        for (const auto& e: childElements) {
            oss << e.str(indent + 1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }
};

struct HTMLBuilder {
    HTMLElement root;
    HTMLBuilder(string root_name) {
        root.name = root_name;
    }

    HTMLBuilder& add_child(string childName, string childText) {
        HTMLElement e{childName, childText};
        root.childElements.push_back(e);
        return *this;
    }

    string str() const {
        return root.str();
    }
};

int main() {
    // using builder to make <ul><li>hello</li><li>world</li></ul>
    HTMLBuilder builder ("ul");

    // a fluent builder allows chaining of calls
    builder.add_child("li", "hello")
        .add_child("li", "world");
    // also see the changes in add_child
    cout << builder.str() << endl;
    return 0;
}