#include <torch/extension.h>

void single_query_cached_kv_attention(
  torch::Tensor& out,
  torch::Tensor& query,
  torch::Tensor& key_cache,
  torch::Tensor& value_cache,
  torch::Tensor& kv_head_mapping,
  float scale,
  torch::Tensor& block_tables,
  torch::Tensor& context_lens,
  int block_size,
  int max_context_len);

PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
  m.def(
    "single_query_cached_kv_attention",
    &single_query_cached_kv_attention,
    "Compute the attention between an input query and the cached key/value tensors");
}
