#include "header.h"
 
void colision_checks(Rectangle col1,Rectangle col2,Rectangle o1, Rectangle o2, float array []){
    
    if (CheckCollisionRecs(col1,col2)){
            //col_wall = array_wall[i];
            const Vector2 center1 = { o1.x + o1.width / 2, o1.y + o1.height / 2 };
            const Vector2 center2 = { o2.x + o2.width / 2, o2.y + o2.height / 2 };
 
            // Calculation of the distance vector between the centers of the rectangles
            const Vector2 delta = Vector2Subtract(center1, center2);
 
            // Calculation of half-widths and half-heights of rectangles
            const Vector2 hs1 = { o1.x*.5f, o1.x*.5f };
            const Vector2 hs2 = { o2.width*.5f, o2.height*.5f };
 
            // Calculation of the minimum distance at which the two rectangles can be separated
            const float minDistX = hs1.x + hs2.x - fabsf(delta.x);
            const float minDistY = hs1.y + hs2.y - fabsf(delta.y);

            array[0] = minDistX;
            array[1] = minDistY;
            array[2] = delta.x;
            array[3] = delta.y;
            
            // Adjusted object position based on minimum distance
            if (minDistX < minDistY) {
                o1.x += copysignf(minDistX, delta.x);
            } else {
                o1.y += copysignf(minDistY, delta.y);
            }
        }
    return;

}