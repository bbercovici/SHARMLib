
// MIT License

// Copyright (c) 2012 Yu Takahashi

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


/**
@file   PolyhedralSphericalHarmo.hpp
@Author Benjamin Bercovici (bebe0705@colorado.edu) (from the original code by 
Yu Takahashi and Siamak Hesar)
@date   October, 2017
@brief  Declaration of the methods enabling the
computation of exterior gravity spherical harmonics
coefficients about a polyhedral shape model. 
*/


#ifndef HEADER_SHARMLIB
#define HEADER_SHARMLIB

#include <armadillo>

#define NM_DIM_MAX 70
#define DIM_MAX (NM_DIM_MAX+1)*(NM_DIM_MAX+2)/2

/* macro to access trinomial coefficients */
/* coded as a macro so the compiler can optimize loop invariants */

#define Index(i,j,k,n) ( ((n)-(i)) * ((n)-(i)+1) / 2 + (k) )

namespace SHARMLib {

/**
structure to store trinomial coefficients
**/
    typedef struct {
        int degree;
    double data [DIM_MAX]; /* worst-case dimension */
    } Trinomial;


    void    CalculateBasicTables (int n_degree,
      double (&mixingFactors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
      int (&trinomialCoefficientCount)[NM_DIM_MAX + 1]);
    void    CalculateFullyNormalizedTables (int n_degree,
        double (&diagonalFactors) [NM_DIM_MAX + 1],
        double (&subdiagonalFactors) [NM_DIM_MAX + 1],
        double (&vertical1Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double (&vertical2Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1]);
    void    CalculateUnnormalizedTables (int n_degree,
       double (&diagonalFactors) [NM_DIM_MAX + 1],
       double (&subdiagonalFactors) [NM_DIM_MAX + 1],
       double (&vertical1Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
       double (&vertical2Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1]);

    double  IntegrateOneSimplex (const Trinomial *tri,
       double (&mixingFactors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1] [NM_DIM_MAX + 1]);
    void    TriAdd  (Trinomial * const result,
       const Trinomial * const left,
       const Trinomial * const right,
       int (&trinomialCoefficientCount)[NM_DIM_MAX + 1]);
    void    TriCopy (Trinomial * const target, const Trinomial * const source,
       int (&trinomialCoefficientCount) [NM_DIM_MAX + 1]);

    void    TriMult (Trinomial * const result, const Trinomial * const left,
       const Trinomial * const right,
       int (&trinomialCoefficientCount) [NM_DIM_MAX + 1]);

    void    TriMultScalar (Trinomial * const result, const double scalar,
     int (&trinomialCoefficientCount) [NM_DIM_MAX + 1]);
    void    TriPrint (const Trinomial * const tri, const char * words);
    void    TriSub  (Trinomial * const result, const Trinomial * const left,
       const Trinomial * const right,
       int (&trinomialCoefficientCount) [NM_DIM_MAX + 1]);




/*
Accumulate contribution of one simplex to potential coefficients Cnm and Snm.
@param n_degree degree of the expansion to build
@param Cnm array of Cnm to be incremented
@param Snm array of Snm to be incremented
@param x0 coordinates x component of the first vertex
@param y0 coordinates y component of the first vertex
@param z0 coordinates z component of the first vertex
@param x1 coordinates x component of the second vertex
@param y1 coordinates y component of the second vertex
@param z1 coordinates z component of the second vertex
@param x2 coordinates x component of the third vertex 
@param y2 coordinates y component of the third vertex  
@param z2 coordinates y component of the third vertex
@param trinomialCoefficientCount
@param diagonalFactors
@param subdiagonalFactors
@param vertical1Factors
@param vertical2Factors
@param mixingFactors
@param ref_radius reference radius in the expansion
*/
    void AccumulateOneSimplex (
        int n_degree,
        double Cnm [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double Snm [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double x0, double y0, double z0,
        double x1, double y1, double z1,
        double x2, double y2, double z2,
        int (&trinomialCoefficientCount) [NM_DIM_MAX + 1],
        double (&diagonalFactors) [NM_DIM_MAX + 1],
        double (&subdiagonalFactors) [NM_DIM_MAX + 1],
        double (&vertical1Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double (&vertical2Factors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double (&mixingFactors) [NM_DIM_MAX + 1] [NM_DIM_MAX + 1] [NM_DIM_MAX + 1],
        double ref_radius
        );




/*
Accumulate contribution of one polyhedral element
@param Cnm2f contribution to the total Cnm for this element
@param Snm2f contribution to the total Snm for this element 
@param n_degree degree of the expansion to build
@param ref_radius reference radius in the expansion
@param r0 pointer to coordinates of first vertex
@param r1 pointer to coordinates of second vertex
@param r2 pointer to coordinates of third vertex
@param normalized true if the normalized coefficients should be computed
*/
    void ComputePolyhedralCS(
        arma::mat & Cnm2f,
        arma::mat & Snm2f,
        int n_degree, 
        double ref_radius,
        double * r0,
        double * r1,
        double * r2,
        bool normalized) ;

    void GetBnmNormalizedExterior(int n_degree,
        arma::mat & b_bar_real,
        arma::mat & b_bar_imag,
        const arma::vec & pos,
        double ref_radius);

}



#endif