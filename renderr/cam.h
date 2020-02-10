#ifndef CAMERAH
#define CAMERAH

#include <cstdlib>
#include "ray.h"
#include "float.h"

inline double random_double() {
    return rand() / (RAND_MAX + 1.0);
}

class cam {
    public:
        cam() {
            origin = vec3(0.0,0.0,0.0);
            lower_left_corner = vec3(-2.0,-1.0,-1.0);
        	horizontal = vec3(4.0,0.0,0.0);
        	vertical = vec3(0.0,2.0,0.0);
		
           }
        ray get_ray(float s, float t) {
            return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
        }


vec3 random_in_unit_sphere() {
    vec3 p;
    do {
        p = 2.0*vec3(random_double(),random_double(),0) - vec3(1,1,1);
    } while (dot(p,p) >= 1.0);
    return p;
}
 
        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
       
};


#endif