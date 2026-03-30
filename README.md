<span style="color:gold">*This project has been created as part of the 42 curriculum by jodone & mgarnier.*</span>

# <h1 align="center"><p style="font-size: 90px;"><span style="color:gold">CUB</span><img src="images/gold-and-white-3d.png" width="70"></h1>

## <span style="color:green">Description</span>

This project is a 3D graphical game inspired by the classic Wolfenstein 3D.
It is considered the first true "First Person Shooter" in video game history.
The goal of this project is to learn the technique used: raycasting.
There were several challenges we had to overcome:
- parsing of the map and textures
- adapting raycasting to the MLX library
- optimizing performance

## <span style="color:green">Instructions</span>

`make`

`./cub3D map.cub`

### Movements:

-	`W` move forward
-	`S` move backward
-	`A` move left
-	`D` move right

-	`LEFT_KEY`  rotate left
-	`RIGHT_KEY` rotate right

### Settings:

-	`UP_KEY`   increase speed
-	`DOWN_KEY` decrease speed
-	`E` increase the minimap size
-	`R` decrease the minimap size

-	`M` toggle mouse on/off

## <span style="color:green">Resources</span>

We used a rewritten version of the Minilibx graphics API: [MacrolibX](https://macrolibx.kbz8.me/) by kbz_8.

We used the [Lodev](https://lodev.org/cgtutor/raycasting.html)'s website to learn about raycasting.

Some examples of our game:

<video src="images/demo.mp4" autoplay loop muted width="600"></video>