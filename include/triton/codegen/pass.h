#ifndef _TRITON_CODEGEN_PASS_H_
#define _TRITON_CODEGEN_PASS_H_


#include <memory>

namespace llvm{
  class Module;
  class LLVMContext;
}

namespace triton{

namespace codegen {
  class target;
}

namespace ir{
  class module;
}
namespace driver{
  class device;
  class module;
  class kernel;
}

}

namespace triton{
namespace codegen{

namespace analysis{
class layouts;
class align;
}

// TODO:
// There should be a proper pass manager there!
std::unique_ptr<llvm::Module> add_passes_to_emit_bin(ir::module &ir, llvm::LLVMContext& ctx,
                                                     codegen::target* target,
                                                     int sm, int num_warps,
                                                     int num_stages, int &shared_static,
                                                     std::unique_ptr<analysis::layouts> *last_layouts = nullptr,
                                                     std::unique_ptr<analysis::align> *last_align = nullptr);


}
}

#endif
