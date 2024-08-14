# Coin Change Problem - Count Ways to Make a Given Amount

This repository contains a C++ implementation of the Coin Change problem, which calculates the number of different ways to make a given amount using a set of coins.

## Problem Description

Given an array `coins` representing different denominations of coins and an integer `sum`, find out the number of different ways to make up that amount using the provided coins. You can assume that you have an infinite number of coins of each denomination.

### Example

```cpp
int coins[] = {1, 2, 3};
int N = 3;  // Number of different coins
int sum = 4;
Solution ob;
long long int result = ob.count(coins, N, sum);
cout << result << endl;
