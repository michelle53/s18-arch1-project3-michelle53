#include "shape.h"
#include "_abPacman.h"

// true if pixel is in pacman centered at centerPos
int abPacmanCheck(const AbPacman *pacman, const Vec2 *centerPos, const Vec2 *pixel){
  u_char radius = pacman->radius;
  int axis;
  Vec2 relPos;
  vec2Sub(&relPos, pixel, centerPos); /* vector from center to pixel */
  vec2Abs(&relPos);		      /* project to first quadrant */
  return (relPos.axes[0] <= radius && pacman->chords[relPos.axes[0]] >= relPos.axes[1]);
}
  
void abPacmanGetBounds(const AbPacman *pacman, const Vec2 *centerPos, Region *bounds){
  u_char axis, radius = pacman->radius;
  for (axis = 0; axis < 2; axis ++) {
    bounds->topLeft.axes[axis] = centerPos->axes[axis] - radius;
    bounds->botRight.axes[axis] = centerPos->axes[axis] + radius;
  }
  regionClipScreen(bounds);
}

  
int abSlicedPacmanCheck(const AbPacman *pacman, const Vec2 *centerPos, const Vec2 *pixel){
  Vec2 relPos;
  vec2Sub(&relPos, pixel, centerPos); /* vector from center to pixel */

  /* reject pixels in slice */
  if (relPos.axes[0] >= 0 && relPos.axes[0]/2 < relPos.axes[1]) 
    return 0;
  else
    return abPacmanCheck(pacman, centerPos, pixel);

}



