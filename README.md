## Ranges

Ranges make a huge difference in how we work with collections
of data since they give users the power to lazily filter and
transform data through a pipeline. Ranges also make iterator
pairs largely unnecessary, reducing the need to write error-prone
code. The familiar `“|”` operator is used to pass data from one
part of the pipeline to the next, making it easy to compose
different pipelines from a common set of primitive functions.

This project is an example of using ranges to lazily evaluate a
data pipeline over a collection in g++ 10:

### Reference

- <https://www.incredibuild.com/blog/what-you-need-to-do-to-move-on-to-c-20-the-complete-list?fbclid=IwAR10IcJy7RsPJQ39AKqmvGaCROw2szJjqxUzx-FS9gEdGQeBcqtahef-C90>
- <https://en.cppreference.com/w/cpp/ranges>
