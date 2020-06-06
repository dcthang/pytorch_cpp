#ifndef NETWORKS_HPP
#define NETWORKS_HPP

// For External Library
#include <torch/torch.h>
#include <boost/program_options.hpp>

// Define Namespace
using namespace torch;
namespace po = boost::program_options;

// Function Prototype
void weights_init(nn::Module &m);
void DownSampling(nn::Sequential &sq, const size_t in_nc, const size_t out_nc, const bool BN, const bool ReLU, const bool bias=false);
void UpSampling(nn::Sequential &sq, const size_t in_nc, const size_t out_nc, const bool BN, const bool ReLU, const bool bias=false);


// -------------------------------------------------
// struct{VariationalAutoEncoderImpl}(nn::Module)
// -------------------------------------------------
struct VariationalAutoEncoderImpl : nn::Module{
private:
    torch::Tensor mean_keep, var_keep, z_keep;
    nn::Sequential encoder, encoder_mean, encoder_var;
    nn::Sequential decoder;
    torch::Tensor sampling(torch::Tensor &mean, torch::Tensor &var);
public:
    VariationalAutoEncoderImpl(){}
    VariationalAutoEncoderImpl(po::variables_map &vm);
    torch::Tensor forward(torch::Tensor x);
    torch::Tensor kld_just_before();
};

TORCH_MODULE(VariationalAutoEncoder);


#endif