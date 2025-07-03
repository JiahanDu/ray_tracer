# ray_tracer

1. The ray tracer is based on the book series Ray Tracing in One Weekend, and its followups: Ray Tracing the Next Week and Ray Tracing the Rest of Your Life.
   We provide optimization, bench marking and other information here.
2. For the vector class, we use curiously recurring template pattern to maximize code reuse, and to make sure one cannot add vectors of different types (e.g. you cannot add
   point and color or dot product point and color). Curiously recurring template pattern (CRTP) also avoid the runntime overhead of virtual functions.

