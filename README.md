# CPE_2016_Lemin

### Introduction

```
The objective of this program is to find the quickest way to make the ants cross over the anthill. To do so, each single
ant need to take the shortest route (and not necessarily the easiest), whithout walking on its peers, and avoiding traffic
jams.
```

### Prerequisites

What things you need to install the Lemin

```
GlibC ,GCC ,make and CSMFL for the bonus
```

### Installing

There is a Makefile in the repository

```
make
```

### Usage

```
./lemin < map
./lem_in < map | ./visu-hex [--host],
./visu-hex [--client] [Ip Address]

```

### Example Map

```
3
##start
0 1 0
##end
1 13 0 #bedroom
2 5 0
# The next room is the kitchen
3 9 0
0-2
2-3
3-1
```

## Authors

* **Nikola Tomic** - *Algorithms for resolution and exit* - [Pujomir](https://github.com/Pujomir)
* **Léandre Blanchard** - *Network , Graphical interface and parsing bonus* - [LeandreBL](https://github.com/LeandreBl)
* **Antoine Le Dû** - *Algorithms for resolution and exit* - [Sezny](https://github.com/sezny)
* **Quentin Sonnefraud** -*Creation of the graph, Error Management and map parsing* - [Vatoth](https://github.com/Vatoth)

Made with love at Epitech Paris in 2017
