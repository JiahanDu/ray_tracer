# ray_tracer

1. The ray tracer is based on the book series Ray Tracing in One Weekend, and its followups: Ray Tracing the Next Week and Ray Tracing the Rest of Your Life.

2. Vector.h file includes basic utility functions for dealing with three dimensional vector calculus. 

3. The Point and Color class inherit the Vector class template, implemented using the curiously recurring template pattern to ensure compile time error for incompatible types of operations between points and colors.

4. The Object class represents all shapes and surfaces included in our scene. We plan to implement both orientable surfaces (like planes and spheres) and non-orientable surfaces (such as the Möbius band and the Klein bottle).

5. We use Monte Carlo sampling techniques to effectively reduce aliasing artifacts.