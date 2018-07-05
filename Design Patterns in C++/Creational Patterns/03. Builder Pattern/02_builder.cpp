#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 

struct HTMLElement {
    // respresents an HTML Element

    string name; // p, ul etc..
    string text; // text inside tags
    vector <HTMLElement> childElements;
    const size_t indent_size = 2;

    /* 
     * constructs HTMLElement without initializing data members
     */    
    HTMLElement() {}

    /*
     * initializes name and text
     */
    HTMLElement(const string &name, const string &text)
        : name{name}, text{text} {}

    /* 
     * Function to recursively build an element using indentation
     * @param number: An integer
     * @return: string
     */
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
    // HTMLBuilder builds HTMLElements

    HTMLElement root;

    /*
     * Constructs HTMLBuilder instance by initializing root elment's name
     */
    HTMLBuilder(string root_name) {
        root.name = root_name;
    }

    /*
     * Adding a child element using child's name and text
     */
    void add_child(string childName, string childText) {
        HTMLElement e{childName, childText};
        root.childElements.push_back(e);
    }

    /*
     * function that calls HTMLElement to return the structure in string format
     */
    string str() const {
        return root.str();
    }
};

int main() {
    // using builder to make <ul><li>hello</li><li>world</li></ul>
    HTMLBuilder builder ("ul");
    builder.add_child("li", "hello");
    builder.add_child("li", "world");
    cout << builder.str() << endl;
    return 0;
}