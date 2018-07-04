/**
* SOLID Design Principle 2 : Open-Closed Principle (OCP)
* Defn. Entities should be open for extension but closed for modification.
*/


#include <string>
#include <vector>
#include <iostream>

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product
{
  std::string name;
  Color color; 
  Size size;
};

struct ProductFilter
{
  /**
  * Look at the functions of this class. Notice that we've to write explicit
  * function for every filtering criteria. So instead of opening up the class
  * for extension, we're opening it up for modification. Violates OCP!
  */
  typedef std::vector<Product*> Items;
  static Items by_color(Items items, Color color)
  {
    Items result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  static Items by_size(Items items, Size Size)
  {
    Items result;
    for (auto& i : items)
      if (i->size == Size)
        result.push_back(i);
    return result;
  }

  static Items by_color_and_size(Items items, Color color, Size size)
  {
    Items result;
    for (auto& i : items)
      if (i->color == color && i->size == size)
        result.push_back(i);
    return result;
  }
};

/**
* Now, to solve the problem above, we've to design a more generalized filter.
* The solution is implemented below using Specification Pattern (not in GOF
* patterns) which is used in relation to data access quite a lot.
*/
template <typename T> struct ISpecification
{
  /**
  * =0 means a pure virtual function. Any derived class must define this function.
  * This class is an abstract class that cannot be instantiated.
  */
  virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct IFilter
{
  /**
  * This class is an abstract class IFilter.
  * The function filter() takes a vector of items of type T and a specification
  *  of type T on the basis of which the items will be filtered out.
  */
  virtual std::vector<T*> filter(std::vector<T*> items, ISpecification<T>& spec) = 0;
};


struct BetterFilter : IFilter<Product>
{
  /**
  * A BetterFilter class derived from IFilter
  */

  /**
  * Overriding filter() function to filter out items of Product type based on some
  * specification of item.
  */
  typedef std::vector<Product*> Items;
  std::vector<Product*> filter(std::vector<Product*> items, ISpecification<Product>& spec) override
  {
    Items result;
    for (auto& p : items)
      if (spec.is_satisfied(p))
        result.push_back(p);
    return result;
  }
};

struct ColorSpecification: ISpecification<Product>
{
  /**
  * A ColorSpecification class derived from ISpecification.
  */
  Color color;

  explicit ColorSpecification(const Color color)
    : color{color}
  {
  }

  /**
  * overriding is_satisfied to check if Product satisfies the given color
  * specification.
  */
  bool is_satisfied(Product* item) override {
    return item->color == color;
  }
};

struct SizeSpecification: ISpecification<Product>
{
  /**
  * Just like color specification, it is for size specification.
  */
  Size size;

  explicit SizeSpecification(const Size size)
    : size{size}
  {
  }


  bool is_satisfied(Product* item) override {
    return item->size == size;
  }
};

template <typename T> struct AndSpecification : ISpecification<T>
{
  /**
  * For two simultaneous specifications (Ex. Color and Size [see main() below])
  */
  ISpecification<T>& first;
  ISpecification<T>& second;


  AndSpecification(ISpecification<T>& first, ISpecification<T>& second)
    : first{first},
      second{second}
  {
  }


  bool is_satisfied(T* item) override {
    return first.is_satisfied(item) && second.is_satisfied(item);
  }
};

int main()
{
  Product apple{ "Apple", Color::Green, Size::Small };
  Product tree{ "Tree", Color::Green, Size::Large };
  Product house{ "House", Color::Blue, Size::Large };

  std::vector<Product*> all{ &apple, &tree, &house };

  BetterFilter bf;
  ColorSpecification green(Color::Green);

  auto green_things = bf.filter(all, green);
  for (auto& x : green_things)
    std::cout << x->name << " is green" << std::endl;

  SizeSpecification big(Size::Large);
  AndSpecification<Product> green_and_big{ big,green };

  auto green_big_things = bf.filter(all, green_and_big);
  for (auto& x : green_big_things)
    std::cout << x->name << " is green and big" << std::endl;

  getchar();
  return 0;
}