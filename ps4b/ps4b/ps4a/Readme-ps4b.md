# PS4b: Sokoban

## Contact
Name:Philopater Askander
Section:203
Time to Complete: 40 hours


## Description
The purpose of my code is to implement the game features of the previous project. In PS4a, I was required to make the UI, but for this project, I had to make a player move using all four directions, move the box, and stop movement if a wall has been hit. 

### Features
My code doesn't work fully, but there are a few cool features. The character does move freely and does not move if there's a wall in front of him. The character can move the box sometimes, but not always. There's a bug when I was trying to find a way to change the position of the box once it has been moved that I wasn't able to figure out.

### Memory
I stored the data in a two dimensional array. This allowed me to go in and out of the map when identifying what characters correspond with a wall and other items.

### Lambdas
The lamdba expression I wrote was used to print the value of the vector that contained the position of the box. My thought process was to create a vector that stored the position of the box so I could then go into the vector to see if the guy's position matched the position in the vector. If it did, then the box would move foreward 64 increments and the guy would remain in position. The issue with this was, I was trying to find a way to pop_back the values that were replaced with the new values, but every method I tried failed so i wasn't able to succesfully complete it. The algorithm I used was the std::count algorithm, which allowed me to identify is the next position the guy was going to matched with the positions stored into the vector that had all the positions of the walls from the 2d array.
### Issues
As mentioned previously, what doesn't work is the moving of boxes sometimes, and the game also doesn't detect if the game was successfully completed.

### Extra Credit
One special case that I did implement was the guy changes figures depending on his direction

## Acknowledgements
James Daly tried helping me
