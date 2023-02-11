/*
 * Ranges
 *
 * Ranges make a huge difference in how we work with collections
 * of data since they give users the power to lazily filter and
 * transform data through a pipeline. Ranges also make iterator
 * pairs largely unnecessary, reducing the need to write
 * error-prone code. The familiar “|” operator is used to pass
 * data from one part of the pipeline to the next, making it easy
 * to compose different pipelines from a common set of primitive
 * functions.
 *
 * The following is an example of using ranges to lazily evaluate
 * a data pipeline over a collection in g++ 10:
 *
 * @see: https://www.incredibuild.com/blog/what-you-need-to-do-to-move-on-to-c-20-the-complete-list?fbclid=IwAR10IcJy7RsPJQ39AKqmvGaCROw2szJjqxUzx-FS9gEdGQeBcqtahef-C90
 * @see: https://en.cppreference.com/w/cpp/ranges
 */

#include <iostream>
#include <iomanip>
#include <ranges>
#include <vector>

auto show = [](auto & container) {
  // Use lazy evaluation to print out the container
  for (auto const & v : container) {
    std::cout << std::setw(2) << v;
  }
  std::cout << std::endl;  
};

int main(int argc, char const * argv[]) {
  std::cout << "C++ Version: " << __cplusplus << '\n';
  using std::views::filter,
        std::views::transform,
        std::views::reverse;

  // Some data for us to work on
  auto numbers = std::vector<int> { 6, 5, 4, 3, 2, 1 };
  // Use lazy evaluation to print out the numbers
  show(numbers);

  // Lambda function that will provide filtering
  auto is_even = [](auto const n) { return n % 2 == 0; };

  // Process our dataset
  auto results = numbers
    | filter(is_even)
    | transform([](auto n) { return ++n; })
    | reverse;

  // Use lazy evaluation to print out the results
  show(results);  // Output: 3 5 7

  return 0;
}
