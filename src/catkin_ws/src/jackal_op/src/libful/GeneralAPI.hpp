// define class with useful stuff

// standard includes
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <functional>

// alglib include
//#include "linalg.cpp"

// armadillo include
#include <armadillo>

// defines and inlclude for optim
#define OPTIM_ENABLE_ARMA_WRAPPERS
#include <optim.hpp>

// ceres
#define CERES_SHOW_RESIDUALS
#include <ceres/ceres.h>

// stuff
#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;

namespace genAPI {

    // model parameters
    const _Float64 alpha = 100.0;
    const int stateDim = 12;
    const int inputDim = 3;
    const std::vector<int> pos_p = {0, 4, 8};
    const std::vector<int> pos_v = {1, 5, 9};
    const std::vector<int> pos_b = {2, 6, 10};
    const std::vector<int> pos_a = {3, 7, 11};
    const std::vector<_Float64> theta = {0.4221, 0.2888, -0.0281};
    //const std::vector<_Float64> theta = {1, 1.2662, -0.5457};

    // env params
    const std::vector<_Float64> Anchors = {
        0, -4, 3.5,
        0, 4, 3.5,
        4, 4, 3.5,
        4, -4, 3.5};

    struct Tag {
        int Nanchors;
        _Float64 J;
        std::vector<_Float64> A;
        std::vector<_Float64> Dopt;
        std::vector<_Float64> p;
        std::vector<_Float64> GJ;
    };

    struct TagSet {

        int Ntags;
        int Npairs;
        int Nanchors;
        std::vector<int> CurrPair;
        std::vector<genAPI::Tag> Tags;
        std::vector<_Float64> TagDists;

    };

    /** **** METHODS **** */
    
    // init Tag
    Tag TagInit(int Nanchors);

    // cost function single miniblock
    _Float64 J(double* p, double* grad_out, double* A, double D, int* Pair);

    // Total cost function - position only
    _Float64 Jtot_arma(const arma::vec& p_arma, arma::vec* grad_out, void* tag);

    // Total cost function - bearing
    _Float64 Jtot_arma_bear(const arma::vec& p_arma, arma::vec* grad_out, void* tag);

    // Optim lib minimization
    int OptimMin(std::vector<_Float64> p0, std::vector<_Float64> D, TagSet* tag);

    // Ceres lib minimization
    int CeresMin(std::vector<_Float64> p0, std::vector<_Float64> D, TagSet* tag);

    // model observer
    std::vector<_Float64> modelObserver(std::vector<_Float64> x, std::vector<_Float64> u);

    // Euler integration - hybrid system
    std::vector<_Float64> odeEuler(std::vector<_Float64> x, std::vector<_Float64> u, _Float64 dt);

}

namespace ceresAPI {


    struct Result {
        Result() {}

        std::vector<_Float64> p;
        ceres::Solver::Summary summary;
    };

    class FunctionSmall : public CostFunction {
    public:

        // attributes
        int _blocksize;
        int _nblocks;
        int _nresiduals;
        int _i;
        int _j;
        int _k;

        genAPI::TagSet* _tag;

        double _D;

        FunctionSmall(genAPI::TagSet* tag, int i, int j, int k);
        bool Setup(genAPI::TagSet* tag, int i, int j, int k);
        bool Evaluate(double const* const* parameters, double* residuals, double** jacobians) const;

        
    private: 
    };

    Result solveSmall(arma::vec& p_arma, void* tag);
}