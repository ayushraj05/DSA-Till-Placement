# Merge Sort Algorithm

## Overview

Merge Sort is a divide-and-conquer sorting algorithm. It works by recursively dividing the array into two halves, sorting each half, and then merging the sorted halves to produce a sorted array.

## How It Works

1. **Divide**: Split the array into two halves until each half contains a single element.
2. **Conquer**: Sort each half recursively.
3. **Combine**: Merge the sorted halves back together to get the final sorted array.

## Steps

1. **Divide**: Split the array into two equal (or nearly equal) parts.
2. **Recursively Sort**: Sort each part.
3. **Merge**: Combine the sorted parts into a single sorted array.

## Example

Given the array `[5, 2, 9, 1, 5, 6]`:

1. Split: `[5, 2, 9]` and `[1, 5, 6]`
2. Sort each half: `[2, 5, 9]` and `[1, 5, 6]`
3. Merge: `[1, 2, 5, 5, 6, 9]`

## Time Complexity

- **Best Case**: O(n log n)
- **Average Case**: O(n log n)
- **Worst Case**: O(n log n)

## Space Complexity

- **Auxiliary Space**: O(n)

## Summary

Merge Sort is an efficient and stable sorting algorithm with consistent performance across different cases. It requires additional space proportional to the size of the array, but it guarantees a time complexity of O(n log n).

