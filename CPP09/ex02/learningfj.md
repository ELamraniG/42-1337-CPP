// INPUT: 9 5 7 8 3 4 1 2 6
// PAIRS (larger first):
// [9 5]   [8 7]  [4 3]   [2 1]   6(leftover)
// 
// LARGER ELEMENTS: 9 8 4 2
// SMALLER ELEMENTS (pend): 5 7 3 1
// 
// RECURSIVELY SORT LARGER: [9 8 4 2]
// Make pairs: [9 8] [4 2]
// Recurse on [9 4] -> becomes [4 9]
// Result after recursion: [2 4 8 9]
// 
// NOW WE HAVE:
// mainChain = [2 4 8 9]  (sorted larger elements)
// pend = [5 7 3 1]       (smaller elements waiting to insert)
// 
// JACOBSTHAL INSERTION ORDER:
// Jacobsthal sequence: 0 1 1 3 5 8 13...
// For 4 pend elements, insertion order: [0, 2, 1, 3]
// This means: insert pend[0] first (at beginning)
// Then pend[2], then pend[1], then pend[3]
// 
// BUILDING MAINCHAIN:
// mainChain.insert(begin, pend[0]) -> [5 2 4 8 9]
// 
// BINARY SEARCH INSERT REST:
// pend[2]=3: binary_search in [5 2 4 8 9] -> [2 3 4 5 8 9]
// pend[1]=7: binary_search in [2 3 4 5 8 9] -> [2 3 4 5 7 8 9]
// pend[3]=1: binary_search in [2 3 4 5 7 8 9] -> [1 2 3 4 5 7 8 9]
// 
// INSERT LEFTOVER:
// leftover=6: binary_search in [1 2 3 4 5 7 8 9] -> [1 2 3 4 5 6 7 8 9]
// 
// FINAL SORTED: [1 2 3 4 5 6 7 8 9] ✓