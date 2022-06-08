#ifndef TDL_INCLUDE_CODEGEN_BUFFER_INFO_PASS_H
#define TDL_INCLUDE_CODEGEN_BUFFER_INFO_PASS_H

#include <set>
#include <map>

namespace triton {

namespace ir {
  class module;
  class value;
  class phi_node;
  class instruction;
  class builder;
}

namespace codegen{

namespace analysis{
class layouts;
}

namespace transform{

class cts {
private:
  bool is_shmem_op(ir::instruction* i, int op);
  bool is_shmem_res(ir::value* i);
void add_copy(ir::instruction *parent, ir::value *x, ir::builder &builder, bool to_shared, std::map<ir::value*,ir::value*>& copies);

public:
  cts(analysis::layouts* layouts, bool use_async = false): layouts_(layouts), use_async_(use_async) {}
  void run(ir::module &mod);

private:
  bool use_async_;
  analysis::layouts* layouts_;
};

}
}
}

#endif