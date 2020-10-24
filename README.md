# monte-carlo-var-simulator

This is a C++ implementation for a Monte-Carlo Value at Risk simulation engine used to simulate risk factors on a portfolio of assets.


## Notes

#### Const functions

A "const function", denoted with the keyword const after a function declaration, makes it a compiler error for this class function to change a member variable of the class. 

#### Signed versus unsigned numbers

Signed numbers use sign flag or can be distinguish between negative values and positive values. Unsigned numbers store only positive numbers.

#### Covariance 

Covariance between variables i and j over some time period T, can be calculated as:

```
for t < T: 
{
    cov += i_t * j_t
}
return cov / (T-1)
```

#### Using `enum` to perform different calculations 

Returns can be defined in mutliple ways. Add return types in `ReturnType.h`, and implement these with a `case` block in `TSHandler.cpp`.

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