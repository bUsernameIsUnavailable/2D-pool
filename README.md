# 2D Pool
2D Pool is a very bare-bones graphics engine that simulates a pool-like game.

## ECS
The engine was implemented using the [Entity Component System](https://en.wikipedia.org/wiki/Entity_component_system) architectural pattern, most commonly used in video games thanks to how performant it can be.

I have implemented it this way, despite not needing the performance boost, because I wanted to see how the pattern could be implemented at a low-level instead of the usual [Object-Oriented Programming](https://en.wikipedia.org/wiki/Object-oriented_programming) paradigm.

The code has been adapted from [the website](https://austinmorlan.com/posts/entity_component_system/) of Austin Morlan, a very seasoned C++ programmer.

#### Entities
Anything that exists within the game world is an entity. This includes the pool table, the 4 margins and the balls.

#### Components
Components are simply structures of data which give entities meaning. An entity by itself is only an index, so each component that it owns adds more data.

#### Systems
The entities along with their components don't do anything by themselves. The systems are the ones that act upon certain entities depending on the components that they're looking for.

## Rendering
The graphics are drawn using [OpenGL](https://www.opengl.org/), along with additional libraries [GLM](https://github.com/g-truc/glm) and [SOIL](https://github.com/littlstar/soil) to make matrix calculations easier and allow texturing.

## Collisions
In order to check for collisions, the engine uses the [Separating Axis Theorem (SAT)](https://en.wikipedia.org/wiki/Hyperplane_separation_theorem), which works for any 2 convex shapes. Resolving the collision is done using the code taken from [a question](https://stackoverflow.com/questions/345838/ball-to-ball-collision-detection-and-handling/345863) on Stack Overflow that's based on the [impulse momentum theorem](https://en.wikipedia.org/wiki/Impulse_(physics)).

![Collision Demo](demo/collision_demo.gif)

# Issues
The project is by no means a game and is only meant to be a learning experience on how to render computer graphics and how to implement collisions in 2D.

### Engine
This engine is very unoptimised because it's only been made in a few days by a student without prior experience in developing something similar.

### Collisions
The collision detection algorithm is discrete, potentially causing [tunnelling](https://en.wikipedia.org/wiki/Tunnel_effect) to occur. Additionally, the engine lags whenever 2 or more balls approach each other, which can cause unusual things to happen to their velocities.

## License
[GNU General Public License v3.0](https://choosealicense.com/licenses/gpl-3.0/)