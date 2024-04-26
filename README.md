⚠️ This version of the project has been made using the MAC OSX version of the mlx ⚠️

This version isn't meant to be compilated, let alone tested.
But you can browse the repository in order to inform yourself about how raycasting works.

The engine used is called minilibx, a homemade engine from the 42 school.
The only functions you need to remember are :
- mlx_loop() | Creates a loop on a single thread, executing the functions inside indefinitely
- mlx_hook() | Depending on the parameters, it will listen to your mouse, keyboard, or an action done with the window
- mlx_new_window() | creates an empty window, I tried making multiple windows but never figured out how, guess we can't
- mlx_new_image() | the most important one, this will contain every single image which will be built pixel by pixel, then sent inside the loop

Raycasting is quite simple to understand, but hard to code from scratch, you'll need to learn how to rotate and move a point on a plane.
What is a DDA (quite important), what does the "ray" in raycasting means and how do we calculate the distance between the player and the walls.

To start off, what is raycasting ?
To simulate a 3D environment, 40+ years ago, people thought about putting a player in a grid, filled with zeros and ones. Every '1' is a wall and every '0' is a walkable area.
The player will send hundreds if not thousands of rays in a specific field of view, and verify each pixel to check where the wall is.
There is just as much rays as there pixels in the screen width, so for a 1920x1080 resolution, we would used 1920 rays in a field of view of 60.

What is a DDA ?
The problem with that system, is that it's SLOW, painfully SLOW.
So in the 90's, John Carmack came up with the idea of checking the presence of walls only where they are supposed to be.

How to rotate/move the player ?
The map is strictly two dimensional, so only an [x,y] plane. However, rotating means turning in a circle, or 360°.
In this context, a circle is not represented as a 360° sphere, but rather four quadrants, each measuring 1/2 of π, so a complete rotation will reasult in π².
Moving the player simply involves changing his [x,y] coordinates, depending on the direction he's looking at.

Explaining in detail the formulas here is not the point, but to understand how it works and differs from conventional math.
Since this is a school project, I do not intend on giving the answers but rather encourage you by finding them yourself.


Here in a picture that I totally didn't snag from google, you have a clear representation of raycasting.
The bottom left map is simply a representation of the system, but as you can see, the walls appearance and their size depends on the distance between the player and them.
The floor and ceiling are simply random colors printed on each halves of the window before the walls are displayed.

<img src="http://jackkelly.name/blog/images/learning-to-raycast-in-haskell/basic_shading.png"></img>

In this image, the player check for the presence of walls on a single ray.
Instead of checking each pixel to find the wall, we will increment a certain [x,y] value to the player's coordinates.
Once we incremented them, we simply check where we are on the grid, is it a '1' or a '0' ? If it's a '0'. we increment again, if it's a '1', we stop and check the next ray.
Finding the value for the intervals between each jumps is left at your discretion, although you can find the answers here, I strongly suggest you figure it out yourself.

<img src="https://i.stack.imgur.com/TXHJB.png" style="width:50%;"></img>
