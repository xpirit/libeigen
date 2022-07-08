#include <jlcxx/jlcxx.hpp>
#include <jlcxx/stl.hpp>

class Eigen
{
public:
  Eigen(int i = 0) : m_value(i) {}
  int add(int i) const { return m_value + i; } // Member function
  Eigen* thisptr() { return this; }
  Eigen& thisref() { return *this; }
  Eigen thiscopy() { return *this; }
  const int* valueptr() { return &m_value; }
private:
  int m_value;
};

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.add_type<Eigen>("Eigen")
    .constructor<int>()
    .method("add", &Eigen::add)
    .method("thisptr", &Eigen::thisptr)
    .method("thisref", &Eigen::thisref)
    .method("thiscopy", &Eigen::thiscopy)
    .method("valueptr", &Eigen::valueptr);
  mod.method("sumEigens", [] (const std::vector<Eigen>& vec)
  {
    int result = 0;
    for (auto Eigen : vec)
    {
      result += *Eigen.valueptr();
    }
    return result;
  });
}
