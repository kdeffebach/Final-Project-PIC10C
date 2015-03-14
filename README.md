# Final-Project-PIC10C
Settlers of Catan Game

The main center of play contains a grid board on which the player moves around trying to collect resources: wood, wheat
ore or brick. Each of the squares on the grid board has a resource and a number associated to it. The player can collect the resource by pressing the
spacebar if the die roll matches the number on the square they are trying to collect. If it is a valid collection the count of that particular
resource increases.
The player can build three different structures with the resources: villages, cities, or roads. A village is worth one point, a city is worth two points,
and 5 roads in a row is worth one point. The player needs 10 points to win on settler difficulty, 12 on invader difficulty, and 15 on conquest difficulty.
Villages cost one of each resource, roads cost one brick and one wood, and cities cost two ore and one wheat. The player builds a road by pressing 'b', a
village by pressing 'v' and a city by pressing 'c'.
While the player is trying to build structures, a random number generator determines when robbers are added to the count, and if the robbers get to a
certain count (300,400,500) for the different levels before the player gets the required number of points the game is over and the player loses. If the
player earns the required amount of points before the number of robbers is breached they win.
