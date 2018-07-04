/**
* SOLID Design Principle 4 : Interface Segregation Principle (ISP)
* Defn. No client (user of your code) should be forced to depend on methods it
* does not use.
*/ 

#include <vector>

/**
* Suppose we want the client to have an interface for printing a list of 
* Document.
*/

struct Document;

/**
* We provide an interface IMachine (commented out below )with pure virtual
* functions print, scan and fax. We expect user to extend this interface
* and provide library with concrete implementation of these functions.
*/
//struct IMachine
//{
//  virtual void print(std::vector<Document*> docs) = 0;
//  virtual void scan(std::vector<Document*> docs) = 0;
//  virtual void fax(std::vector<Document*> docs) = 0;
//};
//

/**
* Suppose MFP is a concrete implementation of IMachine by user. Now if
* user only wants print functionality, s/he must define other functions
* too. Also, every time user defines an interface with concrete implementations,
* there is recompilation required. These break ISP.
*/
//struct MFP : IMachine
//{
//  void print(std::vector<Document*> docs) override;
//  void scan(std::vector<Document*> docs) override;
//  void fax(std::vector<Document*> docs) override;
//};

struct IPrinter
{
  virtual void print(std::vector<Document*> docs) = 0;
};

struct IScanner
{
  virtual void scan(std::vector<Document*> docs) = 0;
};

struct Printer : IPrinter
{
  void print(std::vector<Document*> docs) override;
};

struct Scanner : IScanner
{
  void scan(std::vector<Document*> docs) override;
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine
{
  IPrinter& printer;
  IScanner& scanner;


  Machine(IPrinter& printer, IScanner& scanner)
    : printer{printer},
      scanner{scanner}
  {
  }

  void print(std::vector<Document*> docs) override {
    printer.print(docs);
  }
  void scan(std::vector<Document*> docs) override {
    scanner.scan(docs);
  }
};