//
//  main.cpp
//  CF.STL_Ranges_00
//
//  Created by Alan Sampson on 2/19/23.
//

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
#include <algorithm>
#include <version>

#include "version_info.h"
#include "identify.h"

#define stfy(STR) #STR
#define xstfy(STR) str(STR)

using namespace std::literals::string_literals;

//  MARK: - Local Constants.
namespace konst {

auto delimiter(char const dc = '-', size_t sl = 80) -> std::string const {
  auto const dlm = std::string(sl, dc);
  return dlm;
}

static
auto const dlm = delimiter();

static
auto const dot = delimiter('.');

static
auto const tiddle = delimiter('~');

} /* namespace konst */

void use_for_each(void);

[[maybe_unused]]
auto show = [](auto & container) {
  // Use lazy evaluation to print out the container
  for (auto const & v : container) {
    std::cout << std::setw(2) << v;
  }
  std::cout << std::endl;
};

/*
 *  MARK:  main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "CF.STL_Ranges_00\n"s;
  std::cout << "C++ Version: " << __cplusplus << '\n';
  std::cout << konst::tiddle << '\n' << '\n';
  avi::version_details();

  avi::identify();
  std::cout << konst::tiddle << std::endl;

  // Some data for us to work on
  auto numbers = std::vector<int> { 6, 5, 4, 3, 2, 1 };
  // Use lazy evaluation to print out the numbers
  show(numbers);

  // Lambda function that will provide filtering
  [[maybe_unused]]
  auto is_even = [](auto const n) { return n % 2 == 0; };

#ifdef __cpp_lib_ranges
  using std::views::filter,
        std::views::transform,
        std::views::reverse;

  // Process our dataset
  //  [looks suspiciously like a Hartmann (CMS/Batch) pipeline.]
  auto results = numbers
       | filter(is_even)
       | transform([](auto n) { return ++n; })
       | reverse;

  // Use lazy evaluation to print out the results
  show(results);  // Output: 3 5 7
#else
# warning "Missing C++ library feature  std::views"
  std::cout.put('\n');
  std::cout << konst::tiddle << '\n';
  std::cout << "std::views not available to C++ Ver "s << __cplusplus << '\n';
  std::cout << "Library feature macro "s << stfy(__cpp_lib_ranges) << " not defined."s << '\n';
  std::cout << konst::tiddle << '\n';
#endif  /* __cpp_lib_ranges */

  use_for_each();

  return 0;
}

/*
 *  MARK:  use_for_each()
 *
 *  @see:  https://stackoverflow.com/questions/3185132/how-to-combine-a-function-and-a-predicate-in-for-each
 */
void use_for_each(void) {
  std::cout << "In fnuction " << __func__ << "()\n";

  namespace ranges = std::ranges;

  std::vector<int> vec = { 1, 2, 3, 4, 5, };
  show(vec);

  [[maybe_unused]]
  const auto even = [](int i) { return 0 == i % 2; };

#ifdef __cpp_lib_ranges
  ranges::for_each(vec
                   | std::views::filter(even),
                   [](int & i) { i += 1; });
#else
# warning "Missing C++ library feature std::ranges::for_each"
  std::cout.put('\n');
  std::cout << konst::tiddle << '\n';
  std::cout << "std::ranges::for_each not available to C++ Ver "s << __cplusplus << '\n';
  std::cout << "Library feature macro "s << stfy(__cpp_lib_ranges) << " not defined."s << '\n';
  std::cout << konst::tiddle << '\n';
#endif  /* __cpp_lib_ranges */

  show(vec);

  return;
}
