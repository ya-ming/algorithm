# Percolation

This is a C++ implementation of the percolation problem presented in the [Coursera's Algorithm course](https://www.coursera.org/learn/algorithms-part1) to apply the Union Find algorithm.

The detail of the percolation problem is described in (here)[https://coursera.cs.princeton.edu/algs4/assignments/percolation/specification.php]

# Test Result

The result and test of the PercolationStats test is as below:

```
200x100
mean                    = 0.5928565
stddev                  = 0.00967445390362336
95% confidence interval = [0.59096030703489, 0.59475269296511]

200x100
mean                    = 0.592876
stddev                  = 0.0105193946181001
95% confidence interval = [0.590814198654852, 0.594937801345148]

2x10000
mean                    = 0.66485
stddev                  = 0.11848367540777
95% confidence interval = [0.662527719962008, 0.667172280037992]

2x100000
mean                    = 0.6665075
stddev                  = 0.117907872792271
95% confidence interval = [0.665776699433106, 0.667238300566894]
```

### Running time measurement

Based on the measurement:
* Double the number of sites, quadruple the processing time
* Double the number of trails, double the processing time

| N   | T   |  CPU Time used in ms  |
|-----|-----|:---------------------:|
| 100 | 100 | 216                   |
| 200 | 100 | 860                   |
| 400 | 100 | 3620                  |
| 100 | 200 | 421                   |
| 100 | 400 | 846                   |