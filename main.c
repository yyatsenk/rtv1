//HEADER

#include "rtv1.h"


#include <stdio.h>
#include <stdbool.h> /* Needed for boolean datatype */
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Width and height of out image */
#define WIDTH  800
#define HEIGHT 600

/* The vector structure */
typedef struct{
      float x,y,z;
}vector;

/* The sphere */
typedef struct{
        vector pos;
        float  radius;
	int material;
}sphere; 

/* The ray */
typedef struct{
        vector start;
        vector dir;
}ray;

/* Colour */
typedef struct{
	float red, green, blue;
}colour;

/* Material Definition */
typedef struct{
	colour diffuse;
	float reflection;
}material;

/* Lightsource definition */
typedef struct{
	vector pos;
	colour intensity;
}light;

/* Subtract two vectors and return the resulting vector */
vector vectorSub(vector *v1, vector *v2){
	vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z };
	return result;
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vectorDot(vector *v1, vector *v2){
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* Calculate Vector x Scalar and return resulting Vector*/ 
vector vectorScale(float c, vector *v){
        vector result = {v->x * c, v->y * c, v->z * c };
        return result;
}

/* Add two vectors and return the resulting vector */
vector vectorAdd(vector *v1, vector *v2){
        vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
        return result;
}

/* Check if the ray and sphere intersect */
bool intersectRaySphere(ray *r, sphere *s, float *t){
	
	bool retval = false;

	/* A = d.d, the vector dot product of the direction */
	float A = vectorDot(&r->dir, &r->dir); 
	
	/* We need a vector representing the distance between the start of 
	 * the ray and the position of the circle.
	 * This is the term (p0 - c) 
	 */
	vector dist = vectorSub(&r->start, &s->pos);
	
	/* 2d.(p0 - c) */  
	float B = 2 * vectorDot(&r->dir, &dist);
	
	/* (p0 - c).(p0 - c) - r^2 */
	float C = vectorDot(&dist, &dist) - (s->radius * s->radius);
	
	/* Solving the discriminant */
	float discr = B * B - 4 * A * C;
	
	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
	if(discr < 0)
		retval = false;
	else{
		float sqrtdiscr = sqrtf(discr);
		float t0 = (-B + sqrtdiscr)/(2);
		float t1 = (-B - sqrtdiscr)/(2);
		
		/* We want the closest one */
		if(t0 > t1)
			t0 = t1;

		/* Verify t1 larger than 0 and less than the original t */
		if((t0 > 0.001f) && (t0 < *t)){
			*t = t0;
			retval = true;
		}else
			retval = false;
	}

return retval;
}
/*
float		k;

	k = mlx->i[mlx->iter].rad;
	mlx->i[mlx->iter].rot.y = 1;
	mlx->dist = vecsub(origin, mlx->i[mlx->iter].vec);
	mlx->k1 = vecdot(dir, dir) - pow(vecdot(dir, mlx->i[mlx->iter].rot), 2)
		* (1 + k * k);
	mlx->k2 = 2 * (vecdot(dir, mlx->dist) - (1 + k * k)
		* vecdot(dir, mlx->i[mlx->iter].rot)
		* vecdot(mlx->dist, mlx->i[mlx->iter].rot));
	mlx->k3 = vecdot(mlx->dist, mlx->dist) - (1 + k * k)
		* pow(vecdot(mlx->dist, mlx->i[mlx->iter].rot), 2);
	mlx->d = mlx->k2 * mlx->k2 - 4 * mlx->k1 * mlx->k3;
	if (mlx->d < 0)
	{
		mlx->t0 = INFINITY;
		mlx->t1 = INFINITY;
		return ;
	}
	mlx->t0 = (-mlx->k2 + sqrtf(mlx->d)) / (2 * mlx->k1);
mlx->t1 = (-mlx->k2 - sqrtf(mlx->d)) / (2 * mlx->k1);
*/
bool intersectRayCylinder(ray *r, sphere *s, float *t){
	
	bool retval = false;
	float		k;
	vector rot = {0,1,0};
	k = s->radius;

	/* A = d.d, the vector dot product of the direction */
	float A = vectorDot(&r->dir, &r->dir) - pow(vectorDot(&r->dir, &rot), 2)\
	*(1 + k * k); 
	vector dist = vectorSub(&r->start, &s->pos);
	
	/* 2d.(p0 - c) */  
	float B = 2 * (vectorDot(&r->dir, &dist) - (1 + k * k)\
	* vectorDot(&r->dir, &rot));
	
	/* (p0 - c).(p0 - c) - r^2 */
	float C = vectorDot(&dist, &dist) - (1 + k * k)\
	* pow(vectorDot(&dist, &rot), 2);
	
	/* Solving the discriminant */
	float discr = B * B - 4 * A * C;
	
	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
	if(discr < 0)
		retval = false;
	else{
		float sqrtdiscr = sqrtf(discr);
		float t0 = (-B + sqrtdiscr)/(2);
		float t1 = (-B - sqrtdiscr)/(2);
		
		/* We want the closest one */
		if(t0 > t1)
			t0 = t1;

		/* Verify t1 larger than 0 and less than the original t */
		if((t0 > 0.001f) && (t0 < *t)){
			*t = t0;
			retval = true;
		}else
			retval = false;
	}

return retval;
}

/* Output data as PPM file */
void saveppm(char *filename, unsigned char *img, int width, int height){
	/* FILE pointer */
	FILE *f;

	/* Open file for writing */
	f = fopen(filename, "wb");

	/* PPM header info, including the size of the image */
	fprintf(f, "P6 %d %d %d\n", width, height, 255);

	/* Write the image data to the file - remember 3 byte per pixel */
	fwrite(img, 3, width*height, f);

	/* Make sure you close the file */
	fclose(f);
}

int main(int argc, char *argv[]){

	ray r;
	t_mlx	mlx;

    mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,\
		WIDTH, HEIGHT, "RTv1");
		mlx.image_ptr = mlx_new_image(mlx.mlx_ptr,\
		WIDTH, HEIGHT);
		mlx.data = (int*)mlx_get_data_addr(mlx.image_ptr, &(mlx.bpp),\
		&(mlx.size_line), &(mlx.end));
	material materials[3];
	materials[0].diffuse.red = 1;
	materials[0].diffuse.green = 0;
	materials[0].diffuse.blue = 0;
	materials[0].reflection = 0.2;
	
	materials[1].diffuse.red = 0;
	materials[1].diffuse.green = 1;
	materials[1].diffuse.blue = 0;
	materials[1].reflection = 0.5;
	
	materials[2].diffuse.red = 0;
	materials[2].diffuse.green = 0;
	materials[2].diffuse.blue = 1;
	materials[2].reflection = 0.9;
	
	sphere spheres[3]; 
	spheres[0].pos.x = 150;
	spheres[0].pos.y = 200;
	spheres[0].pos.z = 0;
	spheres[0].radius = 100;
	spheres[0].material = 0;
	
	spheres[1].pos.x = 400;
	spheres[1].pos.y = 400;
	spheres[1].pos.z = 0;
	spheres[1].radius = 100;
	spheres[1].material = 1;
	
	spheres[2].pos.x = 500;
	spheres[2].pos.y = 140;
	spheres[2].pos.z = 0;
	spheres[2].radius = 100;
	spheres[2].material = 2;
	
	light lights[3];
	
	lights[0].pos.x = 0;
	lights[0].pos.y = 0;
	lights[0].pos.z = -100;
	lights[0].intensity.red = 1;
	lights[0].intensity.green = 1;
	lights[0].intensity.blue = 1;
	
	lights[1].pos.x = 400;
	lights[1].pos.y = -700;
	lights[1].pos.z = -700;
	lights[1].intensity.red = 0.6;
	lights[1].intensity.green = 0.7;
	lights[1].intensity.blue = 1;

	lights[2].pos.x = 1000;
	lights[2].pos.y = 0;
	lights[2].pos.z = -100;
	lights[2].intensity.red = 0.3;
	lights[2].intensity.green = 0.5;
	lights[2].intensity.blue = 1;
	
	/* Will contain the raw image */

	
	int x, y;
	for(y=0;y<HEIGHT;y++){
		for(x=0;x<WIDTH;x++){
			
			float red = 0;
			float green = 0;
			float blue = 0;
			
			int level = 0;
			float coef = 1.0;
			
			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;
			
			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;
			
			do{
				/* Find closest intersection */
				float t = 20000.0f;
				int currentSphere = -1;
				
				unsigned int i;
				for(i = 0; i < 3; i++){
					if(intersectRaySphere(&r, &spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1) break;
				
				vector scaled = vectorScale(t, &r.dir);
				vector newStart = vectorAdd(&r.start, &scaled);
				
				/* Find the normal for this new vector at the point of intersection */
				vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
				float temp = vectorDot(&n, &n);
				if(temp == 0) break;
				
				temp = 1.0f / sqrtf(temp);
				n = vectorScale(temp, &n);

				/* Find the material to determine the colour */
				material currentMat = materials[spheres[currentSphere].material];
				
				/* Find the value of the light at this point */
				unsigned int j;
				for(j=0; j < 3; j++){
					light currentLight = lights[j];
					vector dist = vectorSub(&currentLight.pos, &newStart);
					if(vectorDot(&n, &dist) <= 0.0f) continue;
					float t = sqrtf(vectorDot(&dist,&dist));
					if(t <= 0.0f) continue;
					
					ray lightRay;
					lightRay.start = newStart;
					lightRay.dir = vectorScale((1/t), &dist);
					
					/* Calculate shadows */
					bool inShadow = false;
					unsigned int k;
					for (k = 0; k < 3; ++k) {
						if (intersectRayCylinder(&lightRay, &spheres[k], &t)){
							inShadow = true;
							break;
						}
					}
					if (!inShadow){
						/* Lambert diffusion */
						float lambert = vectorDot(&lightRay.dir, &n) * coef; 
						red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
						green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
						blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
					}
				}
				/* Iterate over the reflection */
				coef *= currentMat.reflection;
				
				/* The reflected ray start and direction */
				r.start = newStart;
				float reflect = 2.0f * vectorDot(&r.dir, &n);
				vector tmp = vectorScale(reflect, &n);
				r.dir = vectorSub(&r.dir, &tmp);

				level++;

			}while((coef > 0.0f) && (level < 15));
			int color;
            color = pow(256,2)* (unsigned char)min(red*255.0f, 255.0f)\
             + 256* (unsigned char)min(green*255.0f, 255.0f) +\
             (unsigned char)min(blue*255.0f, 255.0f);
			mlx.data[(x + y*WIDTH) + 0] = color;
			
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.image_ptr, 0,0);
	//saveppm("image.ppm", img, WIDTH, HEIGHT);
	mlx_loop(mlx.mlx_ptr);
return 0;
}
/*
int 		main(int argv, char **argc)
{
	t_mlx	mlx;

	if (argv == 2)
	{
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,\
		WIDTH, HEIGHT, "RTv1");
		mlx.image_ptr = mlx_new_image(mlx.mlx_ptr,\
		WIDTH, HEIGHT);
		mlx.data = (int*)mlx_get_data_addr(mlx.image_ptr, &(mlx.bpp),\
		&(mlx.size_line), &(mlx.end));
		mlx_hook(mlx.win_ptr, 2, 5, key_hook, &mlx);
		mlx_hook(mlx.win_ptr, 6, 1L << 6, mouse_hook, &mlx);
		mlx_hook(mlx.win_ptr, 17, 1L << 17, icon_close, &mlx);
		mlx_loop_hook(mlx.mlx_ptr, draw_it_for_me, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		write(1, ERROR_MSG, ft_strlen(ERROR_MSG));
	return (0);
}
*/

