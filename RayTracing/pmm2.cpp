
//Code for the ppm file after implementing "hitablelist.h" header, antialiasing and forming matte objects!

#include<iostream>
#include "sphere.h"
#include "hitable_list.h"
#include "float.h"
#include "camera.h"
#include<fstream>
using namespace std;

vec3 random_in_unit_sphere() {                                                  //randomizes ray directons -> causes shadows to form...nooiiiceeee....looks cooler!!
    vec3 p;
    do {
        p = 2.0*vec3(drand48(), drand48(), drand48()) - vec3(1,1,1);
    } while(p.squared_length() >= 1.0);
    return p;
}



vec3 color(const ray& r, hitable *world){
    hit_record rec;
    if(world->hit(r,0.001, MAXFLOAT, rec)) {
        vec3 target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5*color( ray(rec.p, target - rec.p), world);
    }
    else {
        vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5*(unit_direction.y() + 1.0 );
        return (1.0-t)*vec3(1.0,1.0,1.0) + t*vec3(0.5, 0.7,1.0);                //changing entries accordingly changes colours and texture.
    }
    
}
    

int main(){ 
    ofstream img("picture.ppm") ; 
    int nx = 1000;
    int ny = 500;
    int ns = 500;
    img<<"P3\n"<<nx<<" "<<ny<<"\n255\n";
    /*vec3 lower_left_corner(-2.0,-1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0,2.0,0.0);
    vec3 origin(0.0,0.0,0.0);*/
    hitable *list[2];
    list[0] = new sphere (vec3(0,0,-1), 0.5);                    //changing the position of the sphere -> +ve value makes the sphere disappear as it comes behind the camera on
                                                                //the +ve z axis. z=0, results in an image similar to the one obtained at the start in chapter 1.
                                                                //the x and y values can also be accordingly varied in order to shift the sphere on the screen.
                                                                //This happens as the center is varied.
                                                                //on lateral movement the shape changes to OVAL, ask why?



    list[1] = new sphere (vec3(0, -100.5, -1),100);             
    hitable *world = new hitable_list(list,2);
    camera cam;
    
    for(int j =ny-1; j>=0 ;j--){
        for(int i=0; i< nx; i++){
            vec3 col(0,0,0);
            for(int s=0;s<ns;s++){
                
                float u = float(i+drand48())/float(nx);
                float v = float(j+drand48())/float(ny);
                ray r = cam.get_ray(u,v);
                vec3 p= r.point_at_parameter(2.0);
                col+= color(r,world);
            }
            
            col/= float(ns);
            col = vec3( sqrt(col[0]), sqrt(col[1]), sqrt(col[2]) );
            
            
            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);
            img<<ir<<" "<<ig<<" "<<ib<<endl;
        }
    }
    system("open picture.ppm");
}
