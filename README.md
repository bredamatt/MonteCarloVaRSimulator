# monte-carlo-var-simulator

This is a C++ implementation for a Monte-Carlo Value at Risk simulation engine used to simulate risk factors on a portfolio of assets.


## C++ Notes

### Const functions

A "const function", denoted with the keyword const after a function declaration, makes it a compiler error for this class function to change a member variable of the class. 

### Signed versus unsigned numbers

Signed numbers use sign flag or can be distinguish between negative values and positive values. Unsigned numbers store only positive numbers.

### Using `enum` to perform different calculations 

Returns can be defined in mutliple ways. Add return types in `ReturnType.h`, and implement these with a `case` block in `TSHandler.cpp`.

## Statistics notes

### Covariance 

Covariance measures the joint variability of two random variables. In essence, it measures the degree to which two random variables deviate from their expected values in similar ways.

For example, the (average) covariance between variables x and y over some time period T, can be calculated as:

<!-- $$
cov_{x,y} = \frac{\sum_{t=1}^{T}(x_{t} - \bar{x})(y_{t} - \bar{y})}{T - 1} 
$$ --> 

<div align="center"><img src="svg/dY66FRPqp8.svg"/></div>

where the means of the variable x is define as:

<!-- $$
\bar{x} = \frac{\sum_{t=1}^{T}{x_{t}}}{T-1}
$$ --> 

<div align="center"><img src="svg/c4s7H0HgH5.svg"/></div>


### Covariance matrix 

A covariance matrix represents the covariance between multiple variables i and j, in which the (i,j) element in the matrix is the covariance between the variables i and j.

Intuitively, the covariance matrix generalizes the notion of variance to multiple dimensions. As an example, the variation in a collection of random points in two-dimensional space cannot be characterized fully by a single number, nor would the variances in the i and j directions contain all of the necessary information.

For a random vector X, we denote the covariance matrix of X as:

<!-- $$
\pmb{K_{\pmb{XX}}}
$$ --> 

<div align="center"><img src="svg/1NYReOJb0e.svg"/></div>


More generally, if the entries in the column vector:

<!-- $$
\pmb{X} = \{ X_{1}, X_{2}, ..., X_{n} \}^{T}
$$ --> 

<div align="center"><img src="svg/Bl1s3DT9Am.svg"/></div>

are random variables, each with finite variance and expected value / mean, the covariance matrix of this random vector is the matrix whose (i, j) entry is the covariance defined as follows:

<!-- $$
\pmb{K_{\pmb{X_{i}X_{j}}}} = cov[X_{i}, X_{j}] = E[(X_i) - E[X_{i}])(X_{j} - E[X_{j}])]
$$ --> 

<div align="center"><img src="svg/Wj99zPWW8l.svg"/></div>

## Day 1

1. Implement TimeSeriesHandler and ReturnType enumerator class.

The TimeSeriesHandler should:

- generate a covariance matrix 
- generate spot rates 
- transform to returns,
- compute covariance for two risk-factors

2. Implement Cholesky decomposition from covariance matrix 

## Day 2 

## Day 3

## Day 4 