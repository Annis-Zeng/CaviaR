#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector caviar_AS(NumericVector BETA, NumericVector y, double empiricalQuantile, NumericVector VaR, int RowsOfy)
{
  int i;
  
  /* Initialize output variables */
  VaR[0] = empiricalQuantile;
  
  /* Start the loop */
  for(i = 1; i < RowsOfy; i++)
  {
    // Asymmetric Slope
    VaR[i] = BETA[0] + BETA[1] * VaR[i-1] + BETA[2] * y[i-1] * (y[i-1] > 0) - BETA[3] * y[i-1] * (y[i-1] < 0); 
  }
  return VaR;
}