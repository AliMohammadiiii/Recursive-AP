# Recursive-AP
Here are several problems related to recursive solving with the C++ language
**Problem 1** Albert, who lives in Nerd City, is returning home. The buildings of each street in Nerda city have the following features:
1. All city streets are one way
2. Every street has exactly one building that is taller than all the other buildings on that street
3. The height sequence of the buildings before the building with the maximum height is strictly ascending
4. The sequence of the height of the buildings after the building with the maximum height is strictly descending
In other words, in every street we have a sequence of buildings as follows, where h[1] shows the height of the first building on the street and h[n] shows the height of the last building, the IM building is the tallest building.
h[1] < ... < h[i-1] < h[i] > h[i+1] > ... >h[n]
In the city of nerds, entering every street requires a password. The code of each street is the index of the highest building. Albert has forgotten his street code and cannot return home.

**Problem 2** When Albert arrived at his house, he remembered that he had forgotten the key to the house but remembered another way to enter the house. He can play a game with the door lock. The input lock gives two numbers n and k to Albert. Anyone who enters all the n-digit numbers whose consecutive digits differ exactly k as the answer to the house lock succeeds in entering the house.

**Problem3** Albert decided to jump between the roofs of the houses in their city. His ability to jump is so high that he can only jump between the adjacent houses whose height difference is exactly one unit.
You will be given an aerial map and help him jump the furthest distance
