# Wolf3d
21 School's project about computer graphics and raycasting.

## What I did
At first, I drew some walls, using a simple raycasting technique.
In short, every column of the screen is a ray, which goes through a 2D array, until it hits a wall. Then, based on the distance to the wall, I can calculate the height of the wall on the screen.
![](https://i.imgur.com/rq6RZsI.png)

---

Sprites are, at first, just squares on the screen. To know where on the screen they go, I use the angle between camera's direction and sprite's position. And size is just the distance between the two.
![](https://i.imgur.com/rMtggrS.png)

---

To hide sprites behind walls I remember distances to walls, then I draw objects column by column, comparing distance to the sprite with wall distance, and not drawing if the latter is smaller. I also use magenta as a transparency color, so if the sprite has a magenta pixel, I just don't draw it.
![](https://i.imgur.com/6DaJO8o.png)

---

A small command line profiler is very useful so that I know if I'm under my preferred 60 fps limit.
![](https://i.imgur.com/TPEYyNp.png)

---

As I wanted to add some mobs, I needed pathfinding, so I implented an ordinary A* algorithm.
![](https://i.imgur.com/3VwVyaZ.png)
![](https://i.imgur.com/A5FNvEv.png)

---
This is how the map that Wolf3D reads looks like.
![](https://i.imgur.com/oexUpDK.png)

## End result
In the end, I added some guns, animations, which are as simple as changing sprites and mobs. Here is the end result!
![](https://i.imgur.com/sfCH4eM.png)
![](https://i.imgur.com/nlU2ldC.png)
![](https://i.imgur.com/1DCl4l2.png)

## Made by
**Starnuik** aka sbosmer
