import triton
import triton.language as tl

triton.ops._matmul.kernel.compile(signature='*fp32, *fp32, *fp32, i32, i32, i32, i32, i32, i32, i32, i32, i32',
                                  constants={"BLOCK_M": 128, "BLOCK_N": 128, "BLOCK_K": 32,
                                             "GROUP_M": 8  , "SPLIT_K": 1  , "EVEN_K": True, 
                                             "ACC_TYPE": tl.float32})