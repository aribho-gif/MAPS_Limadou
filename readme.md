# MAPS exp. 1: LIMADOU  -  LabII, Group 4
## Brief files description
### Read_data.py
Python code (much simpler than c++) that reads a csv file, transfers it in a pandas DF and writes the DF in a .dat file.
Once we have the file .dat I find really simpler to use in a c++ code.

### Usedata.C 
*The proposal of the method for importing the data in the code.* In this version it uses a TNtuple (just because of its simplicity wrt the tree), which can be sufficient for the bkg analysis. For the tracks reconstuction it's probably better to just create directly a Class and the TTree... see tree.C description

### Tree.C
The code to implement the extraction of data from .dat files, importing it into a TTree. Useful for advanced analysis: cluster search, tracks, ...

## Analysis
### POINT CLASS: to analyse hits and reconstruct their position
1. Create a Point class, which contains as data member the "data 3D position" of an hit: chip number, hit_x,hit_y. The real 3D position (x,y,z in the detector space) can be found via simply conversions
- chip number -> hex(): we obtain something like 0x171, where the first number is the *stave plane*, and the last is the *chip*
- z = stave * distance between staves
- x, y from hit_x, hit_y + info from the *chip* (an hit on chip 1 will have the coodinates of the hit + the distance from chip 0)
2. Implement the function for the conversion and the get functions (in particular getChipNumber, getStaveNumber)

### TTREE: to efficiently store and use the data
T&E with different branches to find the best Tree development
Implement a way to store the data in the Tree respecting the event number 

### CLUSTER SEARCH
Cluster research:
1. data stored in the TNtuple/TTree
2. loop over the same event
3. loop over the same chip
4. loop over every hit to find another one near it (x_hit - 1 <= x_hit' <= x_hit + 1, y_hit - 1 <= y_hit' <= y_hit + 1) without counting the same cluster 2 times

