# N Queen 

N Queen problem is NP HARD problem.<br>
Optimization of check is done using:<br>
    column and diagonal hashing in the function 

```
 bool isSafe(int row, int colum){
        bool LD = leftDia[(row - colum)+(sz -1)];
        bool RD = rightDia[row+colum];
        bool column = col[colum];
        if(LD || RD || column) return false;
        return true;
    }
```


### Time Complexity and Space Complexity

Time Complexity is O(n!) <br>
Space Complexity is O(n)


# Hamiltonian Cycle

It is NP-complete problem where soltuions requires to find a close loop covering all vertices exactly once.

### Time Complexity and Space Complexity

Time Complexity is O(n!)<br>
Space Complexity is O(n)